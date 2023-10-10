#define ButtonPin 6 //Define the button pin

void setup() {
  //Initialize the serial port and set to 9600
  Serial.begin(9600);
  //Set the pin to input mode
  pinMode(ButtonPin,INPUT);
}

void loop() {
  //Define a value to store the read button value
  int ReadValue = digitalRead(ButtonPin); 
  //Print the value on the serial port
  Serial.print("The current status of the button is : ");
  Serial.println(ReadValue);
  delay(500);
}
