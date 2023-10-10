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
  //Define a value to store the read button value
  int ReadValue = digitalRead(ButtonPin); 
  //Determine whether the button is pressed
  if (ReadValue == 0) {
    //Eliminate the button jitter
    delay(10);  
    if (ReadValue == 0) {
      value = !value;
      //Ternary arithmetic
      //If count is greater than 3, count = 0
      //If count is smaller than 3, count + 1
      count = count > 3 ? 0 : count + 1;
      Serial.print("The current status of the button is : ");
      Serial.println(value);
      Serial.println(count);
    }
    //Again, determine whether the button is still pressed
    //Pressed: execute the loop; Released: exit the loop to run next code
    while (digitalRead(ButtonPin) == 0); 
  }
  if (count == 0) {
    cube.all(RED);
  }
  else if (count == 1){
    cube.all(BLUE);
  }
  else if (count == 2){
    cube.all(GREEN);
  }
  else if (count == 3){
    cube.all(WHITE);
  }
  else if (count == 4){
    cube.all(BLACK);
  }
}
