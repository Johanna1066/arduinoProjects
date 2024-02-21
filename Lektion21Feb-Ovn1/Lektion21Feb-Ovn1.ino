//Buttonpress lights up RGB-LED in random colour


//Cnstants
const byte RGBRed = 9;
const byte RGBGreen = 10;
const byte RGBBlue = 11;

const byte buttonPin = 2;

const unsigned long debounceDelay = 50;

//Variables
byte buttonState = LOW;
byte lastButtonState = LOW;


void setup() {
  pinMode(RGBRed, OUTPUT);
  pinMode(RGBGreen, OUTPUT);
  pinMode(RGBBlue, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  static unsigned long lastDebounceTime = 0;

  byte reading = digitalRead(buttonPin);

  if (reading != lastButtonState)  //If button state has changed
  {
    lastDebounceTime = millis();  //get time in ms
  }

  if ((millis() - lastDebounceTime) > debounceDelay)  //Has it been more than 50 ms
  {
    if (reading != buttonState) {
      buttonState = reading;

      if (HIGH == buttonState)  //If you write this way you can't
      {                         //misstakenly use = instead of ==
        long numRed = random(0,255);
        long numGreen = random(0,255);
        long numBlue = random(0,255);

        analogWrite(RGBRed, (numRed));
        analogWrite(RGBGreen, (numGreen));
        analogWrite(RGBBlue, (numBlue));
      }
    }
  }
  lastButtonState = reading;  //to catch the bounces both ways (HIGH <-> LOW)
}
