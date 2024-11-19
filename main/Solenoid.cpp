#include "Solenoid.h"

Solenoid::Solenoid() : _pin(Constants::SOLENOID_PIN), _duration(Constants::DURATION), _recoil(Constants::RECOIL_DURATION)
{
    _phase = false;
}

void Solenoid::BeginSolenoid()
{
    pinMode(_pin, OUTPUT);
    _lastTime = micros();
}

void Solenoid::State(unsigned long currentTime)
{
    if (currentTime - _lastTime > _duration && _phase)
    {
        digitalWrite(_pin, LOW);
        _phase = false;
        _lastTime = currentTime;
    }
}

void Solenoid::Shoot(unsigned long currentTime)
{
    if (currentTime - _lastTime > _recoil)
    {
        digitalWrite(_pin, HIGH);
        _phase = true;
        _lastTime = currentTime;
    }
}