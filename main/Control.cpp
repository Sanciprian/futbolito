#include "Control.h"

// Constructor //
Control::Control() {}

// Setup //
void Control::BeginControl()
{
  _esp32->begin("ESP32_CONTROLLER");
  _currentBoton = Constants::RELEASEB;
}

// Getters //
states Control::GetInput()
{
  if (_esp32->available())
  {
    _currentBoton = _esp32->read();
  }
  switch (_currentBoton)
  {
  case Constants::RIGHTB:
    return Right;
    break;
  case Constants::LEFTB:
    return Left;
    break;
  case Constants::INCREASE_SPEEDB:
    return IncreaseSpeed;
    break;
  case Constants::LOWER_SPEEDB:
    return LowerSpeed;
    break;
  case Constants::SHOOTB:
    return Shoot;
    break;
  case Constants::RELEASEB:
    return Stop;
    break;
  }
  return Stop; // In theory this will never happen.
}

void Control::PrintState()
{
  Serial.println(_currentBoton);
}