#include "Arduino.h"
#include "Encoder.h"

long Encoder::step;
int Encoder::firstChannel;
int Encoder::secondChannel;

Encoder::Encoder(int firstChannel, int secondChannel) {
  pinMode(firstChannel, INPUT);
  this->firstChannel = firstChannel;

  pinMode(secondChannel, INPUT);
  this->secondChannel = secondChannel;

  attachInterrupt(digitalPinToInterrupt(firstChannel), Encoder::readFirstChannel, CHANGE);
  attachInterrupt(digitalPinToInterrupt(secondChannel), Encoder::readSecondChannel, CHANGE);
}

void Encoder::readFirstChannel() {
  if (digitalRead(Encoder::firstChannel) == HIGH) {
    if (digitalRead(Encoder::secondChannel) == LOW) {
      Encoder::step++;
    } else {
      Encoder::step--;
    }
  } else {
    if (digitalRead(Encoder::secondChannel) == LOW) {
      Encoder::step--;
    } else {
      Encoder::step++;
    }
  }
}

void Encoder::readSecondChannel() {
  if (digitalRead(Encoder::secondChannel) == HIGH) {
    if (digitalRead(Encoder::firstChannel) == HIGH) {
      Encoder::step++;
    } else {
      Encoder::step--;
    }
  } else {
    if (digitalRead(Encoder::firstChannel) == LOW) {
      Encoder::step++;
    } else {
      Encoder::step--;
    }
  }
}

void Encoder::readEncoder() {
  readFirstChannel();
  readSecondChannel();
}

long Encoder::getStep() {
  return this->step;
}
