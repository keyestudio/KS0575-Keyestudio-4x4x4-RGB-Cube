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
  if(initialValue > 800) {
    //Circulate to light up RGB LED till all LED are on
    cube.all(RED);
  }
  else if (initialValue > 600) {
    //Circulate to light up RGB LED till 3 rows of RGB LED are on
    for (int i = 0; i < 3; i++) {
      cube.line(0, 0, i, 3, 0, i, RGB(mapValue, 0, 50));
      cube.line(0, 1, i, 3, 1, i, RGB(mapValue, 0, 50));
      cube.line(0, 2, i, 3, 2, i, RGB(mapValue, 0, 50));
      cube.line(0, 3, i, 3, 3, i, RGB(mapValue, 0, 50));
      cube.set(1, 0, 3, RGB(mapValue, 0, 50));
      cube.set(1, 1, 3, RGB(mapValue, 0, 50));
      cube.set(1, 2, 3, RGB(mapValue, 0, 50));
      cube.set(1, 3, 3, RGB(mapValue, 0, 50));
    }
  }
  else if (initialValue > 400) {
    //Circulate to light up RGB LED till 2 rows of RGB LED are on
    for (int i = 0; i < 2; i++) {
      cube.line(0, 0, i, 3, 0, i, RGB(0, 50, mapValue));
      cube.line(0, 1, i, 3, 1, i, RGB(0, 50, mapValue));
      cube.line(0, 2, i, 3, 2, i, RGB(0, 50, mapValue));
      cube.line(0, 3, i, 3, 3, i, RGB(0, 50, mapValue));
      cube.set(2, 0, 2, RGB(0, 50, mapValue));
      cube.set(2, 1, 2, RGB(0, 50, mapValue));
      cube.set(2, 2, 2, RGB(0, 50, mapValue));
      cube.set(2, 3, 2, RGB(0, 50, mapValue));
    }
  }
  else if (initialValue > 200) {
    //Circulate to light up RGB LED till 1 row of RGB LED are on. If the value is lower than 200, turn off all LED.
    for (int i = 0; i < 1; i++) {
      cube.line(0, 0, i, 3, 0, i, RGB(mapValue, mapValue, mapValue));
      cube.line(0, 1, i, 3, 1, i, RGB(mapValue, mapValue, mapValue));
      cube.line(0, 2, i, 3, 2, i, RGB(mapValue, mapValue, mapValue));
      cube.line(0, 3, i, 3, 3, i, RGB(mapValue, mapValue, mapValue));
      cube.set(1, 0, 1, RGB(mapValue, mapValue, mapValue));
      cube.set(1, 1, 1, RGB(mapValue, mapValue, mapValue));
      cube.set(1, 2, 1, RGB(mapValue, mapValue, mapValue));
      cube.set(1, 3, 1, RGB(mapValue, mapValue, mapValue));
    }
  }
  delay(500);
  cube.all(BLACK);
}
