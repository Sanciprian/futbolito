#include "Constants.h"
#include "Control.h"

// Objects // 
Control control;

states currentState = Stop; 
// Gobal Variables // 
void setup() {
  // Serial Communication // 
  Serial.begin(Constants::baud_rate);
  
  // Setup //
  control.beginControl();
}

void loop() {
  currentState = control.getInput();
  switch (currentState) { 
    case Stop:
      break;
    case Left:
      break;
    case Right:
      break;
    case Shoot:
      break;
  }
}
