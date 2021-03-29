int const BUZZER = 4;

int const IR_SENSOR_L = 0;
int const IR_SENSOR_C = 1;
int const IR_SENSOR_R = 2;

// EN -> speed, Direction control -> HIGH = Forward, LOW = Reverse
// motor A
int const MOTOR_A_EN = 10;
int const MOTOR_A_DIR = 12;
int const MOTOR_A_SENSOR_A = 18;
int const MOTOR_A_SENSOR_B = 19;

// motor B
int const MOTOR_B_EN = 11;
int const MOTOR_B_DIR = 13;

float ir_sensor_l_value = 0.0;
float ir_sensor_c_value = 0.0;
float ir_sensor_r_value = 0.0;

int i;
double motor_A_pos = 0;

void motor_A_encoder_A(void);
void motor_A_encoder_B(void);

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

  pinMode(MOTOR_A_SENSOR_A, INPUT_PULLUP);
  pinMode(MOTOR_A_SENSOR_B, INPUT_PULLUP);

  // config digital pin
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_EN, 0);

  digitalWrite(MOTOR_A_SENSOR_A, HIGH);
  digitalWrite(MOTOR_A_SENSOR_B, HIGH);

  // Interrupt
  attachInterrupt(digitalPinToInterrupt(MOTOR_A_SENSOR_A), motor_A_encoder_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_A_SENSOR_B), motor_A_encoder_B, CHANGE);

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

  motor_A_pos = 0;
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_EN, 64);
  while(motor_A_pos >= -800) delay(1);
  Serial.println(motor_A_pos);
  analogWrite(MOTOR_A_EN, 00);
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  delay(8000);
}

void motor_A_encoder_A(void)
{
  if (digitalRead(MOTOR_A_SENSOR_A) == HIGH)
  {
    if (digitalRead(MOTOR_A_SENSOR_B) == LOW) motor_A_pos++; // CW
    else motor_A_pos--; // CCW
  }
  else
  {
    if (digitalRead(MOTOR_A_SENSOR_B) == HIGH) motor_A_pos++; // CW
    else motor_A_pos--; // CCW
  }
}

void motor_A_encoder_B(void)
{
  if (digitalRead(MOTOR_A_SENSOR_B) == HIGH)
  {
    if (digitalRead(MOTOR_A_SENSOR_A) == HIGH) motor_A_pos++; // CW
    else motor_A_pos--; // CCW
  }
  else
  {
    if (digitalRead(MOTOR_A_SENSOR_A) == LOW) motor_A_pos++; // CW
    else motor_A_pos--; // CCW
  }
}
