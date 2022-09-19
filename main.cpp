#include <Arduino.h>

/*
"StAuth10184: I Jesse Em, 000295218 certify that this material is my original work. 
No other person's work has been used without due acknowledgement. 
I have not made my work available to anyone else."

*/

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop() {
  int iVal;
  float v;
  float temp; 

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);

  v = iVal * (3.3 / 1023.0);
  temp = iVal * (50.0 / 1023.0);

  // tried map, did not work
  // c = map(iVal, 0.0, 1023, 0.0, 3.4);
  // float j = (float) c;

  String weather = "";
  
  if (temp < 10 ) {
    weather = "Cold!";
  } else if (temp > 10 && temp <= 15) {
    weather = "Cool";
  } else if (temp > 15 && temp <= 25) {
    weather = "Perfect";
  } else if (temp > 25 && temp <= 30) {
    weather = "Warm";
  } else if (temp > 30 && temp <= 35) {
    weather = "Hot";
  } else if (temp > 35) {
    weather = "Too Hot!";
  } 

  // print value to the USB port
  //Serial.println("Digitized Value of " + String(iVal) + " is equivalent to an Analog Voltage of = " + String(v) + "V");
  // wait 0.5 seconds (500 ms)
  //delay(500);

  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to an temperature of of = " + String(temp) + " deg. C, which is " + weather);
  // wait 0.5 seconds (2000 ms)
  delay(2000);
}