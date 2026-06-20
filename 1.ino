#define IRSensor 3          // Connect IR sensor DO pin to D3
#define LED_BUILTIN 13      // Internal LED pin

void setup() {
  Serial.begin(9600);               // Start Serial Monitor
  pinMode(IRSensor, INPUT);         // Set IR sensor as input
  pinMode(LED_BUILTIN, OUTPUT);     // Set internal LED as output
}

void loop() {
  int sensorValue = digitalRead(IRSensor);  // Read sensor: 0 = obstacle, 1 = no obstacle

  if (sensorValue == 0) {
    Serial.println("🚧  NotObstacle Detected!");         // Hand or object in front
    digitalWrite(LED_BUILTIN, HIGH);                // Turn ON internal LED
  } else {
    Serial.println("✅ No Obstacle.");               // Nothing in front
    digitalWrite(LED_BUILTIN, LOW);                 // Turn OFF internal LED
  }

  delay(200); // Check every 0.2 seconds
}
