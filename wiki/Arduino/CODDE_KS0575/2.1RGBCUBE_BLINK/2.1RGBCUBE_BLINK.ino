#include "SPI.h"
#include "Cube.h"

Cube cube;

void setup() {
  // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud
}

void loop() {

  //set 0 0 0 The Start Point as red
  cube.set(0, 0, 0, RED);
  delay(500);
  //Turn off all RGB LED, NOTE: When lights out, it only can turn off all RGB LED rather than only one of them.
  cube.all(BLACK);
  delay(500);
  
}
