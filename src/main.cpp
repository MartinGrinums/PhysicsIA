// // SPDX-FileCopyrightText: 2011 Limor Fried/ladyada for Adafruit Industries
// //
// // SPDX-License-Identifier: MIT

// // thermistor-1.ino Simple test program for a thermistor for Adafruit Learning System
// // https://learn.adafruit.com/thermistor/using-a-thermistor by Limor Fried, Adafruit Industries
// // MIT License - please keep attribution and consider buying parts from Adafruit

// // the value of the 'other' resistor
// #define SERIESRESISTOR 100
// #define TMP36 A4
// #include <Arduino.h>
// // What pin to connect the sensor to
// #define THERMISTORPIN A0

// void setup(void) {
//   Serial.begin(9600);
// }

// void loop(void) {
//   float reading;
//   float tempReading;
//   reading = analogRead(THERMISTORPIN);
//   tempReading = analogRead(TMP36);
//   //Serial.print("Analog reading ");
//   //Serial.println(reading);

//   float voltage = tempReading * 5.0;
//   voltage /= 1024.0;
//   Serial.print("Voltage: ");
//   Serial.println(voltage);
//   float tempC = (voltage -0.5)*100;
//   Serial.print("Temperature ");
//   Serial.println(tempC);

//   // convert the value to resistance
//   reading = (1023 / reading)  - 1;     // (1023/ADC - 1)
//   reading = SERIESRESISTOR / reading;  // 10K / (1023/ADC - 1)
//   Serial.print("Thermistor resistance ");
//   Serial.println(reading);

//   delay(1000);
// }

#define SERIESRESISTOR 100
#define TMP36 A4
#include <Arduino.h>
#include <sdModule.h>
SD_CARD sd_card;
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  int time = sd_card.initSD();
}

void loop()
{
  String name = sd_card.createFile(50);
  float tempReading;
  tempReading = analogRead(TMP36);
  float voltage = tempReading * 5.0;
  voltage /= 1024.0;
  float tempC = ((voltage - 0.5) * 100);
  Serial.println("Temperature: " + String(tempC));
  sd_card.writeInFile(name, tempC);
  delay(1000);
}