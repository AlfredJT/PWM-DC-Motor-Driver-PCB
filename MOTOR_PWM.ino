const int motorPin1 = 11;
const int PWM = 100; 

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  analogWrite(motorPin, PWM);
}