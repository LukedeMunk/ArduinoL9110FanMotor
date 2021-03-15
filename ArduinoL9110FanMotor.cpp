/*
   File:      ArduinoL9110FanMotor.ccp
   Authors:   Luke de Munk
   Class:     L9110FanMotor
   Version:   1.0

   Library for controlling fan with L9110 driver.
*/
#include "ArduinoL9110FanMotor.h"

#define MIN_TURN_SPEED    20                                                //Below this value, fan doesn't turn because of friction
#define MIN_START_SPEED   60                                                //Below this value, fan doesn't start because of friction, for start function
#define MAX_SPEED         255
#define STARTUP_SPEED     200                                               //For start function

/**************************************************************************/
/*!
  @brief    Initialise the L9110 driven fan.
  @param    INAPin          Pin for Input A (must support PWM)
  @param    INBPin          Pin for Input B (must support PWM)
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
  uint8_t calcSpeed = _calculateSpeed(speed);                               //Convert percentage to actual speed

  /* If below start speed, start with higher speed to avoid getting stuck */
  if (calcSpeed < MIN_START_SPEED) {
    analogWrite(_INAPin, STARTUP_SPEED);
    digitalWrite(_INBPin, 0);
    delay(20);
  }

  /* Output given speed */
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
  uint8_t calcSpeed = _calculateSpeed(speed);                               //Convert percentage to actual speed

  /* If below start speed, start with higher speed to avoid getting stuck */
  if (calcSpeed < MIN_START_SPEED) {
    digitalWrite(_INAPin, 0);
    analogWrite(_INBPin, STARTUP_SPEED);
    delay(20);
  }

  /* Output given speed */
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

/**************************************************************************/
/*!
  @brief    Converts speed in percentage to needed value.
  @param    speed           Speed of movement (0-100)
  @returns  speed           Speed in value 0-255
*/
/**************************************************************************/
uint8_t L9110FanMotor::_calculateSpeed(uint8_t speed) {
  /* Speed needs to be between 0 and 100 percent */
  if (speed > 100)
    speed = 100;
  
  speed = (speed * MAX_SPEED)/100;
  
  /* If speed is below minimum turn speed, return minimum output */
  if (speed > 0 && speed < MIN_TURN_SPEED)
    return MIN_TURN_SPEED;

  return speed;
}