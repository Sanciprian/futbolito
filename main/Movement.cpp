#include "Movement.h"

// Constructor //
Movement::Movement(uint8_t _speed){
  this->speed = _speed;
}

// Setup //
void Movement::beginMovement(){
  //stepper
  // driver
  // Calibrate
}

// Setters //
void Movement::setSpeed(int _speed){
  this->speed = _speed; // El plan es modificarlo si necesario
}


// Methods //
void Movement::left(){
  //stepper left this->speed
}

void Movement::right(){
  //stepper right this->speed
}

void Movement::shoot(){
  // 
}

void Movement::defaultPos(){
  // Go to the middle of the fild
}