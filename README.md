## Wearable prototype

A dashboard for a prototype of a wearable device built in the [iRoboticist Workshop](http://workshop.iroboticist.com/).

### Key files

- [arduino_port_read.ino](../../blob/master/arduino_port_read.ino) (C++ code for arduino, not part of rails app)
- app > controllers > [dashboard_controller.rb](../../blob/master/app/controllers/dashboard_controller.rb)
- app > assets > javascrips > [dashboard.js](../../blob/master/app/assets/javascripts/dashboard.js)
- app > views > dashboard > [main.html.erb](../../blob/master/app/views/dashboard/main.html.erb)

### To launch app

Locally: fork and clone app. From terminal, in app's directory, run:

    bundle install
    rails s

In web browser, visit:

    http://localhost:3000/

__NOTE:__ the app expects serial port input