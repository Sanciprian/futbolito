#ifndef Movement_h
#define Movement_h

// External Files //
#include "Constants.h"
#include <TMCStepper.h>

// Class //
class Movement
{
private:
  // Other variables //
  volatile uint8_t _speed; // 0-100%
  volatile uint8_t _minSpeed;
  volatile uint8_t _maxSpeed;
  unsigned long _lastTime;
  volatile bool _moveFlag;
  volatile bool _state; // False = turn of   True = turn on
  const uint8_t _variation;

  // PINS //
  const uint8_t _dir;
  const uint8_t _step;
  const uint8_t _enable;

  // TMC2208 Object //
  uint8_t _address;
  HardwareSerial &_serial;
  TMC2208Stepper *_driver;

public:
  // Constructor //
  Movement(uint8_t speed, uint8_t dirPin, uint8_t stepPin, uint8_t enablePin, HardwareSerial &port, uint8_t address);

  // Setup //
  void BeginMovement();

  // Setters //
  void SetSpeed(int speed);
  void SetLeft();
  void SetRight();
  void SetDriverState(bool state);

  // Methods //
  void DefaultPos();
  void Move(unsigned long currentTime); // This is going to be feed to the loop
  void IncreaseSpeed();
  void DecreaseSpeed();
};

#endif