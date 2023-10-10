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
  int x = 0;
  int y = 0;
  int z = 0;
  
  //X axis
  for (int i = 0; i < 4; i++){
    cube.line(x, y, z, x, y, z + 3, RED);
    x++;
    if(x > 4){
      x = 0;
    }
    delay(200);
  }
  cube.all(BLACK);
  delay(200);

  //Y axis
  x = 0;
  y = 0;
  z = 0;
  for (int i = 0; i < 4; i++){
    cube.line(x, y, z, x, y, z + 3, RED);
    y++;
    if(y > 4){
      y = 0;
    }
    delay(200);
  }
  cube.all(BLACK);
  delay(200);
  
  //Z axis
  x = 0;
  y = 0;
  z = 0;
  for (int i = 0; i < 4; i++){
    cube.line(x, y, z, x + 3, y, z, RED);
    z++;
    if(z > 4){
      z = 0;
    }
    delay(200);
  }
  cube.all(BLACK);
  delay(200);
}
