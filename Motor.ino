const int SW_pin = 10; // digital pin connected to switch output
const int X_pin = 1; // analog pin connected to X output
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293

void moveUp (){
  while (analogRead(X_pin)<450){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    Serial.println(analogRead(X_pin));
    Serial.println("Moving Up");
  }
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void moveDown(){
  while (analogRead(X_pin)>550){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    Serial.println(analogRead(X_pin));
    Serial.println("Moving Down");
  }
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  Serial.println(analogRead(X_pin));
  Serial.println("idle");
  if (analogRead(X_pin)<450)
  moveUp();
  else if (analogRead(X_pin)>550)
  moveDown();
  delay(500);
}
