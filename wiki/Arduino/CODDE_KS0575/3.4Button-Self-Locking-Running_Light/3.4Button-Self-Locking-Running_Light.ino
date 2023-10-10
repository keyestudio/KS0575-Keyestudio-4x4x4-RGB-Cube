#include "SPI.h"
#include "Cube.h"

#define ButtonPin 6 //Define the button pin

Cube cube;

int value = 0;      //Define a value to determine the button value
int count = 0;      //Define a loop count

void setup() {
    // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud
  //Set the pin mode to input
  pinMode(ButtonPin,INPUT);
}

void loop() {
  //Defien a value to store the button value
  int ReadValue = digitalRead(ButtonPin); 
  //Determine whether the button is pressed
  if (ReadValue == 0) {
    //Eliminate the button jitter
    delay(10);  
    if (ReadValue == 0) {
      value = !value;
      //Accumulate count and cycle it within 0-2
      //Ternary arithmetic
      //If count is greater than 3, count = 0
      //If count is smaller than 3, count + 1
      count = count > 2 ? 0 : count + 1;
      Serial.print("The current status of the button is : ");
      Serial.println(value);
      Serial.println(count);
    }
    //Again, determine whether the button is still pressed
    //Pressed: execute the loop; Released: exit the loop to run next code
    while (digitalRead(ButtonPin) == 0); 
  }
  //When count = 0, water flow light in axis x
  //When count = 1, water flow light in axis y
  //When count = 2, water flow light in axis z
  xaxis(count);
  yaxis(count);
  zaxis(count);

}

//water flow light in axis X
void xaxis(int count){
  int x = 0;
  int y = 0;
  int z = 0;
  //
  if (count == 0) {
    for (int i = 0; i < 4; i++){
      cube.line(x, y, z, x, y , z + 3, YELLOW);
      cube.line(x, y + 1, z, x, y + 1, z + 3, GREEN);
      cube.line(x, y + 2, z, x, y + 2, z + 3, RED);
      cube.line(x, y + 3, z, x, y + 3, z + 3, WHITE);
      x++;
      if(x > 4){
        x = 0;
      }
      delay(200);
    }
    cube.all(BLACK);
  }
}

//water flow light in axis y
void yaxis(int count){
  int x = 0;
  int y = 0;
  int z = 0;
  if(count == 1){
    for (int i = 0; i < 4; i++){
      cube.line(x, y, z, x, y, z + 3, PURPLE);
      cube.line(x + 1, y, z, x + 1, y, z + 3, PINK);
      cube.line(x + 2, y, z, x + 2, y, z + 3, BLUE);
      cube.line(x + 3, y, z, x + 3, y, z + 3, WHITE);
      y++;
      if(y > 4){
        y = 0;
      }
      delay(200);
    }
    cube.all(BLACK);
  }
}

//water flow light in axis z
void zaxis(int count){
  int x = 0;
  int y = 0;
  int z = 0;
  if (count == 2){
    for (int i = 0; i < 4; i++){
      cube.line(x, y, z, x + 3, y, z, BLUE);
      cube.line(x, y + 1, z, x + 3, y + 1, z, RED);
      cube.line(x, y + 2, z, x + 3, y + 2, z, ORANGE);
      cube.line(x, y + 3, z, x + 3, y + 3, z, PURPLE);
      z++;
      if(z > 4){
        z = 0;
      }
      delay(200);
    }
    cube.all(BLACK);
  }
}
