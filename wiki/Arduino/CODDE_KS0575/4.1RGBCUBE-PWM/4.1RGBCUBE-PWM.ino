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

  //Red
  for(int i = 0; i <256; i++){
    cube.all(RGB(i,0,0));
    delay(10);
  }
  for(int i = 255; i > 1; i--){
    cube.all(RGB(i,0,0));
    delay(10);
  }
  //Blue
  for(int i = 0; i <256; i++){
    cube.all(RGB(0,0,i));
    delay(10);
  }
  for(int i = 255; i > 1; i--){
    cube.all(RGB(0,0,i));
    delay(10);
  }
  //Greed
  for(int i = 0; i <256; i++){
    cube.all(RGB(0,i,0));
    delay(10);
  }
  for(int i = 255; i > 1; i--){
    cube.all(RGB(0,i,0));
    delay(10);
  }
}
