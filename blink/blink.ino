#define LED_PIN 48


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("HIGH");
  digitalWrite(LED_PIN, HIGH);
  delay(500);

  Serial.println("LOW");
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
