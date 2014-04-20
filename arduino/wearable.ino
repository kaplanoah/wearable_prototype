/*

Code for display learned from Saurabh Palan at iRoboticist Workshop
workshop.iRoboticist.com
twitter.com/iRoboticist


Code for reading pulse sensor adapted from code for Pulse Sensor Amped by Joel Murphy and Yury Gitman
code.google.com/p/pulse-sensor/downloads/list
www.pulsesensor.com 
    
*/


/* DELETE THIS LATER */
int pulseRate[20] = {125, 126, 127, 128, 129, 128, 131, 138, 132, 127};


#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>
#include <Time.h>

Adafruit_SharpMem display(SCK, MOSI, SS);

#define BLACK 0
#define WHITE 1

int pulsePin = 0; // purple wire to A0
int fadeRate = 0; // for PWM on pin 11

// volatile for interrupt
volatile int BPM;                 // pulse rate
volatile int Signal;              // incoming raw data
volatile int HRV;                 // time between beats
volatile boolean Pulse = false;   // true when pulse wave is high, false when low
volatile boolean QS = false;      // becomes true when pulse rate is determined (every 20 pulses)

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  display.begin();
  display.clearDisplay();

  interruptSetup(); // read Pulse Sensor signal every 1mS  
}

void loop(){
  
  if (Serial.available() > 0) {
    byte byte_read = Serial.read();
    got_char((char)byte_read);
  }
  
  if (QS == true){
    display.clearDisplay();    
    display.setTextColor(BLACK);
    display.setCursor(20,5);
    display.setTextSize(3);
    display.print(BPM);
    display.setTextSize(1);
    display.println(" bpm");
    display.refresh();
    QS = false;    
  }
  
  delay(20);
}

void got_char(char x) {
  if (x == 'v') {
    writeValues();
  }
}

void writeValues() {
  
  digitalWrite(13, HIGH);

  Serial.println("pulseRate");
  for(int i = 0; i < (sizeof(pulseRate) / sizeof(pulseRate[0])); i++) {
   Serial.println(pulseRate[i]);
  }
  Serial.println("end");

  digitalWrite(13, LOW);
}
