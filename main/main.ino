/* Copyright (c) 2024 Francis Guindon */

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

char ssid[] = "El Arado";
char pass[] = "ElArado1507";

int status = WL_IDLE_STATUS;
WiFiClient  client;

int sensorValue;

unsigned long myChannelNumber = 2483973;
const char * myWriteAPIKey = "TMZANOXDNZ2QNZFP";

void setup() {
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
}

void loop() {
  sensorValue = analogRead(A0);

  ThingSpeak.writeField(myChannelNumber, 1, sensorValue, myWriteAPIKey);
  delay(5000);
}
