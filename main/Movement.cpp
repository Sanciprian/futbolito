#include "Movement.h"

// Constructor //
Movement::Movement(uint8_t speed, uint8_t dirPin, uint8_t stepPin, uint8_t enablePin, HardwareSerial &port, uint8_t address)
    : _dir(dirPin), _step(stepPin), _enable(enablePin), _serial(port), _address(address), _variation(Constants::SPEED_VARIATION)
{
  this->SetSpeed(speed);
  _minSpeed = Constants::MIN_SPEED;
  _maxSpeed = Constants::MAX_SPEED;
  _driver = new TMC2208Stepper(&_serial, _address);
}

// Setup //
void Movement::BeginMovement()
{
  // Declaration of pins and serial
  _serial.begin(Constants::BAUD_DRIVER);
  pinMode(_dir, OUTPUT);
  pinMode(_step, OUTPUT);
  pinMode(_enable, OUTPUT);

  // Driver
  _driver->begin();
  _driver->toff(5);                         // Configure off time
  _driver->blank_time(24);                  // Configure blanking time
  _driver->rms_current(Constants::CURRENT); // Set motor current in mA (adjust to your motor's rating)
  _driver->microsteps(1);                   // No microstepping

  // Variables
  _lastTime = micros();
  _moveFlag = true;
  _state = false;
}

// Setters //
void Movement::SetSpeed(int speed)
{
  _speed = map(constrain(speed, 0, 100), 0, 100, _minSpeed, _maxSpeed);
}

// Methods //
void Movement::SetLeft()
{
  // stepper left this->speed
  this->SetDriverState(true);
  digitalWrite(_dir, HIGH);
}

void Movement::SetRight()
{
  // stepper right this->speed
  this->SetDriverState(true);
  digitalWrite(_dir, LOW);
}

void Movement::Move(unsigned long currentTime)
{
  /*
    Tried to avoid time blocking. Thus created the function this way.
    However, we need to test in practice if this will work.
    Since the execution of the code can take longer than the time set in here.
    If that happend we will need to change to delayMicroseconds();
  */
  if (_state) // Does nothing onless driver is active
  {
    if (currentTime - _lastTime >= _speed)
    {
      if (_moveFlag)
      {
        digitalWrite(_step, HIGH);
        _lastTime = currentTime;
        _moveFlag = false;
      }
      else
      {
        digitalWrite(_step, LOW);
        _lastTime = currentTime;
        _moveFlag = true;
      }
    }
  }
}
void Movement::SetDriverState(bool state)
{
  _state = state;
  digitalWrite(_enable, !_state);
}

void Movement::DefaultPos()
{
  // Go to the middle of the field. This method can work when autonomous
}

void Movement::IncreaseSpeed()
{
  this->SetSpeed(_speed + _variation);
}

void Movement::DecreaseSpeed()
{
  this->SetSpeed(_speed - _variation);
}

void Movement::Stop()
{
  this->SetDriverState(true);
  digitalWrite(_step, LOW);
  delayMicroseconds(1000);
  this->SetDriverState(false);
  _state = false;
}