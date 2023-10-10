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
  if (initialValue > 80) {
    tuning3();
  }
  else if (initialValue > 40) {
    tuning2();
  }
  else if (initialValue > 15) {
    tuning1();
  }
  cube.all(BLACK);
}

void tuning3(){
  int de = 50;
  static int c = 0;
  for(int i = 0; i < 4; i++){
    cube.all(BLACK);
    cube.box(0, 0, 0, 0, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(1, 0, 0, 1, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(2, 0, 0, 2, 3, i, BLUE);
    cube.box(3, 0, 0, 3, 3, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 3; i >= 0; i--){
    cube.all(BLACK);
    cube.box(0, 0, 0, 0, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(1, 0, 0, 1, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(2, 0, 0, 2, 3, i, BLUE);
    cube.box(3, 0, 0, 3, 3, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 0; i < 4; i++){
    cube.all(BLACK);
    cube.box(1, 0, 0, 1, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(0, 0, 0, 0, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(3, 0, 0, 3, 3, i, BLUE);
    cube.box(2, 0, 0, 3, 2, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 3; i >= 0; i--){
    cube.all(BLACK);
    cube.box(1, 0, 0, 1, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(0, 0, 0, 0, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(3, 0, 0, 3, 3, i, BLUE);
    cube.box(2, 0, 0, 3, 2, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
}

void tuning2(){
  int de = 50;
  static int c = 0;
  for(int i = 0; i < 3; i++){
    cube.all(BLACK);
    cube.box(0, 0, 0, 0, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(1, 0, 0, 1, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(2, 0, 0, 2, 3, i, BLUE);
    cube.box(3, 0, 0, 3, 3, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 2; i >= 0; i--){
    cube.all(BLACK);
    cube.box(0, 0, 0, 0, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(1, 0, 0, 1, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(2, 0, 0, 2, 3, i, BLUE);
    cube.box(3, 0, 0, 3, 3, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 0; i < 3; i++){
    cube.all(BLACK);
    cube.box(1, 0, 0, 1, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(0, 0, 0, 0, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(3, 0, 0, 3, 3, i, BLUE);
    cube.box(2, 0, 0, 3, 2, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 2; i >= 0; i--){
    cube.all(BLACK);
    cube.box(1, 0, 0, 1, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(0, 0, 0, 0, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(3, 0, 0, 3, 3, i, BLUE);
    cube.box(2, 0, 0, 3, 2, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
}

void tuning1(){
  int de = 50;
  static int c = 0;
  for(int i = 0; i < 2; i++){
    cube.all(BLACK);
    cube.box(0, 0, 0, 0, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(1, 0, 0, 1, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(2, 0, 0, 2, 3, i, BLUE);
    cube.box(3, 0, 0, 3, 3, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 1; i >= 0; i--){
    cube.all(BLACK);
    cube.box(0, 0, 0, 0, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(1, 0, 0, 1, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(2, 0, 0, 2, 3, i, BLUE);
    cube.box(3, 0, 0, 3, 3, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 0; i < 2; i++){
    cube.all(BLACK);
    cube.box(1, 0, 0, 1, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(0, 0, 0, 0, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(3, 0, 0, 3, 3, i, BLUE);
    cube.box(2, 0, 0, 3, 2, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
  for(int i = 1; i >= 0; i--){
    cube.all(BLACK);
    cube.box(1, 0, 0, 1, 3, i, RGB(0x0f, 0xf0, 0x0f));
    cube.box(0, 0, 0, 0, 3, (c = i - 1 > 0 ? i - 1 : 0), RED);
    cube.box(3, 0, 0, 3, 3, i, BLUE);
    cube.box(2, 0, 0, 3, 2, (c = i - 1 > 0 ? i - 1 : 0), GREEN);
    delay(de);
  }
}