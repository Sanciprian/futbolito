/*
  Documentation of how buttons are going to be determine with the schematics. 
  
*/

#ifndef Control_h
#define Control_h

// External Files // 
#include "Constants.h"

// Class //
class Control{
  private: 
    // data // 
    const uint8_t pinA = Constants::input_a; 
    const uint8_t pinB = Constants::input_b; 
  public:

    // Constructor // 
    Control(); 
    
    // Setup //
    void beginControl();

    // Getters // 
    states getInput();

    // Setters // 

    // Methods // 
    
};
#endif