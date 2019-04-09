String text;
void setup() {
  Serial.begin(9600); // init serial0 TX0, RX0
  Serial1.begin(9600); // init serial1 TX1, RX1
  delay(1000);
}

void loop() {
  // read from port 1, send to port 0
  if(Serial1.available()){
    Serial.write("Uno: ");
    Serial.print(Serial1.readString());
  }
    
  // read from port 0, send to port 1
  if(Serial.available()) 
  {
    Serial.print("Mega: ");
    while(Serial.available())
    {
      text = Serial.readString();
      Serial1.print(text);
      Serial.print(text);
    }
//    Serial.println("got out of loop");
    Serial1.println();
    Serial.println();
  }
}
