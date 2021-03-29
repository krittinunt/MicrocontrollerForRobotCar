int const BUZZER = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }
  
  // digital pin mode
  pinMode(BUZZER, OUTPUT);

  // beep beep
  digitalWrite(BUZZER, HIGH);
  delay(70);
  digitalWrite(BUZZER, LOW);
  delay(50);
  digitalWrite(BUZZER, HIGH);
  delay(70);
  digitalWrite(BUZZER, LOW);

  // Print to serial
  Serial.println();
  Serial.println();
  Serial.println("SRTC Robot ready");
  Serial.println("============================================");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
