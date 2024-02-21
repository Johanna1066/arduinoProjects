//Two buttons and 2 LED
//button1 will toggle LED1 as default. When button 2 is pressed down, button 1 instead toggles LED2.
//I've only done debouncing for the first button

//constants
const byte buttonPinRed = 2;
const byte buttonPinBlue = 3;
const byte ledPinRed = 10;
const byte ledPinBlue = 9;


const unsigned long debounceDelay = 50;

//variables
byte ledStateRed = LOW;     //For remembering the last state of LED
byte ledStateBlue = LOW;    //   -||-

byte lastButtonState = LOW; //Variables for debouncing of the fisr button
byte buttonState = LOW;     


void setup() {
  pinMode(buttonPinRed, INPUT);
  pinMode(buttonPinBlue, INPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
}


void loop() {
  byte reading = digitalRead(buttonPinRed);

  unsigned long lastDebounceTime = 0;

  if (reading != lastButtonState)  //If red button state has changed
  {
    lastDebounceTime = millis();  //get time in ms
  }

  if ((millis() - lastDebounceTime) > debounceDelay)  //Has it been more than 50 ms
  {
    if (reading != buttonState) {
      buttonState = reading;

      if (HIGH == buttonState) {

        byte reading2 = digitalRead(buttonPinBlue);

        if (reading2 == HIGH) {
          ledStateRed = !ledStateRed;
          digitalWrite(ledPinRed, ledStateRed);
        } else {
          ledStateBlue = !ledStateBlue;
          digitalWrite(ledPinBlue, ledStateBlue);
        }
      }
    }
  }
  lastButtonState = reading;  //to catch the bounces both ways (HIGH <-> LOW)
}
