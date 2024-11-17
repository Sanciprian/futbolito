#ifndef Constants_h
#define Constants_h

// External Files //
#include <Arduino.h>

// State Machine Description //
enum states 
{
  Stop = 0,
  Left = 1,
  Right = 2,
  Shoot = 3
};

// Constants Values Throughtout The Code // 
class Constants{
    private:
      /* data */
    public:
        // General // 
        static constexpr int baud_rate = 115200; 
        // Movement (Steppers) // 
        static constexpr uint8_t stepper = 22; // Faltan
        
        // Controler // 
        static constexpr uint8_t input_a = 0; // Faltan
        static constexpr uint8_t input_b = 0; // Faltan

        // Security // 
        static constexpr uint8_t limit_right = 0; // Faltan
        static constexpr uint8_t limit_left = 0; // Faltan

        // Stepper // 

};
#endif