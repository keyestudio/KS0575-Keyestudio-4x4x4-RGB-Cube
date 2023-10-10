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
  //Set a random x, y, z value
  int randx1 = random(4);
  int randy1 = random(4);
  int randz1 = random(4);

  //Light up a random LED in a random color
  //RGB(random(255), random(255), random(255))
  cube.set(randx1, randy1, randz1, RGB(random(255), random(255), random(255)));
  delay(10);
}
