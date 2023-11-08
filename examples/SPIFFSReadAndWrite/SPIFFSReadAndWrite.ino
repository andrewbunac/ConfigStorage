
#include "ConfigStorage.h"
#include <SPI.h>

ConfigStorage configStorage;
void setup() {
  
  // Initialize Serial monitoriing
  Serial.begin(115200);
  
  // Initialize the configuration storage (NVS or SPIFFS)
  configStorage.begin();

  // uncomment below on first run to initialize saving,  and comment out on second run(second upload)
  // Store and retrieve values
  // configStorage.setConfig("TERMINAL_ID", "12345");
  // configStorage.setConfig("SSID", "WIFI_NAME");
  // configStorage.setConfig("SSID_PASSWORD", "WIFI_PASSWORD123");

  // Commen out on first run and uncomment on second run to test if data persist
  Serial.println("TERMINAL_ID: " + configStorage.getConfig("TERMINAL_ID"));
  Serial.println("SSID: " + configStorage.getConfig("SSID"));
  Serial.println("SSID_PASSWORD: " + configStorage.getConfig("SSID_PASSWORD"));
}

void loop() {
  // put your main code here, to run repeatedly:

}
