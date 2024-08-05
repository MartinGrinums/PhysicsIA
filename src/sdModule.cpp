#include <sdModule.h>

int SD_CARD::initSD(){
    Serial.begin(9600);
    if(!SD.begin(10)){
        Serial.println("Failed to initialise SD Module");
    }
    else{
        Serial.println("SD Module initialised"); 
        
    }
    int rander = random(500);
    delay(rander);
    int time = millis();
    Serial.println(time);
    return time;
}

String SD_CARD::createFile(int time){
    File myFile;
    //Serial.println(filename);
    myFile = SD.open("data.txt", FILE_WRITE);
    myFile.close();
    if(SD.exists("data.txt")){
        Serial.println("File created");
    }
    else{
        Serial.println("File creation failed");
    }
    return "data.txt";
}

void SD_CARD::writeInFile(String filename, double temp){
    File myFile;
    myFile = SD.open(filename, FILE_WRITE);
    Serial.println("Writing to file");
    String data = String(temp);
    Serial.println(data);
    myFile.println(data);
    myFile.close();
}