/*
   File:      ArduinoL9110FanMotor.ccp
   Authors:   Luke de Munk
   Class:     L9110FanMotor
   Version:   1.0

   Library for controlling fan with L9110 driver.
*/
#include "ArduinoL9110FanMotor.h"

#define MIN_TURN_SPEED    20
#define MIN_START_SPEED   60
#define MAX_SPEED         255
#define STARTUP_SPEED     200

/**************************************************************************/
/*!
  @brief    Initialise the L9110 driven fan.
  @param    INAPin          Pin for A (uses PWM)
  @param    INBPin          Pin for B (uses PWM)
*/
/**************************************************************************/
L9110FanMotor::L9110FanMotor(uint8_t INAPin, uint8_t INBPin) {
  _INAPin = INAPin;
  _INBPin = INBPin;

  pinMode(_INAPin, OUTPUT);
  pinMode(_INBPin, OUTPUT);

  digitalWrite(_INAPin, 0);
  digitalWrite(_INBPin, 0);
}

/**************************************************************************/
/*!
  @brief    Turn clockwise.
  @param    speed           Speed of movement (0-100)
*/
/**************************************************************************/
void L9110FanMotor::clockwise(uint8_t speed) {
  uint8_t calcSpeed = _calculateSpeed(speed);
  if (calcSpeed < MIN_START_SPEED) {
    analogWrite(_INAPin, STARTUP_SPEED);
    digitalWrite(_INBPin, 0);
    delay(20);
  }
  analogWrite(_INAPin, calcSpeed);
  digitalWrite(_INBPin, 0);
}

/**************************************************************************/
/*!
  @brief    Turn counter clockwise.
  @param    speed           Speed of movement (0-100)
*/
/**************************************************************************/
void L9110FanMotor::counterClockwise(uint8_t speed) {
  uint8_t calcSpeed = _calculateSpeed(speed);
  if (calcSpeed < MIN_START_SPEED) {
    digitalWrite(_INAPin, 0);
    analogWrite(_INBPin, STARTUP_SPEED);
    delay(20);
  }
  digitalWrite(_INAPin, 0);
  analogWrite(_INBPin, calcSpeed);
}

/**************************************************************************/
/*!
  @brief    Stop fan.
*/
/**************************************************************************/
void L9110FanMotor::stop(){
  digitalWrite(_INAPin, 0);
  analogWrite(_INBPin, 0);
}