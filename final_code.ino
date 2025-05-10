#include <AFMotor.h>

char command = 'S';         // Default command (Stop)
char lastCommand = '\0';    // To detect changes

// Create motor objects
AF_DCMotor motor1(1); // M1
AF_DCMotor motor2(2); // M2
AF_DCMotor motor3(3); // M3
AF_DCMotor motor4(4); // M4

void setup() {
  Serial.begin(9600);  // Bluetooth works over Serial

  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

   void loop() {
   if (Serial.available()) {
   char incoming = Serial.read();

// Ignore newline or carriage return
  if (incoming == '\n' || incoming == '\r') {
   return;
}

// Accept only valid commands
  if (incoming == 'M' || incoming == 'n' || incoming == 'X' || incoming == 'Y' || incoming == 'S') {
   command = incoming;

// Execute if new command or it's 'S' (stop)
  if (command != lastCommand || command=='S') {
  lastCommand = command;

  Serial.print("Executing Command: ");
  Serial.println(command);

  if (command == 'M') forward();
  else if (command == 'n') back();
  else if (command == 'X') left();
  else if (command == 'Y') right();
  else if (command == 'S') Stop();
}
}
}

delay(5); // Small delay for stability
}


// Movement functions
void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void back() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void left() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void right() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

