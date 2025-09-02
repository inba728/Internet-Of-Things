// C++ code
//
    
int sensorValue = 0;
const int threshold = 800; 

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.print("Soil Moisture Level: ");
  Serial.println(sensorValue);

  if (sensorValue < threshold) {
    digitalWrite(5, LOW);
    Serial.println("Soil is DRY - LED ON");
  } else {

    digitalWrite(5, HIGH);
    Serial.println("Soil is WET - LED OFF");
  }
  delay(1000); 
}

