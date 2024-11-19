#ifndef Solenoid_h
#define Solenoid_h

// External Files //
#include "Constants.h"

// Class //
class Solenoid
{
private:
  // data //
  const uint8_t _pin;
  const uint32_t _duration;
  const uint32_t _recoil;
  unsigned long _lastTime;
  volatile bool _phase;

public:
  // Constructor //
  Solenoid();
  // Setup //
  void BeginSolenoid();
  // Getters //
  // Setters //
  // Methods //
  void Shoot(unsigned long currentTime);
  void State(unsigned long currentTime);
};
#endif