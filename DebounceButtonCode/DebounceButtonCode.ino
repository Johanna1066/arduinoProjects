//debouncing code for button 


//constants
const byte buttonPin = 2;
const byte ledPin = 13;

const unsigned long debounceDelay = 50;

//variables
byte ledState = LOW;          //For remembering the last state
byte lastButtonState = LOW;   //   -||-
byte buttonState = LOW; 
unsigned long lastDebounceTime = 0;

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  byte reading = digitalRead(buttonPin);

  if(reading != lastButtonState)                      //If button state has changed
  {
    lastDebounceTime = millis();                      //get time in ms
  }

  if((millis() - lastDebounceTime) > debounceDelay)   //Has it been more than 50 ms
  {
    if(reading != buttonState)
    {
    buttonState = reading;

      if(HIGH == buttonState)                         //If you write this way you can't
      {                                               //misstakenly use = instead of ==
        ledState = !ledState;                         //Easy way to flip a byte (bool)
        digitalWrite(ledPin, ledState);
      }
    }
  }

  lastButtonState = reading;                          //to catch the bounces both ways (HIGH <-> LOW)
}
