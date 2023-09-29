#define MotLP       6
#define MotLN       7
#define MotRP       8
#define MotRN       9

#define LeftPwm     3
#define RightPwm    5

enum Dir
{
  Forward = 0,
  Backward = 1
};

void setup()
{
  /*Set same frequency for LeftPwm (Pin 3) and RightPwm (pin 5) to get same performance in both motors*/
  TCCR0B = TCCR0B & B11111000 | B00000011; // for PWM frequency of 976.56 Hz to RightPwm pin (The DEFAULT)
  TCCR2B = TCCR2B & B11111000 | B00000011; // for PWM frequency of 980.39 Hz to LeftPwm pin
  pinMode(MotRP, OUTPUT);
  pinMode(MotRN, OUTPUT);
  pinMode(MotLP, OUTPUT);
  pinMode(MotLN, OUTPUT);
}

void loop()
{
  /*Turns both motors in forward direction*/
  moveRobot(Forward, Forward, 48, 48);
  delay(2200);
  stopRobot();
  delay(2000);
  /*Turns both motors in backward direction*/
  moveRobot(Backward, Backward, 192, 192);
  delay(1600);
  stopRobot();
  delay(2000);
  /*Turns motors in the opposite direction of each other*/
  moveRobot(Forward, Backward, 64, 64);
  delay(900);
  stopRobot();
  delay(2000);
}

void moveRobot(Dir leftDirection, Dir rightDirection, int leftPwmValue, int rightPwmValue)
{
  if (leftDirection == Forward)
  {
    digitalWrite(MotLP, HIGH);
    digitalWrite(MotLN, LOW);
  }
  else if (leftDirection == Backward)
  {
    digitalWrite(MotLP, LOW);
    digitalWrite(MotLN, HIGH);
  }
  analogWrite(LeftPwm, leftPwmValue);

  if (rightDirection == Forward)
  {
    digitalWrite(MotRP, LOW);
    digitalWrite(MotRN, HIGH);
  }
  else if (rightDirection == Backward)
  {
    digitalWrite(MotRP, HIGH);
    digitalWrite(MotRN, LOW);
  }
  analogWrite(RightPwm, rightPwmValue);
}
void stopRobot()
{
  /*Stop left motor*/
  digitalWrite(MotLP, LOW);
  digitalWrite(MotLN, LOW);
  /*Stop right motor*/
  digitalWrite(MotRP, LOW);
  digitalWrite(MotRN, LOW);
}
