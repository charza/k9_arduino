/*
 * k9_arduino_ps2.ino
 * ~~~~~~~~~~~~~~
 * Version: ...Um... FIRST!
 *
 */
 
#include <PS2X_lib.h>

PS2X ps2wl;
int error = 0; 
byte type = 0;
byte vibrate = 0;

static const boolean PRESSURE                = false;
static const boolean VIBE                    = false;
static const byte PIN_INPUT_CLOCK            = 13;
static const byte PIN_INPUT_COMMAND          = 10;
static const byte PIN_INPUT_ATTENTION        = 11;
static const byte PIN_INPUT_PRESSURE         = 12;
static const byte PIN_DRIVE1                 = 10;
static const byte PIN_DRIVE2                 = 09;
static const byte PIN_DRIVE2                 = 07;
static const byte PIN_DRIVE2                 = 06;

void setup(void) {
  Serial.begin(38400);
// PIN MODES 4 PS2 ARE SETUP IN config_gamepad(), LOL!
//  pinMode(PIN_INPUT_CLOCK, INPUT);
//  pinMode(PIN_INPUT_COMMAND, INPUT);
//  pinMode(PIN_INPUT_ATTENTION, INPUT);
//  pinMode(PIN_INPUT_DATA, INPUT);
// PINS FOR SERVOS:
  pinMode(PIN_DRIVE1,OUTPUT);
  pinMode(PIN_DRIVE2,OUTPUT);
  pinMode(PIN_DRIVE3,OUTPUT);
  pinMode(PIN_DRIVE4,OUTPUT);
  error = ps2wl.config_gamepad(PIN_INPUT_CLOCK,
                              PIN_INPUT_COMMAND,
                              PIN_INPUT_ATTENTION,
                              PIN_INPUT_DATA,
                              PRESSURE, VIBE);
}
void loop(void) {
//  long timeNow = millis();

  ps2wl.read_gamepad();
  if(ps2wl.ButtonPressed(PSB_PAD_UP) && ps2wl.ButtonPressed(PSB_PAD_TRIANGLE){
    forward();
  }
  else if(ps2wl.ButtonPressed(PSB_PAD_DOWN) && ps2wl.ButtonPressed(PSB_PAD_CROSS){
    back();
  }
  else if(ps2wl.ButtonPressed(PSB_PAD_DOWN) && ps2wl.ButtonPressed(PSB_PAD_TRIANGLE){
    left();
  }
  else if(ps2wl.ButtonPressed(PSB_PAD_UP) && ps2wl.ButtonPressed(PSB_PAD_CROSS){
    right();
  }
  else{
    hault();
  }
}
void forward(void){
  digitalWrite(PIN_DRIVE1,HIGH);
  digitalWrite(PIN_DRIVE2,LOW);
  digitalWrite(PIN_DRIVE3,HIGH);
  digitalWrite(PIN_DRIVE4,LOW);
}
void back(void){
  digitalWrite(PIN_DRIVE1,LOW);
  digitalWrite(PIN_DRIVE2,HIGH);
  digitalWrite(PIN_DRIVE3,LOW);
  digitalWrite(PIN_DRIVE4,HIGH);
}
void left(void){
  digitalWrite(PIN_DRIVE1,HIGH);
  digitalWrite(PIN_DRIVE2,LOW);
  digitalWrite(PIN_DRIVE3,LOW);
  digitalWrite(PIN_DRIVE4,HIGH);
}
void right(void){
  digitalWrite(PIN_DRIVE1,LOW);
  digitalWrite(PIN_DRIVE2,HIGH);
  digitalWrite(PIN_DRIVE3,HIGH);
  digitalWrite(PIN_DRIVE4,LOW);
}
void hault(void){
  digitalWrite(PIN_DRIVE1,LOW);
  digitalWrite(PIN_DRIVE2,LOW);
  digitalWrite(PIN_DRIVE3,LOW);
  digitalWrite(PIN_DRIVE4,LOW);
}
