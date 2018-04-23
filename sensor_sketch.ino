
/*  ARDUINO CHEMICAL SENSOR - HARDWARE CODE
 *  By Jamie Rajewski
 */

#include <SoftwareSerial.h>

// ------------------------------------------------- //

const int INP_PIN = A0; // Analog pin connected to sensor

SoftwareSerial BluetoothSerial(10, 11); // RX | TX

// Voltage
const float VCC = 5.0;
String character; 
int delayAmt = 250;


void setup() {
  pinMode(INP_PIN, INPUT);
  BluetoothSerial.begin(38400); // Baud rate for BT transmissions
}

void loop() {

  // Get the time of the measurement (in seconds, to two decimal places)
  double current_time = double(millis()) / 1000.0;
  
  // Read input
  int adc = analogRead(INP_PIN); 

  // Use ADC reading to calculate voltage
  float volt = adc * VCC / 1023.0;

  // Send the delimited, formatted data to the Android app for processing
  BluetoothSerial.println("&"+String(volt)+"-"+String(current_time));

  delay(delayAmt);
}

