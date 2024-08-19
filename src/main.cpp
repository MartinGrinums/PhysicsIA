#define SERIESRESISTOR 220
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
  sd_card.initSD();
  sd_card.createFile(); 
  for(int i = 0; i<5; i++) {
  //read and convert thermistor readings to resistance in ohms
  float therm1Reading;
  therm1Reading = analogRead(THERM1);
  therm1Reading = (1023/therm1Reading) - 1;
  therm1Reading = SERIESRESISTOR / therm1Reading;
  Serial.println("Thermistor 1 reading: " + String(therm1Reading));
  float therm2Reading;
  therm2Reading = analogRead(THERM2);
  therm2Reading = 220 / (1024.0 /((float)analogRead(THERM2)) - 1.0);
  Serial.println("Thermistor 2 reading: " + String(therm2Reading));
   float therm3Reading;
   therm3Reading = analogRead(THERM3);
   therm3Reading = (1023/therm3Reading) - 1;
   therm3Reading = SERIESRESISTOR / therm3Reading;
   Serial.println("Thermistor 3 reading: " + String(therm3Reading));
  //print to console and to the file on the sd card
  sd_card.writeInFile("data.csv", therm1Reading, therm2Reading, therm3Reading);
  delay(1000);
  }
}

void loop()
{

}