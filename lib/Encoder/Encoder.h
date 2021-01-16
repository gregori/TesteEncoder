/*
 * File: Encoder.h
 * Author: pedropaulovtz
 * 
 * Created on January 12, 2020
 */

#ifndef ENCODER_H /* Entender pra que serve */
#define ENCODER_H /* Entender pra que serve */

#include "Arduino.h"

class Encoder {
  public:
    Encoder(int firstChannel, int secondChannel);
    long getStep();
    void readEncoder();

  private:
    static void readFirstChannel();
    static void readSecondChannel();

    static long step;
    static int firstChannel;
    static int secondChannel;
};  

#endif /* Entender pra que serve */
