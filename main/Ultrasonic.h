#ifndef Ultrasonic_h
#define Ultrasonic_h

// External Files //
#include "Constants.h"
#include "LiquidCrystal_I2C.h"

class Ultrasonic
{
private:
  // data //
  const uint8_t _trigger;
  const uint8_t _echo;
  volatile uint8_t _goals;
  volatile long _duration;
  volatile long _distance;

  LiquidCrystal_I2C *_lcd;

public:
  // Constructor //
  Ultrasonic();
  // Setup //
  void BeginUltrasonic();

  // Getters //
  int GetDistance();
  int GetGoals();

  // Setters //
  void SetDistance();
  // Methods //
  bool Score();
  void PrintScore();
};
#endif