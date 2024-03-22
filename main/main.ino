// #include <SoftwareSerial.h>

// #include <ArduinoWiFiServer.h>
// #include <BearSSLHelpers.h>
// #include <CertStoreBearSSL.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266WiFiAP.h>
// #include <ESP8266WiFiGeneric.h>
// #include <ESP8266WiFiGratuitous.h>
// #include <ESP8266WiFiMulti.h>
// #include <ESP8266WiFiSTA.h>
// #include <ESP8266WiFiScan.h>
// #include <ESP8266WiFiType.h>
// #include <WiFiClient.h>
// #include <WiFiClientSecure.h>
// #include <WiFiClientSecureBearSSL.h>
// #include <WiFiServer.h>
// #include <WiFiServerSecure.h>
// #include <WiFiServerSecureBearSSL.h>
// #include <WiFiUdp.h>

// #include <ESP8266AVRISP.h>
// #include <command.h>

// #include <dummy.h>

/* Copyright (c) 2024 Francis Guindon */

int delay_ms = 500;
int bus_width;
int data[] = {D0, D1, D2, D3, D4, D5, D6, D7, D8};

void setup() {
  Serial.begin(9600);
  bus_width = sizeof(data)/sizeof(data[0]);
  
  for (int i = 0; i < bus_width; ++i) {
    pinMode(data[i], OUTPUT);
  }
}

void set_boometer_value(int value) {
  for (int i = 0; i < value; ++i) {
    digitalWrite(data[i], HIGH);
  }

  for (int i = value; i < 8; ++i) {
    digitalWrite(data[i], LOW);
  }
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);

  set_boometer_value(sensorValue >> 7);

  // for (int i = 0; i < 8; ++i) {
  //   digitalWrite(data[i], HIGH);
  //   delay(delay_ms);
  // }

  // for (int i = 0; i < 8; ++i) {
  //   digitalWrite(data[7-i], LOW);
  //   delay(delay_ms);
  // }
}
