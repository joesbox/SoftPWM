/*
|| @author         Brett Hagman <bhagman@wiring.org.co>
|| @url            http://wiring.org.co/
|| @url            http://roguerobotics.com/
||
|| @description
|| | A Software PWM Library
|| |
|| | Written by Brett Hagman
|| | http://www.roguerobotics.com/
|| | bhagman@roguerobotics.com, bhagman@wiring.org.co
|| |
|| | A Wiring (and Arduino) Library, for Atmel AVR8 bit series microcontrollers,
|| | to produce PWM signals on any arbitrary pin.
|| |
|| | It was originally designed for controlling the brightness of LEDs, but
|| | could be adapted to control servos and other low frequency PWM controlled
|| | devices as well.
|| |
|| | It uses a single hardware timer (Timer 2) on the Atmel microcontroller to
|| | generate up to 20 PWM channels (your mileage may vary).
|| |
|| #
||
|| @license Please see the accompanying LICENSE.txt file for this project.
||
|| @name Software PWM Library
|| @type Library
|| @target Atmel AVR 8 Bit
||
|| @version 1.0.0
||
*/

#ifndef SOFTPWM_H
#define SOFTPWM_H

#define SOFTPWM_VERSION 10000

#include <stdint.h>
#include <ADC.h>

#define SOFTPWM_MAXCHANNELS 20
#define SOFTPWM_PWMDEFAULT 0x00

#define SOFTPWM_NORMAL 0
#define SOFTPWM_INVERTED 1

#define SOFTPWM_ANALOG 10 // Number of 'periods' between analog readings. 10 = 50ms perdiod @ 200Hz. 10S/s.
#define SOFTPWM_ANALOG_SAMPLES 10 // Number of samples to keep

#define ALL -1

/// @brief Begin SoftPWM
/// @param defaultPolarity Polarity
void SoftPWMBegin(uint8_t defaultPolarity = SOFTPWM_NORMAL);

/// @brief Set PWM value
/// @param pin Output pin
/// @param analogReadbackPin Analog pin used to read high-side driver current
/// @param analogReadbackDelay 8-Bit PWM value to reach before taking an analog reading (used to take account for Turn on delay of HSDs)
/// @param value 8-Bit PWM value
/// @param hardset Hard set (>1 = disable timer)
void SoftPWMSet(int8_t pin, int8_t analogReadbackPin, uint8_t analogReadbackDelay, uint8_t value, uint8_t hardset = 0);

/// @brief Set PWM percentage value
/// @param pin Output pin
/// @param analogReadbackPin Analog pin used to read high-side driver current
/// @param analogReadbackDelay  Percentage PWM value to reach before taking an analog reading (used to take account for Turn on delay of HSDs)
/// @param percent Percentage PWM value
/// @param hardset Hard set (>1 = disable timer)
void SoftPWMSetPercent(int8_t pin, int8_t analogReadbackPin, uint8_t analogReadbackDelay, uint8_t percent, uint8_t hardset = 0);

/// @brief End PWM control
/// @param pin Output pin
void SoftPWMEnd(int8_t pin);

/// @brief Set fade time
/// @param pin Output pin
/// @param fadeUpTime Fade up time
/// @param fadeDownTime Fade down time
void SoftPWMSetFadeTime(int8_t pin, uint16_t fadeUpTime, uint16_t fadeDownTime);

/// @brief Set PWM polarity
/// @param pin Output pin
/// @param polarity Active high or active low
void SoftPWMSetPolarity(int8_t pin, uint8_t polarity);

/// @brief Return the raw analog value for the given control pin
/// @param pin Control pin
/// @return Mean analog raw value
int SoftPWMGetAnalog(uint8_t pin);

#endif

