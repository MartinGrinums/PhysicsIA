#pragma once
#include <Arduino.h>
#include <SD.h>
class SD_CARD {
    private:
    
    public:
    

    String createFile(int time);
    void writeInFile(String filename, double temp1, double therm1, double therm2, double therm3);
    int initSD();
};