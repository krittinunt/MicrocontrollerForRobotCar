int const BUZZER = 4;

int const IR_SENSOR_L = 0;
int const IR_SENSOR_C = 1;
int const IR_SENSOR_R = 2;

// EN -> speed, Direction control -> HIGH = Forward, LOW = Reverse
// motor A
int const MOTOR_A_EN = 10;
int const MOTOR_A_DIR = 12;

// motor B
int const MOTOR_B_EN = 11;
int const MOTOR_B_DIR = 13;

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

  pinMode(MOTOR_A_EN, OUTPUT);
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_B_EN, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);

  // config digital pin
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_EN, 0);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_EN, 0);

  // beep beep
  digitalWrite(BUZZER, HIGH);
  delay(70);
  digitalWrite(BUZZER, LOW);
  delay(50);
  digitalWrite(BUZZER, HIGH);
  delay(70);
  digitalWrite(BUZZER, LOW);

  // Print to serial
  //Serial.println();
  //Serial.println();
  //Serial.println("SRTC Robot ready");
  //Serial.println("============================================");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  ir_sensor_l_value = analogRead(IR_SENSOR_L);
  ir_sensor_c_value = analogRead(IR_SENSOR_C);
  ir_sensor_r_value = analogRead(IR_SENSOR_R);
  
  //Serial.print("IR Sensor value : ");
  //Serial.print(ir_sensor_l_value);
  //Serial.print(',');
  //Serial.print(ir_sensor_c_value);
  //Serial.print(',');
  //Serial.println(ir_sensor_r_value);

  // motor A Forward
  //digitalWrite(MOTOR_A_DIR, HIGH);
  //analogWrite(MOTOR_A_EN, 64);
  //delay(5000);

  // motor A stop
  //analogWrite(MOTOR_A_EN, 0);
  //delay(2000);

  // motor A Reverse
  //digitalWrite(MOTOR_A_DIR, LOW);
  //analogWrite(MOTOR_A_EN, 64);
  //delay(5000);

  // motor A stop
  //analogWrite(MOTOR_A_EN, 0);
  //delay(2000);

  //delay(200);

  // Drive two motors
  //digitalWrite(MOTOR_A_DIR, HIGH);
  //digitalWrite(MOTOR_B_DIR, HIGH);
  //analogWrite(MOTOR_A_EN, 64);
  //analogWrite(MOTOR_B_EN, 64);
  //delay(5000);

  // Car Forward
  //digitalWrite(MOTOR_A_DIR, HIGH);
  //digitalWrite(MOTOR_B_DIR, LOW);
  //analogWrite(MOTOR_A_EN, 64);
  //analogWrite(MOTOR_B_EN, 64);
  //delay(5000);

  // Car Reverse
  //digitalWrite(MOTOR_A_DIR, LOW);
  //digitalWrite(MOTOR_B_DIR, HIGH);
  //analogWrite(MOTOR_A_EN, 64);
  //analogWrite(MOTOR_B_EN, 64);
  //delay(5000);

  // Car Turn Left Half Drive
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_A_EN, 0);
  analogWrite(MOTOR_B_EN, 64);
  delay(5000);

  // Stop two motors
  analogWrite(MOTOR_A_EN, 0);
  analogWrite(MOTOR_B_EN, 0);
  delay(2000);
}
