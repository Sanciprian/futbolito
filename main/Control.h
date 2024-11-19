/*
  Bluetooth buton Lingo
  Release = 0
  left = L
  right = R
  up = F
  down = B

  circule (right)= C
  triangle(up) = T
  x(down) = X
  square(left) = S
*/

#ifndef Control_h
#define Control_h

// External Files //
#include "Constants.h"
#include "BluetoothSerial.h"

// Class //
class Control
{
private:
  // data //
  volatile char _currentBoton;
  BluetoothSerial *_esp32;

public:
  // Constructor //
  Control();

  // Setup //
  void BeginControl();

  // Getters //
  states GetInput();

  // Methods //
  void PrintState(); // for debugging
};
#endif