#include <Servo.h>

Servo servo;
Servo topServo;

const int x = A0;
const int y = A1;
int servoPos = 180;
int speed = 2;

int xPos = 180;
int xSpeed = 2;

void setup() {
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  servo.write(servoPos);
  topServo.write(xPos);

  servo.attach(9);
  topServo.attach(8);
  Serial.begin(9600);
}

void loop() {
  int xval = analogRead(x);
  int yval = analogRead(y);

  Serial.print("y: ");
  Serial.println(yval);
  Serial.print("x: ");
  Serial.println(xval);

  // only move the joystick if the stick is pushed far
  if (yval > 800) {
    servoPos -= speed; // increase the angle
  } else if (yval < 200) {
    servoPos += speed;
  }

  // for the other servo
  if (xval > 800) {
    xPos += xSpeed; // increase the angle
  } else if (xval < 200) {
    xPos -= xSpeed;
  }

  servoPos = constrain(servoPos, 126, 180);
  xPos = constrain(xPos, 30, 180);

  servo.write(servoPos);
  topServo.write(xPos);

  Serial.print("servoPos: ");
  Serial.println(servoPos);
  Serial.print("xPos: ");
  Serial.println(xPos);

  delay(20);
}
