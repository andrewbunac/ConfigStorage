#ifndef ConfigStorage_h
#define ConfigStorage_h


//====================== ARDUINO LIBRARIES (ESP32 Compatible Libraries) ============================//
// You will have to download and install the following libraries below in order to program the      //
// Reverse Vendo Machine (RVM)                                                                      //
//============================================================================================= ====//
#include <Arduino.h>                //SYSTEM PARAMETER  - WiFi Library (By: Arduino)
#include <Preferences.h>            //SYSTEM PARAMETER  - WiFi Library (By: Arduino)
#include <FS.h>                     //SYSTEM PARAMETER  - WiFi Library (By: Arduino)
#include <SPIFFS.h>                 //SYSTEM PARAMETER  - WiFi Library (By: Arduino)

class ConfigStorage {
public:
  ConfigStorage();
  void begin();
  void setConfig(const char* key, const char* value);
  String getConfig(const char* key);

private:
  Preferences preferences;
  bool initialized = false;
  const char* FILE_PATH = "/config.txt";
};

#endif