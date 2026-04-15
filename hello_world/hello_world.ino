void setup() {
  // put your setup code here, to run once:
  // Begin serial comunication
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Word");
  delay(1000);
}
