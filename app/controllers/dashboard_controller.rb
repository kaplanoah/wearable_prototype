class DashboardController < ApplicationController

  def main
  end

  def import_values
    port_file = '/dev/tty.usbmodemfd121' 
    baud_rate = 9600
    data_bits = 8
    stop_bits = 1
    parity = SerialPort::NONE

    begin
      port = SerialPort.new(port_file, baud_rate, data_bits, stop_bits, parity)

      port.write "v"

      arduino_input_string = ""
      port_line = ""
      i = 1

      until port_line.include? "end"
        port_line = port.readline(i)
        arduino_input_string += port_line
        i += 1
      end

      arduino_input_array = arduino_input_string.split("\r\n")

      pulse_values = []

      pointer = arduino_input_array[-2].to_i

      (arduino_input_array.length - 4).times do
        pulse_values.push(arduino_input_array[pointer].to_i)
        pointer == 50 ? ( pointer = 1 ) : ( pointer += 1 )
      end

      average = pulse_values.inject{ |sum, el| sum + el }. / pulse_values.length
      max = pulse_values.max
      min = pulse_values.min

    rescue
      pulse_values = ["no values received. please make sure device is plugged in. (port: #{port_file})"]
    end

    respond_to do |f|
      f.json { render :json => { :values => pulse_values, :average => average, :max => max, :min => min } }
    end
  end

end
