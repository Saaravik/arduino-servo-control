#include <Arduino.h>
#include <Servo.h>

constexpr uint8_t SERVO_PIN = 9;
constexpr int SERVO_MIN_PULSE_US = 1000;
constexpr int SERVO_MAX_PULSE_US = 2000;
constexpr int MAX_ANGLE = 180;
constexpr int ANGLE_STEP = 10;
constexpr unsigned long STEP_INTERVAL_MS = 1000;

Servo servo;
int angle = 0;

void setup() {
	servo.attach(SERVO_PIN, SERVO_MIN_PULSE_US, SERVO_MAX_PULSE_US);
	servo.write(angle);
}

void loop() {
	delay(STEP_INTERVAL_MS);

	angle += ANGLE_STEP;
	if (angle > MAX_ANGLE) {
		angle = 0;
	}

	servo.write(angle);
}
