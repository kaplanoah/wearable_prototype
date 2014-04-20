int pulseRate[10] = {125, 126, 127, 128, 129, 128, 131, 138, 132, 127};

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);  
}
 
void writeValues() {

  for(int i = 0; i<10; i++) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
  }

  Serial.println("pulseRate");
  for(int i = 0; i < (sizeof(pulseRate) / sizeof(pulseRate[0])); i++) {
   Serial.println(pulseRate[i]);
  }
  Serial.println("end");

  digitalWrite(13, HIGH);
}

void got_char(char x) {
 
  if (x == 'b') {
    writeValues();
  }
}

void loop() {

  if (Serial.available() > 0) {
    byte byte_read = Serial.read();
    got_char((char)byte_read);
  }

  delay(100);
}
