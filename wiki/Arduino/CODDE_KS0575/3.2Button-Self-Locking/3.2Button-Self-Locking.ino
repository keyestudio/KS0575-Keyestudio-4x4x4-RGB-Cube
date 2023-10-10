#define ButtonPin 6 //Define a button pin
int value = 0;      //Define a value to determine the button value

void setup() {
  //Initialize the serial port and set the baud rate to 9600
  Serial.begin(9600);
  //Set the pin mode to input
  pinMode(ButtonPin,INPUT);
}

void loop() {
  //Define a value to store the button value
  int ReadValue = digitalRead(ButtonPin); 
  //Determine whether the value is pressed
  if (ReadValue == 0) {
    //eliminate the button jitter
    delay(10);  
    if (ReadValue == 0) {
      value = !value;
      Serial.print("The current status of the button is : ");
      Serial.println(value);
    }
    //Again, determine whether the button is still pressed
    //Pressed: execute the loop; Released: exit the loop to run next code
    while (digitalRead(ButtonPin) == 0); 
  }
}
