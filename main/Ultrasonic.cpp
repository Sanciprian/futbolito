#include "Ultrasonic.h"

Ultrasonic::Ultrasonic() : _trigger(Constants::TRIGGER_PIN), _echo(Constants::ECHO_PIN), _counter(Constants::COUNTER_PIN)
{
    _goals = 0;
    _duration = 0;
    _distance = 0;
    _lcd = new LiquidCrystal_I2C(Constants::LCD_ADDRESS, Constants::LCD_COLUMNS, Constants::LCD_ROWS);
}
void Ultrasonic::BeginUltrasonic()
{
    pinMode(_trigger, OUTPUT);
    pinMode(_echo, INPUT);
    pinMode(_counter, OUTPUT);
    _lcd->init();
    _lcd->backlight();
    _lcd->clear();
    _lcd->setCursor(0, 0);
    this->PrintScore();
}
int Ultrasonic::GetDistance()
{
    return _distance;
}

void Ultrasonic::SetDistance()
{
    digitalWrite(_trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigger, LOW);
    _duration = pulseIn(_echo, HIGH);
    _distance = _duration / 58.2;
}

int Ultrasonic::GetGoals()
{
    return _goals;
}

bool Ultrasonic::Score()
{
    if (_distance <= 5 || _distance == 1207)
    {
        _goals = _goals + 1;
        return true;
    }
    return false;
}

void Ultrasonic::PrintScore()
{
    if (_goals < 10)
    {
        _lcd->print(_goals);
    }
    else
    {
        String temp = String(_goals);
        _lcd->print(temp[1]);
        _lcd->setCursor(1, 0);
        _lcd->print(temp[0]);
    }
}
