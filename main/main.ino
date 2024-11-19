#include "Constants.h"
#include "Control.h"
#include "Movement.h"

// Objects //
Control control;
Movement movement(Constants::DEFAULT_SPEED, Constants::DIR_PIN, Constants::STEP_PIN, Constants::ENABLE_PIN, Constants::SERIAL_DRIVER, Constants::DRIVER_ADDRESS);
states currentState = Stop;

// Gobal Variables //
unsigned long time;

void setup()
{
  // Serial Communication //
  Serial.begin(Constants::BAUD_RATE);

  // Setup //
  control.beginControl();
}

void loop()
{
  time = micros();
  currentState = control.getInput();
  movement.Move(time);

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
  }
}
