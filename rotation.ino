#include <Stepper.h>
#include <ESP32Servo.h>

Stepper stepper = Stepper(4096, 15,2,0,4);
Servo servo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(15, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(18, OUTPUT);
  stepper.setSpeed(6);
  servo.attach(18);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
    stepper.step(2048);
    servo.write(pos);              // tell servo to go to position in variable 'pos'
  }
  for (pos = 180; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
    stepper.step(2048);
    servo.write(pos);              // tell servo to go to position in variable 'pos'
  }
}
