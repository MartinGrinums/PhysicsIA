#include <sdModule.h>

void SD_CARD::initSD(){
    Serial.begin(9600);
    if(!SD.begin(10)){
        Serial.println("Failed to initialise SD Module");
    }
    else{
        Serial.println("SD Module initialised"); 
    }
}

void SD_CARD::createFile(){
    File myFile;
    myFile = SD.open("data.csv", FILE_WRITE);
    myFile.close();
    if(SD.exists("data.csv")){
        Serial.println("File created");
    }
    else{
        Serial.println("File creation failed");
    }
}

void SD_CARD::writeInFile(String filename, double therm1, double therm2, double therm3){
    File myFile;
    myFile = SD.open(filename, FILE_WRITE);
    Serial.println("Writing to file");
    String data = String(therm1)+ "," + String(therm2) + "," + String(therm3);
    Serial.println(data);
    myFile.println(data);
    myFile.close();
}