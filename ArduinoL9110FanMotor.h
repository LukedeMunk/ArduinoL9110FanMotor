/*
 * File:      ArduinoL9110FanMotor.h
 * Authors:   Luke de Munk
 * Class:     L9110FanMotor
 * Version:   1.0
 * 
 * Library for controlling fan with L9110 driver.
 */
#ifndef L9110FanMotor_H
#define L9110FanMotor_H
#include <stdint.h>
#include "Arduino.h"

class L9110FanMotor
{
  public:
    L9110FanMotor(uint8_t INAPin, uint8_t INBPin);

    void clockwise(uint8_t speed);
    void counterClockwise(uint8_t speed);
    void stop();

  private:
    uint8_t _calculateSpeed(uint8_t speed);
    uint8_t _INAPin;
    uint8_t _INBPin;
};
#endif
