/*
 JSN20_MotorTest
 Turns both motors in the forward direction for 1000 milliseconds and then stops motors for 1500 milliseconds.
 After that, it turns motors in opposite direction for 1000 milliseconds and finally stops motors for 1500 milliseconds.
*/

#define MotLP  6
#define MotLN  7
#define MotRP  8
#define MotRN  9

#define EnL    3
#define EnR    5

void setup()
{
  pinMode(MotRP, OUTPUT);
  pinMode(MotRN, OUTPUT);
  pinMode(MotLP, OUTPUT);
  pinMode(MotLN, OUTPUT);
  pinMode(EnR, OUTPUT);
  pinMode(EnL, OUTPUT);
}

void loop()
{
  /*Turns both motors in the forward direction*/
  digitalWrite(MotLP, HIGH);
  digitalWrite(MotLN, LOW);
  digitalWrite(EnL, HIGH);

  digitalWrite(MotRP, LOW);
  digitalWrite(MotRN, HIGH);
  digitalWrite(EnR, HIGH);
  delay(1000);

  /*Stops both motors*/
  digitalWrite(EnR, LOW);
  digitalWrite(EnL, LOW);
  delay(1500);

  /*Turns both motors in the backward direction*/
  digitalWrite(MotLP, LOW);
  digitalWrite(MotLN, HIGH);
  digitalWrite(EnL, HIGH);

  digitalWrite(MotRP, HIGH);
  digitalWrite(MotRN, LOW);
  digitalWrite(EnR, HIGH);
  delay(1000);

  /*Stops both motors*/
  digitalWrite(EnR, LOW);
  digitalWrite(EnL, LOW);
  delay(1500);
}
