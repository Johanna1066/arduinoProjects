void setup() {
  Serial.begin(9600);
}

void loop() {
  // Do stuff here
}

void serialEvent() {
    String input = Serial.readString();
    Serial.print("Echo: ");
    Serial.println(input);
}