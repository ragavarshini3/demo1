// Rotary Encoder Module Example (HW-040)
// Wiring: CLK = D5, DT = D4, SW = D3
// VCC to 5V, GND to GND

#define CLK 5  // Pin for CLK
#define DT 4   // Pin for DT
#define SW 3   // Pin for Button (SW)

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";
unsigned long lastButtonPress = 0;

void setup() {
  // Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Setup Serial Monitor
  Serial.begin(9600);

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);
}

void loop() {
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If the state of CLK has changed, a pulse occurred
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {
    // If DT state is different from CLK, rotation is CW
    if (digitalRead(DT) != currentStateCLK) {
      counter++;
      currentDir = "CW";
    } else {
      // Otherwise rotation is CCW
      counter--;
      currentDir = "CCW";
    }
    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);
  }

  // Remember the last CLK state
  lastStateCLK = currentStateCLK;

  // Read the button state
  if (digitalRead(SW) == LOW) {
    // Simple debounce
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed - Counter reset");
      counter = 0; // Reset counter if needed
    }
    lastButtonPress = millis();
  }
}
