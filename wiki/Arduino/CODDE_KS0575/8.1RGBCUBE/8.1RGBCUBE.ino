#include "SPI.h"
#include "Cube.h"

#define DELAY   50

#define LIGHTNINGINTERVAL 40 // How many raindrops between random lightning strikes, on average
#define RAINDROPDELAY 50     // Milliseconds between raindrop movements
#define MAXLIGHTNING 2       // Maximum number of flashes per lightning strike
#define SHOWCLOUDS 1         // Display a "cloud" layer at the top

int rr1=0;
int gg1=0;
int bb1=255;
int rr2 = 0;
int gg2 = 0;
int bb2 = 255;
int rr3=0;
int gg3=0;
int bb3=255;
int i = 15;
int timer=150;
int timer2=5;

byte drop1XPos;
byte drop1YPos;
byte drop1ZPos = 2;
byte drop2XPos;
byte drop2YPos;
byte drop2ZPos = 0;
byte xPos;
byte yPos;
byte zPos;
byte rr;
byte gg;
byte bb;
rgb_t colour;

byte testState = 0;
byte previousTestState = 0;

Cube cube;

void setup(void) {
  // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud

}

void loop(void) {

  
  cube.all(BLACK);
  for(int i = 0; i < 12;i++){
    clolorFader1();
  }
  clolorFader2();
  cube.all(BLACK);
  laserShow();
  laserShow2();
  cube.all(BLACK);
  spacetime();
  cube.all(BLACK);
  Heartbeat();
  Heartbeat();
  cube.all(BLACK);
  for(int i = 0; i < 60; i++){
    Rainstorm();
  }
  cube.all(BLACK);
  RandomColours();
  cube.all(BLACK);
  Sphere();
  cube.all(BLACK);
  TestPattern();
  cube.all(BLACK);
  for(int i = 0; i < 888; i++){
    RandomColours(2);
  }
}

void laserShow(){
  byte x = 0;
  byte y = 0;
  byte step_x = 1;
  byte step_y = 0;
  for (byte i = 0; i < 24; i++) {
    cube.all(BLACK);
    if (i <= 12) {
      cube.line(0, 3, 0, y, 3-x, 3, WHITE);
      cube.line(3, 3, 0, 3-x, 3-y, 3, BLUE);
      cube.line(3, 0, 0, 3-y, x, 3, GREEN);
      cube.line(0, 0, 0, x, y, 3, RED);
    } else {
      cube.line(0, 3, 3, y, 3-x, 0, WHITE);
      cube.line(3, 3, 3, 3-x, 3-y, 0, BLUE);
      cube.line(3, 0, 3, 3-y, x, 0, GREEN);
      cube.line(0, 0, 3, x, y, 0, RED);
    }
    if (x == 3 && y == 0) {
      step_x = 0;
      step_y = 1;
    } else if (x == 3 && y == 3) {
      step_x = -1;
      step_y = 0;
    } else if (x == 0 && y == 3) {
      step_x = 0;
      step_y = -1;
    } else if (x == 0 && y == 0) {
      step_x = 1;
      step_y = 0;
    }
    x += step_x;
    y += step_y;
    delay(100);
  }
  cube.all(BLACK);
  x = 0;
  y = 0;
  step_x = 1;
  step_y = 0;
  int k = 0;
  int j = 255;
  int b = 100;
  for (byte i = 0; i < 16; i++) {
    k = i + 40;
    j -= 40;
    if (b == 100){
      b = 0;
    }else{
      b = 100;
    }
    cube.line(x, y, 0, x, y, 3, RGB(k, b, j));
    if (x == 3 && y == 0) {
      step_x = 0;
      step_y = 1;
    } else if (x == 3 && y == 3) {
      step_x = -1;
      step_y = 0;
    } else if (x == 0 && y == 3) {
      step_x = 0;
      step_y = -1;
    } else if (x == 0 && y == 1) {
      step_x = 1;
      step_y = 0;
    } else if (x == 2 && y == 1) {
      step_x = 0;
      step_y = 1;
    } else if (x == 2 && y == 2) {
      step_x = -1;
      step_y = 0;
    }
    x += step_x;
    y += step_y;
    delay(50);
  }
}
void laserShow2(){
  tuning3();
  tuning2();
  tuning3();
  tuning2();
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

void Heartbeat(){
  rise();
  delay(40);
  fall();
  delay(100);
  rise();
  delay(40);
  fall();
  delay(500);
}
/**
 * Illuminate one LED at a time, starting from the bottom
 */
void rise()
{
  int i = 0;
  int xPos = 0;
  int yPos = 0;
  int zPos = 0;

  while(zPos < 4)
  {
    yPos = 3;
    while(yPos > -1)
    {
      xPos = 0;
      while(xPos < 4)
      {
        cube.set(xPos, yPos, zPos, RED);
        xPos++;
        i++;
        delay(4);
      }
      yPos--;
    }
    zPos++;
  }
}

/**
 * Extinguish one LED at a time, starting from the top
 */
void fall()
{
  int xPos = 3;
  int yPos = 3;
  int zPos = 3;

  while(zPos > -1)
  {
    xPos = 3;
    while(xPos > -1)
    {
      yPos = 3;
      while(yPos > -1)
      {
        cube.set(xPos, yPos, zPos, BLACK);
        yPos--;
        delay(4);
      }
      xPos--;
    }
    zPos--;
  }
}

void Rainstorm(){
  if(drop1ZPos == 4)
  {
    drop1XPos = random(4);
    drop1YPos = random(4);
  }

  if(drop2ZPos == 4)
  {
    drop2XPos = random(4);
    drop2YPos = random(4);
  }

  cube.all(BLACK);
  clouds();

  if(drop1ZPos > 0)
  {
    drop1ZPos--;
    cube.set(drop1XPos, drop1YPos, drop1ZPos, BLUE);
  } else {
    drop1ZPos = 4;
  }

  if(drop2ZPos > 0)
  {
    drop2ZPos--;
    cube.set(drop2XPos, drop2YPos, drop2ZPos, BLUE);
  } else {
    drop2ZPos = 4;
  }

  delay(RAINDROPDELAY);

  lightning();
}

/**
 * Randomly display a lightning strike
 */
void lightning()
{
  if(random(LIGHTNINGINTERVAL) == 1)
  {
    int lightningFlashes = random(0, MAXLIGHTNING + 1);
    int i = 0;
    while (i < lightningFlashes)
    {
      cube.all(WHITE);
      delay(50);
      cube.all(BLACK);
      delay(150);
      i++;
    }
  }
}

/**
 * Display a white cloud layer at the top of the cube
 */
void clouds()
{
  if(SHOWCLOUDS)
  {
    cube.setplane(Z, 3, WHITE);
  }
}

void RandomColours(){
  xPos = random(4);
  yPos = random(4);
  zPos = random(4);
  rr = random(0, 2) * 255;
  gg = random(0, 2) * 255;
  bb = random(0, 2) * 255;
  
  cube.set(xPos, yPos, zPos, RGB(rr, gg, bb));
  delay(2);
}

void Sphere(){
    for (byte i = 1; i <= 4; i++) {
    // Hollow sphere
    cube.all(BLACK); 
    cube.sphere(1, 1, 1, i, GREEN);
    delay(500);
    // Sphere
    cube.all(BLACK);
    cube.sphere(1, 1, 1, i, RED, BLUE);
    delay(500);
  }
}

void TestPattern(){
  if(!cube.hasReceivedSerialCommand())
  {
    previousTestState = testState;
    switch(testState)
    {
      case 0:
        stepThroughLEDs();
        testState = 1;
        break;
      case 1:
        cycleCubeColours();
        testState = 2;
        break;
      case 2:
        fadeWhite();
        testState = 3;
        break;
      case 3:
        fadeWhite();
        testState = 4;
        break;
      case 4:
        fadeWhite();
        testState = 5;
        break;
      case 5:
        randomPastel();
        break;
    }
  } else {
    testState = 99;
  }
  
  if(testState == 99 && previousTestState != 99)
  {
    cube.all(BLACK);
    previousTestState = 99;
  }
}

void cycleCubeColours()
{
  cube.all(RED);
  delay(300);
  cube.all(GREEN);
  delay(300);
  cube.all(BLUE);
  delay(300);
  cube.all(ORANGE);
  delay(300);
  cube.all(PINK);
  delay(300);
  cube.all(RGB(0x00, 0x44, 0xA));
  delay(300);
}

void stepThroughLEDs()
{
  int i = 0;
  int xPos = 0;
  int yPos = 0;
  int zPos = 0;

  while(zPos < 4)
  {
    yPos = 3;
    while(yPos > -1)
    {
      xPos = 0;
      while(xPos < 4)
      {
        cube.all(BLACK);
        cube.set(xPos, yPos, zPos, WHITE);
        xPos++;
        i++;
        delay(50);
      }
      yPos--;
    }
    zPos++;
  }
}

void cyclePlaneColours()
{
  for (byte i = 0; i < 4; i++)
  {
    cube.all(BLACK);
    cube.setplane(Z, i, RED);
    delay(200);
    cube.all(BLACK);
    cube.setplane(Z, i, GREEN);
    delay(200);
    cube.all(BLACK);
    cube.setplane(Z, i, BLUE);
    delay(200);
  }
}

void fadeWhite()
{
  for (byte i = 0; i < 255; i++)
  {
    cube.all(RGB(i, i, i));
    delay(3);
  }
  for (byte i = 255; i > 0; i--)
  {
    cube.all(RGB(i, i, i));
    delay(3);
  }
}

void randomPastel()
{  
  cube.set(random(4), random(4), random(4), RGB(random(255), random(255), random(255)));
  delay(2);
}

void clolorFader1(){
  static int k = 0;
  if(k == 0){
    rr2 = rr2 >= 255 ? 255 : (rr2 + i > 255 ? 255 : rr2 + i);
    bb2 = 0 >= bb2 ? 0 : (bb2 - i < 0 ? 0 : bb2 - i);
    cube.line(0, 0, 0, 3, 0, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 0, 3, 1, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 0, 3, 2, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 0, 3, 3, 0, RGB(rr2, gg2, bb2));
    delay(timer);
    rr2 = rr2 >= 255 ? 255 : (rr2 + i > 255 ? 255 : rr2 + i);
    bb2 = 0 >= bb2 ? 0 : (bb2 - i < 0 ? 0 : bb2 - i);
    cube.line(0, 0, 1, 3, 0, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 1, 3, 1, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 1, 3, 2, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 1, 3, 3, 1, RGB(rr2, gg2, bb2));
    delay(timer);
    rr2 = rr2 >= 255 ? 255 : (rr2 + i > 255 ? 255 : rr2 + i);
    bb2 = 0 >= bb2 ? 0 : (bb2 - i < 0 ? 0 : bb2 - i);
    cube.line(0, 0, 2, 3, 0, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 2, 3, 1, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 2, 3, 2, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 2, 3, 3, 2, RGB(rr2, gg2, bb2));
    delay(timer);
    rr2 = rr2 >= 255 ? 255 : (rr2 + i > 255 ? 255 : rr2 + i);
    bb2 = 0 >= bb2 ? 0 : (bb2 - i < 0 ? 0 : bb2 - i);
    cube.line(0, 0, 3, 3, 0, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 3, 3, 1, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 3, 3, 2, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 3, 3, 3, 3, RGB(rr2, gg2, bb2));
    delay(timer);
    if (rr2 >= 255) k = 1;
  }
  if(k == 1){
    gg2 = gg2 >= 255 ? 255 : (gg2 + i > 255 ? 255 : gg2 + i);
    rr2 = 0 >= rr2 ? 0 : (rr2 - i < 0 ? 0 : rr2 - i);
    cube.line(0, 0, 0, 3, 0, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 0, 3, 1, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 0, 3, 2, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 0, 3, 3, 0, RGB(rr2, gg2, bb2));
    delay(timer);
    gg2 = gg2 >= 255 ? 255 : (gg2 + i > 255 ? 255 : gg2 + i);
    rr2 = 0 >= rr2 ? 0 : (rr2 - i < 0 ? 0 : rr2 - i);
    cube.line(0, 0, 1, 3, 0, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 1, 3, 1, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 1, 3, 2, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 1, 3, 3, 1, RGB(rr2, gg2, bb2));
    delay(timer);
    gg2 = gg2 >= 255 ? 255 : (gg2 + i > 255 ? 255 : gg2 + i);
    rr2 = 0 >= rr2 ? 0 : (rr2 - i < 0 ? 0 : rr2 - i);
    cube.line(0, 0, 2, 3, 0, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 2, 3, 1, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 2, 3, 2, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 2, 3, 3, 2, RGB(rr2, gg2, bb2));
    delay(timer);
    gg2 = gg2 >= 255 ? 255 : (gg2 + i > 255 ? 255 : gg2 + i);
    rr2 = 0 >= rr2 ? 0 : (rr2 - i < 0 ? 0 : rr2 - i);
    cube.line(0, 0, 3, 3, 0, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 3, 3, 1, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 3, 3, 2, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 3, 3, 3, 3, RGB(rr2, gg2, bb2));
    delay(timer);
    if (gg2 >= 255) k = 2;
  }
  if(k == 2){
    bb2 = bb2 >= 255 ? 255 : (bb2 + i > 255 ? 255 : bb2 + i);
    gg2 = 0 >= gg2 ? 0 : (gg2 - i < 0 ? 0 : gg2 - i);
    cube.line(0, 0, 0, 3, 0, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 0, 3, 1, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 0, 3, 2, 0, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 0, 3, 3, 0, RGB(rr2, gg2, bb2));
    delay(timer);
    bb2 = bb2 >= 255 ? 255 : (bb2 + i > 255 ? 255 : bb2 + i);
    gg2 = 0 >= gg2 ? 0 : (gg2 - i < 0 ? 0 : gg2 - i);
    cube.line(0, 0, 1, 3, 0, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 1, 3, 1, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 1, 3, 2, 1, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 1, 3, 3, 1, RGB(rr2, gg2, bb2));
    delay(timer);
    bb2 = bb2 >= 255 ? 255 : (bb2 + i > 255 ? 255 : bb2 + i);
    gg2 = 0 >= gg2 ? 0 : (gg2 - i < 0 ? 0 : gg2 - i);
    cube.line(0, 0, 2, 3, 0, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 2, 3, 1, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 2, 3, 2, 2, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 2, 3, 3, 2, RGB(rr2, gg2, bb2));
    delay(timer);
    bb2 = bb2 >= 255 ? 255 : (bb2 + i > 255 ? 255 : bb2 + i);
    gg2 = 0 >= gg2 ? 0 : (gg2 - i < 0 ? 0 : gg2 - i);
    cube.line(0, 0, 3, 3, 0, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 1, 3, 3, 1, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 2, 3, 3, 2, 3, RGB(rr2, gg2, bb2));
    cube.line(0, 3, 3, 3, 3, 3, RGB(rr2, gg2, bb2));
    delay(timer);
    if (bb2 >= 255) k = 0;
  }
}

void clolorFader2(){

  while (rr3<255){
    rr3=rr3+1;
    bb3=bb3-1;
    cube.all(RGB(rr3, gg3, bb3));
    delay(timer2);
  }

  while (gg3<255){
    gg3=gg3+1;
    rr3=rr3-1;
    cube.all(RGB(rr3, gg3, bb3));
    delay(timer2);
  }

  while (bb3<255){
    bb3=bb3+1;
    gg3=gg3-1;
    cube.all(RGB(rr3, gg3, bb3));
    delay(timer2);
  }

}

void spacetime(){
  int de = 150;
  for(int i = 0; i < 4; i++){
    cube.all(BLACK);
    cube.line(0, i, 0, 0, i, 3, RGB(255, 0, 0));
    cube.line(0, i, 0, 3, i, 0, RGB(255, 0, 0));
    cube.line(3, i, 0, 3, i, 3, RGB(255, 0, 0));
    cube.line(0, i, 3, 3, i, 3, RGB(255, 0, 0));
    delay(de);
  }

  for(int i = 3; i > 0; i--){
    cube.all(BLACK);
    cube.line(0, i, 0, 0, i, 3, RGB(50, 255, 0));
    cube.line(0, i, 0, 3, i, 0, RGB(50, 255, 0));
    cube.line(3, i, 0, 3, i, 3, RGB(50, 255, 0));
    cube.line(0, i, 3, 3, i, 3, RGB(50, 255, 0));
    delay(de);
  }

  for(int i = 0; i < 4; i++){
    cube.all(BLACK);
    cube.line(i, 0, 0, i, 3, 0, RGB(0, 0, 255));
    cube.line(i, 0, 0, i, 0, 3, RGB(0, 0, 255));
    cube.line(i, 3, 0, i, 3, 3, RGB(0, 0, 255));
    cube.line(i, 0, 3, i, 3, 3, RGB(0, 0, 255));
    delay(de);
  }

  for(int i = 3; i > 0; i--){
    cube.all(BLACK);
    cube.line(i, 0, 0, i, 3, 0, RGB(50, 255, 255));
    cube.line(i, 0, 0, i, 0, 3, RGB(50, 255, 255));
    cube.line(i, 3, 0, i, 3, 3, RGB(50, 255, 255));
    cube.line(i, 0, 3, i, 3, 3, RGB(50, 255, 255));
    delay(de);
  }

  for(int i = 0; i < 4; i++){
    cube.all(BLACK);
    cube.line(0, 0, i, 3, 0, i, RGB(255, 255, 0));
    cube.line(0, 0, i, 0, 3, i, RGB(255, 255, 0));
    cube.line(3, 0, i, 3, 3, i, RGB(255, 255, 0));
    cube.line(0, 3, i, 3, 3, i, RGB(255, 255, 0));
    delay(de);
  }

  for(int i = 3; i > 0; i--){
    cube.all(BLACK);
    cube.line(0, 0, i, 3, 0, i, RGB(255, 255, 255));
    cube.line(0, 0, i, 0, 3, i, RGB(255, 255, 255));
    cube.line(3, 0, i, 3, 3, i, RGB(255, 255, 255));
    cube.line(0, 3, i, 3, 3, i, RGB(255, 255, 255));
    delay(de);
  }

}

void RandomColours(int i){
  xPos = random(4);
  yPos = random(4);
  zPos = random(4);
  rr = random(0, 2) * 255;
  gg = random(0, 2) * 255;
  bb = random(0, 2) * 255;
  
  cube.set(xPos, yPos, zPos, RGB(rr, gg, bb));
  delay(i);
}
