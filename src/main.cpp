#define SERIESRESISTOR 220
#define TMP36 A4
#define THERM1 A0
#define THERM2 A1
#define THERM3 A2
#include <Arduino.h>
#include <sdModule.h>
SD_CARD sd_card;
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  int time = sd_card.initSD();
  String name = sd_card.createFile(50); 
 // for(int i = 0; i<100; i++){
 
 // i++;
  //}
}

void loop()
{
  //create a card on the sd card
  digitalWrite(LED_BUILTIN, HIGH); // read and convert the TMP36 readings to temperature in degrees celsius
  float tempReading;
  tempReading = analogRead(TMP36);
  float voltage = tempReading * 5.0;
  voltage /= 1024.0;
  float tempC = ((voltage - 0.5) * 100);

  //read and convert thermistor readings to resistance in ohms
  float therm1Reading;
  therm1Reading = analogRead(THERM1);
  //Serial.println("Analog reading 1: " + String(therm1Reading));
  therm1Reading = (1023/therm1Reading) - 1;
  therm1Reading = SERIESRESISTOR / therm1Reading;
  Serial.println("Thermistor 1 reading: " + String(therm1Reading));
  float therm2Reading;
  therm2Reading = analogRead(THERM2);
  //Serial.println("Analog reading 1: " + String(therm1Reading));
  therm2Reading = 220 / (1024.0 /((float)analogRead(THERM2)) - 1.0);
  Serial.println("Thermistor 2 reading: " + String(therm2Reading));
   float therm3Reading;
   therm3Reading = analogRead(THERM3);
   //Serial.println("Analog reading 1: " + String(therm1Reading));
   therm3Reading = (1023/therm3Reading) - 1;
   therm3Reading = SERIESRESISTOR / therm3Reading;
   Serial.println("Thermistor 3 reading: " + String(therm3Reading));
  //print to console and to the file on the sd card
  Serial.println("Temperature: " + String(tempC));
  sd_card.writeInFile("data.csv", tempC, therm1Reading, therm2Reading, therm3Reading);
  delay(200);
}