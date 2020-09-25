//Include the module so we don't
//have to use the default Serial
//so the Arduino can be plugged in
//to a computer and still use bluetooth
#include "BluetoothSerial.h"

//Variable to store input value
//initialized with arbitrary value
char k = 'A';
//Connect the Bluetooth module
BluetoothSerial bluetooth;

//Define the pin to control the light
int lightbulb = 2

void setup()
{
  //Set the lightbulb pin to put power out
  pinMode(lightbulb, OUTPUT);
  //Initialize Serial for debugging purposes
  Serial.begin(9600);
  Serial.println("Serial ready");
  //Initialize the bluetooth
  bluetooth.begin("ESP32");
  bluetooth.println("Bluetooth ready");
}

void loop()
{
  //Check for new data
  if(bluetooth.available()){
    //Remember new data
    k = bluetooth.read();
    //Print the data for debugging purposes
    Serial.println(k);
  }
  //Turn on the light if transmitted data is H
  if( k == 'H' ){
    digitalWrite(2, HIGH);
  }
  //Turn off the light if transmitted data is L
  else if( k == 'L') {
    digitalWrite(2, LOW);
  }
  //Wait ten milliseconds to decrease unnecessary hardware strain
   delay(10);
}
