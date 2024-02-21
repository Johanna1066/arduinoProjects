//Meassure time while photoresistor is dark
//then blink led with the time meassured

//Constrants
const byte ledPin = 13;
const byte photoPin = A0;

//variables
//byte ledState = LOW;
bool done = false;
byte photoPinState = LOW;
byte lastPhotoPinState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(photoPin, INPUT);
}

void loop() {

  static unsigned long goingDarkTime = 0;
  static unsigned long goingLightTime = 0;
  static unsigned long LEDtime = 0;

  unsigned long reading = analogRead(photoPin);

  if (done) {
    if ((LEDtime + goingLightTime) > millis()) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
      done = false;
    }
  } else {
    if (reading < 512)  //Calculate time
    {
      photoPinState = LOW;
      if (lastPhotoPinState != photoPinState) {
        goingDarkTime = millis();
      }
    } else {
      photoPinState = HIGH;
      if (lastPhotoPinState != photoPinState) {
        goingLightTime = millis();
        done = true;
        LEDtime = goingLightTime - goingDarkTime;
      }
    }
  }
  lastPhotoPinState = photoPinState;
}
