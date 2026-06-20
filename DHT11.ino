#include <DHT.h>

#define DHTPIN 2       // DHT11 data pin
#define DHTTYPE DHT11  // Sensor type

#define BUTTON_PIN 3   // Push button pin
#define LED_PIN 4      // LED pin

DHT dht(DHTPIN, DHTTYPE);

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  // Read temperature and humidity
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print("°C  |  Humidity: ");
    Serial.print(hum);
    Serial.println("%");
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }

  // Button handling
  bool buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50);  // debounce
    ledState = !ledState;  // toggle LED
    digitalWrite(LED_PIN, ledState);
  }
  lastButtonState = buttonState;

  delay(2000);  // Delay between readings
}
