//Lektion 27/2 - Övningsuppgift 1

//Sätt upp en krets med en ljussensor
//I arduino koden skicka en läsning från ljussensorn en gång i sekunden över serieporten som rådata (inte text) med Serial.write()
//Skriv ett C++ program som läser från serieporten i en loop och skriver ut de värden den får


const byte inputPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
}

void loop() {
  unsigned int reading = analogRead(inputPin);
  Serial.write(reading);
  delay(1000);
}

