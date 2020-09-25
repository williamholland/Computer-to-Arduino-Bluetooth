#include "BluetoothSerial.h"

BluetoothSerial bluetooth;
int count = 0;


void setup()
{
  Serial.begin(9600);
  Serial.println("Serial ready");
  mySerial.begin("ESP32");
  mySerial.println("Bluetooth ready");
}

void loop()
{
  Serial.println(count)
  bluetooth.println(count)
  count++;
}
