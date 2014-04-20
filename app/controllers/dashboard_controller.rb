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

      port.write "b"

      values_string = ""
      port_line = ""
      i = 1

      until port_line.include? "end"
        port_line = port.readline(i)
        values_string += port_line
        i += 1
      end

      values_array = values_string.split("\r\n")
    rescue
      values_array = ["no values received. please make sure device is plugged in."]
    end

    respond_to do |f|
      f.json { render :json=> values_array }
    end
  end

end
