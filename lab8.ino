#define TRIG 9 // Ultrasonic sensor TRIG pin -> Arduino pin 9
#define ECHO 10 // Ultrasonic sensor ECHO pin -> Arduino pin 10

long duration; // Time taken for sound to travel (in microseconds)
float distance; // Distance measured (in cm)
float tankDepth = 15.0; // Total depth of tank in cm
float waterLevel; // Final water level inside the tank

void setup() {
  Serial.begin(9600); // Start Serial Monitor at 9600 baud rate
  pinMode(TRIG, OUTPUT); // TRIG pin as output
  pinMode(ECHO, INPUT); // ECHO pin as input
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure echo time
  duration = pulseIn(ECHO, HIGH); // pulseIn() measures how long the ECHO pin stays HIGH
  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  // Calculate water level
  waterLevel = tankDepth - distance;

  if (waterLevel < 0) waterLevel = 0; // Prevents negative values (when sensor detects wrongly)
  if (waterLevel > tankDepth) waterLevel = tankDepth; // Ensures water level never exceeds tank depth.

  // Print results
  Serial.print("Water Level: ");
  Serial.print(waterLevel);
  Serial.print(" cm / Depth: ");
  Serial.print(tankDepth);
  Serial.println(" cm");

  delay(1000); // update every second
}
