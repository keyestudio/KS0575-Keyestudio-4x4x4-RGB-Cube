#include "SPI.h"
#include "Cube.h"

#define ANALOGPIN A1

Cube cube;

void setup(void) {
  // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud
  pinMode(ANALOGPIN,INPUT);
}

void loop(void) {
  int initialValue = analogRead(ANALOGPIN);
  int mapValue = map(initialValue, 0, 1023, 0, 255);
  //all RGB
  cube.all(RGB(mapValue, mapValue, mapValue));
  //red
  // cube.all(RGB(mapValue, 0, 0));
  //greed
  // cube.all(RGB(0, mapValue, 0));
  //blue
  // cube.all(RGB(0, 0, mapValue));
  delay(100);
}