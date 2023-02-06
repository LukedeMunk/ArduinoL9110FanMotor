/*
 * File:      example.ino
 * Author:    Luke de Munk
 * Version:   1.0
 * 
 * Example for L9110FanMotor library for ardiuno. For functions and parameters, check ArduinoL9110FanMotor.cpp
 * For more info checkout: https://github.com/LukedeMunk/ArduinoL9110FanMotor
 */
#include "ArduinoL9110FanMotor.h"

/* Pins */
#define INA   3     //Must support PWM
#define INB   5     //Must support PWM

L9110FanMotor fan(INA, INB);

 /**************************************************************************/
/*!
  @brief    Setup microchip.
*/
/**************************************************************************/
void setup() {

}

/**************************************************************************/
/*!
  @brief    Mainloop.
*/
/**************************************************************************/
void loop() {
  fan.clockwise(50);
  delay(10000);
  fan.stop();
  delay(1000);
  fan.counterClockwise(60);
  delay(10000);
}
