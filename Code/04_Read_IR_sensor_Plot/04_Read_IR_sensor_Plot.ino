int const BUZZER = 4;

int const IR_SENSOR_L = 0;
int const IR_SENSOR_C = 1;
int const IR_SENSOR_R = 2;

float ir_sensor_l_value = 0.0;
float ir_sensor_c_value = 0.0;
float ir_sensor_r_value = 0.0;

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
  //Serial.println("SRTC Robot ready");
  //Serial.println("============================================");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  ir_sensor_l_value = analogRead(IR_SENSOR_L);
  ir_sensor_c_value = analogRead(IR_SENSOR_C);
  ir_sensor_r_value = analogRead(IR_SENSOR_R);
  
  //Serial.print("IR Sensor value : ");
  Serial.print(ir_sensor_l_value);
  Serial.print(',');
  Serial.print(ir_sensor_c_value);
  Serial.print(',');
  Serial.println(ir_sensor_r_value);

  delay(200);
}
