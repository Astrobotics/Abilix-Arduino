#include <SoftwareSerial.h>
char data = 0;
SoftwareSerial mySerial(2, 3); // TX, RX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}
void loop() {
  Bluetooth();
}

void Bluetooth() {
  if (mySerial.available() > 0)
  {
    data = mySerial.read();
    Serial.print(data);
    Serial.print("\n");
    if (data == 'I')
    {
      digitalWrite(4, HIGH);
    }
    else if (data == 'J')
    {
      digitalWrite(5, HIGH);
    }
    else if (data == 'K')
    {
      digitalWrite(6, HIGH);
    }
    else if (data == 'L')
    {
      digitalWrite(7, HIGH);
    }
    else if (data == 'S')
    {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
  }
}
