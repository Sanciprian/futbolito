#include "Control.h"


// Constructor // 
Control::Control(){}

// Setup // 
void Control::beginControl(){
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
}

// Getters //
states Control::getInput(){
  
  return Stop;// default
}