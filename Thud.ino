int soundSensor=11;

void setup() {
 pinMode(soundSensor,INPUT);
 Serial.begin(9600);
 Serial.println("thud code Started");
}

void loop() {

  if(analogRead(A2)>580){
      tone(8,4000);
      Serial.println(analogRead(A2));
  }
  
  if (Serial.available() > 0) {
    noTone(8);
    Serial.read();
  }
}
