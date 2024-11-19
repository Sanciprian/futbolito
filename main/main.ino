#include "Constants.h"
#include "Control.h"
#include "Movement.h"

// Objects //
Control control;
Movement movement(Constants::DEFAULT_SPEED, Constants::DIR_PIN, Constants::STEP_PIN, Constants::ENABLE_PIN, Constants::SERIAL_DRIVER, Constants::DRIVER_ADDRESS);
states currentState = Stop;

// Gobal Variables //
unsigned long currenTime;

void setup()
{
  // Serial Communication //
  Serial.begin(Constants::BAUD_RATE);

  // Setup //
  control.BeginControl();
  movement.BeginMovement();

  // Limit Switches // 
}

void loop()
{
  currenTime = micros();
  movement.Move(currenTime);
  currentState = control.GetInput();
  switch (currentState)
  {
  case Stop:
    movement.SetDriverState(false); // Is there going to be a need for hard stop ??
    break;
  case Left:
    movement.SetLeft();
    break;
  case Right:
    movement.SetRight();
    break;
  case Shoot:
    break;
  case LowerSpeed:
    movement.DecreaseSpeed();
    break;
  case IncreaseSpeed:
    movement.IncreaseSpeed();
    break;
  }
}
