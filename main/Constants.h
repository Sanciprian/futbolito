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
  Shoot = 3,
  IncreaseSpeed = 4,
  LowerSpeed = 5
};

// Constants Values Throughtout The Code //
class Constants
{
private:
  /* data */
public:
  // General //
  static constexpr uint32_t BAUD_RATE = 115200;
  // Movement (Steppers) //
  static constexpr uint8_t DIR_PIN = 22;
  static constexpr uint8_t STEP_PIN = 22;
  static constexpr uint8_t ENABLE_PIN = 22;
  static constexpr uint8_t DRIVER_ADDRESS = 0b00;
  static constexpr HardwareSerial &SERIAL_DRIVER = Serial2; // We will not use it. But it is needed to use the library.
  static constexpr uint32_t BAUD_DRIVER = 115200;
  static constexpr uint8_t MAX_SPEED = 60;
  static constexpr uint8_t MIN_SPEED = 600;
  static constexpr uint8_t DEFAULT_SPEED = 300;
  static constexpr uint8_t CURRENT = 1400; // max for driver.
  static constexpr uint8_t SPEED_VARIATION = 5;

  // Controler //
  static constexpr char INCREASE_SPEEDB = 'T';
  static constexpr char LOWER_SPEEDB = 'X';
  static constexpr char SHOOTB = 'C';
  static constexpr char RIGHTB = 'R';
  static constexpr char LEFTB = 'L';
  static constexpr char RELEASEB = '0';

  // Security //
  static constexpr uint8_t RIGHT_LIMIT_PIN = 0; // Faltan
  static constexpr uint8_t LEFT_LIMIT_PIN = 0;  // Faltan

  // Solenoid //
  static constexpr uint8_t SOLENOID_PIN = 0;
};
#endif