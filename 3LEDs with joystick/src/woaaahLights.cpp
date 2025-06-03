#include <Arduino.h>

#define JOYSTICK_Y A1
#define JOYSTICK_X A2
#define JOYSTICK_BTN A0
#define LED_RED 6
#define LED_GREEN 10
#define LED_BLUE 11

int joystick_y;
int joystick_x;
int joystick_btn;
int blue_brightness;
int green_brightness;


void setup() {

  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  joystick_btn = analogRead(JOYSTICK_BTN);
  
  joystick_y = analogRead(JOYSTICK_Y);
  Serial.print("jsY value: ");
  Serial.print(joystick_y);

  joystick_x = analogRead(JOYSTICK_X);
  Serial.print(" jsX value: ");
  Serial.print(joystick_y);

  blue_brightness = map(joystick_y, 0, 1023, 0, 255);
  green_brightness = map(joystick_x, 0, 1023, 0, 255);

  analogWrite(LED_BLUE, blue_brightness);
  analogWrite(LED_GREEN, green_brightness);

  Serial.print(" BTN status: ");
  Serial.println(joystick_btn);

  if (joystick_btn < 100) {
    digitalWrite(LED_RED, !digitalRead(LED_RED));
  }

  delay(1);
}
