#include <Arduino.h>

#define FIRST_CHANNEL D1
#define SECOND_CHANNEL D2

#include "Encoder.h"

Encoder firstEncoder(FIRST_CHANNEL, SECOND_CHANNEL);

void setup() {
  firstEncoder.readEncoder();
  Serial.begin(9600);
}

void loop() {
  Serial.println(firstEncoder.getStep());
  delay(100);
}
