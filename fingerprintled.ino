const int greenLED = 7;
const int redLED = 8;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  digitalWrite(greenLED, HIGH);  // Green ON
  digitalWrite(redLED, LOW);     // Red OFF
  delay(1000);

  digitalWrite(greenLED, LOW);   // Green OFF
  digitalWrite(redLED, HIGH);    // Red ON
  delay(1000);
}
