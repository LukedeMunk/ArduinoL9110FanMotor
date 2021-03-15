/*
 * File:      example.ino
 * Author:    Luke de Munk
 * Version:   1.0
 * 
 * Example for L9110FanMotor library for ardiuno.
 * For more info checkout: https://github.com/LukedeMunk/ArduinoL9110FanMotor
 */
#include "ArduinoL9110FanMotor.h"

/* Pins */
#define INA   3     //Must support PWM
#define INB   4     //Must support PWM

L9110FanMotor fan(INA, INB);

 /**************************************************************************/
/*!
  @brief    Setup microchip.
*/
/**************************************************************************/
void setup() {
  fan.clockwise(10);
}

/**************************************************************************/
/*!
  @brief    Mainloop.
*/
/**************************************************************************/
void loop() {

}
