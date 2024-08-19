#pragma once
#include <Arduino.h>
#include <SD.h>
class SD_CARD {
    private:
    
    public:
    

    void createFile();
    void writeInFile(String filename, double therm1, double therm2, double therm3);
    void initSD();
};