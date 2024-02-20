//Two buttons and 2 LED
//button1 toggle LED1 as default. When button 2 is pressed down, button 1 instead toggles LED2.

//constants
const byte buttonPinRed = 2;
const byte buttonPinBlue = 3;
const byte ledPinRed = 10;
const byte ledPinBlue = 9;


const unsigned long debounceDelay = 50;

//variables
byte ledStateRed = LOW;   //For remembering the last state
byte ledStateBlue = LOW;  //   -||-
byte lastButtonState = LOW;
byte buttonState = LOW;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(buttonPinRed, INPUT);
  pinMode(buttonPinBlue, INPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
}

void loop() {
  byte reading = digitalRead(buttonPinRed);

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
