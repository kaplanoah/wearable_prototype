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

      pulseValues = []

    rescue
      pulseValues = ["no values received. please make sure device is plugged in. (port: #{port_file})"]
    end

    respond_to do |f|
      f.json { render :json=> pulseValues }
    end
  end

end
