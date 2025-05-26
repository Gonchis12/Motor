const byte IN3 = 7;      // Dirección
const byte IN4 = 8;      // Dirección opuesta
const byte ENB = 9;      // PWM (~)

const byte PASO  = 5;      // Incremento/decremento de PWM
const int  T_DELAY = 20;   // ms entre pasos (rampa suave)
const int  T_MAX   = 5000; // **nuevo: 5 s a velocidad máxima

void setup() {
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Sentido antihorario (“izquierda”); invierte HIGH/LOW si quieres el otro
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void loop() {
  //Aceleración 
  for (int vel = 0; vel <= 255; vel += PASO) {
    analogWrite(ENB, vel);
    delay(T_DELAY);
  }

  delay(T_MAX);  // Mantiene velocidad máxima 5 s

  // Desaceleración 
  for (int vel = 255; vel >= 0; vel -= PASO) {
    analogWrite(ENB, vel);
    delay(T_DELAY);
  }

  delay(500);    // Medio segundo detenido antes de repetir
}
