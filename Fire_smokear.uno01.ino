// Pin Definitions
#define FLAME_SENSOR_PIN 2    // Digital pin for flame sensor
#define SMOKE_SENSOR_PIN A0   // Analog pin for MQ-2 smoke sensor
#define BUZZER_PIN 3          // Buzzer pin
#define LED_PIN 4             // LED pin

// Threshold values
#define SMOKE_THRESHOLD 300   // Adjust based on calibration

void setup() {
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int flameDetected = digitalRead(FLAME_SENSOR_PIN); // 0 = Flame, 1 = No flame
  int smokeValue = analogRead(SMOKE_SENSOR_PIN);     // 0–1023

  Serial.print("Smoke Level: ");
  Serial.println(smokeValue);

  // Fire Detection
  if (flameDetected == LOW) {
    Serial.println("🔥 Fire Detected!");
    alert();
  }
  // Smoke Detection
  else if (smokeValue > SMOKE_THRESHOLD) {
    Serial.println("💨 Smoke Detected!");
    alert();
  }
  // No danger
  else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}

void alert() {
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
}
