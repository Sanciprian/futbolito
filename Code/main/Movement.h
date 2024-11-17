#ifndef Movement_h
#define Movement_h

// External Files // 
#include "Constants.h"
#include <Stepper.h>

// Class //
class Movement{
  private:
    volatile uint8_t speed;
    Stepper* stepper;

  public: 
    // Constructor //
    Movement(uint8_t speed);
    
    // Setup // 
    void beginMovement();

    // Setters // 
    void setSpeed(int _speed);

    // Methods // 
    void left();
    void right();
    void shoot();
    void defaultPos();
};
#endif