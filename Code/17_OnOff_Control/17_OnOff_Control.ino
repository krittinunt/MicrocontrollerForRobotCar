int const BUZZER = 4;

int const IR_SENSOR_1 = 0;
int const IR_SENSOR_2 = 1;
int const IR_SENSOR_3 = 2;

// EN -> speed, Direction control -> HIGH = Forward, LOW = Reverse
// motor A
int const MOTOR_A_EN = 10;
int const MOTOR_A_DIR = 12;
int const MOTOR_A_SENSOR_A = 18;
int const MOTOR_A_SENSOR_B = 19;

// motor B
int const MOTOR_B_EN = 11;
int const MOTOR_B_DIR = 13;
int const MOTOR_B_SENSOR_A = 20;
int const MOTOR_B_SENSOR_B = 21;

int i;
double motor_A_pos = 0;
double motor_B_pos = 0;

int const BLACK_COLOR_VALUE = 400;

int left_speed = 0;
int right_speed = 0;

void motor_A_encoder_A(void);
void motor_A_encoder_B(void);
void motor_B_encoder_A(void);
void motor_B_encoder_B(void);

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
  pinMode(MOTOR_B_SENSOR_A, INPUT_PULLUP);
  pinMode(MOTOR_B_SENSOR_B, INPUT_PULLUP);

  // config digital pin
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_EN, 0);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_EN, 0);

  digitalWrite(MOTOR_A_SENSOR_A, HIGH);
  digitalWrite(MOTOR_A_SENSOR_B, HIGH);
  digitalWrite(MOTOR_B_SENSOR_A, HIGH);
  digitalWrite(MOTOR_B_SENSOR_B, HIGH);

  // Interrupt
  //attachInterrupt(digitalPinToInterrupt(MOTOR_A_SENSOR_A), motor_A_encoder_A, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(MOTOR_A_SENSOR_B), motor_A_encoder_B, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(MOTOR_B_SENSOR_A), motor_B_encoder_A, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(MOTOR_B_SENSOR_B), motor_B_encoder_B, CHANGE);

  // beep beep
  digitalWrite(BUZZER, HIGH);
  delay(70);
  digitalWrite(BUZZER, LOW);
  delay(50);
  digitalWrite(BUZZER, HIGH);
  delay(70);
  digitalWrite(BUZZER, LOW);

  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_A_EN, 00);
  analogWrite(MOTOR_B_EN, 00);
}

void loop() {
  // put your main code here, to run repeatedly:

  if( isBlack(IR_SENSOR_1) && isWhite(IR_SENSOR_2) && isWhite(IR_SENSOR_3) )
  {
    left_speed = 0;
    right_speed = 64;
  }
  else if( isBlack(IR_SENSOR_1) && isBlack(IR_SENSOR_2) && isWhite(IR_SENSOR_3) )
  {
    left_speed = 0;
    right_speed = 64;
  }
  else if( isWhite(IR_SENSOR_1) && isBlack(IR_SENSOR_2) && isWhite(IR_SENSOR_3) )
  {
    left_speed = 64;
    right_speed = 64;
  }
  else if( isWhite(IR_SENSOR_1) && isBlack(IR_SENSOR_2) && isBlack(IR_SENSOR_3) )
  {
    left_speed = 64;
    right_speed = 0;
  }
  else if( isWhite(IR_SENSOR_1) && isWhite(IR_SENSOR_2) && isBlack(IR_SENSOR_3) )
  {
    left_speed = 64;
    right_speed = 0;
  }
  else if( isWhite(IR_SENSOR_1) && isWhite(IR_SENSOR_2) && isWhite(IR_SENSOR_3) )
  {
    left_speed = 0;
    right_speed = 0;
  }

  analogWrite(MOTOR_A_EN, left_speed);
  analogWrite(MOTOR_B_EN, right_speed);

  delay(100);
}

bool isBlack(int value)
{
  if (value > BLACK_COLOR_VALUE) return true;
  else return false;
}

bool isWhite(int value)
{
  if (value <= BLACK_COLOR_VALUE) return true;
  else return false;
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

void motor_B_encoder_A(void)
{
  if (digitalRead(MOTOR_B_SENSOR_A) == HIGH)
  {
    if (digitalRead(MOTOR_B_SENSOR_B) == LOW) motor_B_pos++; // CW
    else motor_B_pos--; // CCW
  }
  else
  {
    if (digitalRead(MOTOR_B_SENSOR_B) == HIGH) motor_B_pos++; // CW
    else motor_B_pos--; // CCW
  }
}

void motor_B_encoder_B(void)
{
  if (digitalRead(MOTOR_B_SENSOR_B) == HIGH)
  {
    if (digitalRead(MOTOR_B_SENSOR_A) == HIGH) motor_B_pos++; // CW
    else motor_B_pos--; // CCW
  }
  else
  {
    if (digitalRead(MOTOR_B_SENSOR_A) == LOW) motor_B_pos++; // CW
    else motor_B_pos--; // CCW
  }
}
