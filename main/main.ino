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


void loop() {
  for (int i = 0; i < bus_width; ++i) {
    digitalWrite(data[i], HIGH);
    delay(delay_ms);
  }

  for (int i = 0; i < bus_width; ++i) {
    digitalWrite(data[i], LOW);
    delay(delay_ms);
  }
}
