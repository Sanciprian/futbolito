#include "Constants.h"
#include "Control.h"
#include "Movement.h"
#include "Solenoid.h"
#include "Ultrasonic.h"

// Objects //
Control control;
Movement movement(Constants::DEFAULT_SPEED, Constants::DIR_PIN, Constants::STEP_PIN, Constants::ENABLE_PIN, Constants::SERIAL_DRIVER, Constants::DRIVER_ADDRESS);
Solenoid solenoid;
Ultrasonic goal;

// Gobal Variables //
unsigned long currenTime;
states currentState = Stop;

void setup()
{
  // Serial Communication //
  Serial.begin(Constants::BAUD_RATE);

  // Setup //
  control.BeginControl();
  movement.BeginMovement();
  solenoid.BeginSolenoid();
  goal.BeginUltrasonic();

  // Limit Switches //
  pinMode(Constants::RIGHT_LIMIT_PIN, INPUT_PULLUP);
  pinMode(Constants::LEFT_LIMIT_PIN, INPUT_PULLUP);
  attachInterrupt(Constants::RIGHT_LIMIT_PIN, HardStop, CHANGE);
  attachInterrupt(Constants::LEFT_LIMIT_PIN, HardStop, CHANGE);
}

void loop()
{
  currenTime = micros();
  movement.Move(currenTime);
  solenoid.State(currenTime);
  currentState = control.GetInput();
  // goal.GetDistance
  // control.PrintState();
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
    solenoid.Shoot(currentState);
    break;
  case LowerSpeed:
    movement.DecreaseSpeed();
    break;
  case IncreaseSpeed:
    movement.IncreaseSpeed();
    break;
  }

  goal.SetDistance();
  if (goal.Score())
  {
    goal.PrintScore();
  }
}

void HardStop()
{
  movement.Stop();
}