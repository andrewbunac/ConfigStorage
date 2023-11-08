#include "ConfigStorage.h"

ConfigStorage::ConfigStorage() {}

void ConfigStorage::begin() {
  if (!initialized) {
    if (SPIFFS.begin(true)) {
      initialized = true;
    } else {
      Serial.println("Failed to mount SPIFFS");
    }
  }
}

void ConfigStorage::setConfig(const char* key, const char* value) {
  if (initialized) {
    preferences.begin("config", false);
    preferences.putString(key, value);
    preferences.end();
  } else {
    File configFile = SPIFFS.open(FILE_PATH, "w");
    if (configFile) {
      configFile.println(String(key) + "=" + value);
      configFile.close();
    } else {
      Serial.println("Failed to open config file for writing");
    }
  }
}

String ConfigStorage::getConfig(const char* key) {
  if (initialized) {
    preferences.begin("config", true);
    String value = preferences.getString(key, "");
    preferences.end();
    return value;
  } else {
    File configFile = SPIFFS.open(FILE_PATH, "r");
    if (configFile) {
      while (configFile.available()) {
        String line = configFile.readStringUntil('\n');
        int equalsIndex = line.indexOf('=');
        if (equalsIndex != -1) {
          String storedKey = line.substring(0, equalsIndex);
          String storedValue = line.substring(equalsIndex + 1);
          if (storedKey == key) {
            configFile.close();
            return storedValue;
          }
        }
      }
      configFile.close();
    } else {
      Serial.println("Failed to open config file for reading");
    }
    return "";
  }
}
