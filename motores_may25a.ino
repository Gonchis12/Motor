const int pinIN3 = 7;   // Dirección motor
const int pinIN4 = 8;   // Dirección opuesta
const int pinENB = 9;   // PWM (control de velocidad)

void setup() {
  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(pinENB, OUTPUT);
}

void loop() {
  // Sentido horario (derecha)
  digitalWrite(pinIN3, HIGH);  // IN3 = 1
  digitalWrite(pinIN4, LOW);   // IN4 = 0

  // Velocidad máxima
  analogWrite(pinENB, 255);    // 0–255 (255 = duty-cycle 100 %)
}
