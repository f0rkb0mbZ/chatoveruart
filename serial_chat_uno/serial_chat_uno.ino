#include <SoftwareSerial.h>

SoftwareSerial SerialV(10,11); //RX, TX

String text;

void setup()
{
  Serial.begin(9600); // init serial0 TX0, RX0
  SerialV.begin(9600); // init serial1 TXvirtual, RXvirtual
  delay(1000); // stabilize the serial port
}

void loop()
{
  // read from port virtual, send to port 0
  if (SerialV.available()){
    Serial.write("Mega: ");
    Serial.print(SerialV.readString());
  }

  // read from port 0, send to port virtual
  if(Serial.available())
  {
    Serial.print("Uno: ");
    while(Serial.available())
    {
      text = Serial.readString();
      SerialV.print(text);
      Serial.print(text);
    }
    SerialV.println();
    Serial.println();
  }
}
