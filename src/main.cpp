#include <Arduino.h>
#include <Servo.h>

constexpr uint8_t SERVO_PIN = 9;
constexpr int SERVO_MIN_PULSE_US = 900;
constexpr int SERVO_MAX_PULSE_US = 2100;
constexpr int MIN_ANGLE = 0;
constexpr int MAX_ANGLE = 180;
constexpr int ANGLE_STEP = 10;
constexpr unsigned long STEP_INTERVAL_MS = 1000;

Servo servo;
int angle = MIN_ANGLE;

void setup() {
	servo.attach(SERVO_PIN, SERVO_MIN_PULSE_US, SERVO_MAX_PULSE_US);
	servo.write(angle);
}

void loop() {
	delay(STEP_INTERVAL_MS);

	angle += ANGLE_STEP;
	if (angle > MAX_ANGLE) {
		angle = MIN_ANGLE;
	}

	servo.write(angle);
}
