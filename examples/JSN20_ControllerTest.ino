#include <PS2X_lib.h> 

PS2X ps2x;
int error = 0;
byte controllerType = 0;
void setup() 
{
  Serial.begin(9600);
  delay(300); 
  error = ps2x.config_gamepad(13, 11, 10, 12, false, false);
  if (error == 0) 
    Serial.println("Found Controller, configured successful.");
  else if (error == 1)
    Serial.println("No controller found, check wiring.");
  else if (error == 2)
    Serial.println("Controller found but not accepting commands.");
  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode,"
    " may not support it.");
  controllerType = ps2x.readType();
  switch (controllerType) {
    case 0:
      Serial.println("Unknown Controller type found.");
      break;
    case 1:
      Serial.println("DualShock Controller found.");
      break;
    case 2:
      Serial.println("GuitarHero Controller found.");
      break;
    case 3:
      Serial.println("Wireless Sony DualShock Controller found.");
      break;
  }
}
void loop() {
  if (error == 0) { 
    ps2x.read_gamepad();
    if (ps2x.Button(PSB_START))                        
      Serial.println("Start is being held");
    if (ps2x.NewButtonState()) {
         if (ps2x.Button(PSB_TRIANGLE))
        Serial.println("Triangle pressed");
    }
    if (ps2x.ButtonPressed(PSB_CIRCLE))                 //will be TRUE if button was JUST pressed
      Serial.println("Circle just pressed");
    if (ps2x.ButtonReleased(PSB_SQUARE))                //will be TRUE if button was JUST released
      Serial.println("Square just released");
    if (ps2x.NewButtonState(PSB_CROSS))                 //will be TRUE if button was JUST pressed OR released
      Serial.println("X just changed");
    if (ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) {   //print stick values if either is TRUE
      Serial.print("Stick Values:");
      Serial.print(ps2x.Analog(PSS_LY), DEC);           //Left stick, Y axis. Other options: LX, RY, RX
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_LX), DEC);
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_RY), DEC);
      Serial.print(",");
      Serial.println(ps2x.Analog(PSS_RX), DEC);
    }
  }
  delay(50);
}
