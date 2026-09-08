// MineVision - HC-SR04 Ultrasonic Sensor Test
// ESP32-12E DevKit

#define TRIG_PIN 5    // D1
#define ECHO_PIN 4    // D2

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIG_PIN, LOW);

  Serial.println("MineVision HC-SR04 Test Started");
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Measure echo time
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // Calculate distance
  float distance = duration * 0.0343 / 2;

  // Display result
  if (duration == 0) {
    Serial.println("No object detected");
  }
  else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500);
}
