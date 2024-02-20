//constants
const byte buttonPin = 2;
const byte ledPinRed = 9;
const byte ledPinBlue = 10;
const byte ledPinGreen = 11;

const unsigned long debounceDelay = 50;

//variables
byte lastButtonState = LOW;
byte buttonState = LOW;
unsigned long lastDebounceTime = 0;

int currentColour = 0;  //0=red, 1=blue, 2=green

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
}

void loop() {
  byte reading = digitalRead(buttonPin);

  if (reading != lastButtonState)  //If button state has changed
  {
    lastDebounceTime = millis();  //get time in ms
  }

  if ((millis() - lastDebounceTime) > debounceDelay)  //Has it been more than 50 ms
  {
    if (reading != buttonState) {
      buttonState = reading;

      if (HIGH == buttonState) 
      {                         
        digitalWrite(ledPinRed, LOW);
        digitalWrite(ledPinBlue, LOW);
        digitalWrite(ledPinGreen, LOW);
        if (currentColour == 0) {
          digitalWrite(ledPinRed, HIGH);
        }
        if (currentColour == 1) {
          digitalWrite(ledPinBlue, HIGH);
        }
        if (currentColour == 2) {
          digitalWrite(ledPinGreen, HIGH);
        }

        currentColour = currentColour + 1;
        if (currentColour > 2) {
          currentColour = 0;
        }
      }
    }
  }

  lastButtonState = reading;  //to catch the bounces both ways (HIGH <-> LOW)
}
