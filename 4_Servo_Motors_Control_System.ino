#include <Servo.h>

Servo servos[4];
const byte servoPins[4] = {0, 1, 2, 3};
const byte buttonCW = A4;  		  // Clockwise button
const byte buttonCCW = A2;  	  // Counterclockwise button
const byte buttonSelect = A1;   // Servo selector

int angles[4] = {90, 90, 90, 90}; // Initial servo angles
byte selected = 0;  			  // 0–3 = servo#, 4 = all
bool lastSel = HIGH;

void setup() {
  for (byte i = 0; i < 4; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(angles[i]);
  }
  pinMode(buttonCW, INPUT);
  pinMode(buttonCCW, INPUT);
  pinMode(buttonSelect, INPUT);
}

void loop() {
  // Read selector button with edge detection
  bool nowSel = digitalRead(buttonSelect);
  if (lastSel == HIGH && nowSel == LOW) {
    selected = (selected + 1) % 5; // 0–4
  }
  lastSel = nowSel;

  // Check direction buttons
  if (digitalRead(buttonCW) == HIGH) {
    rotateSelected(+1);  // rotate CW
    delay(15);           // control speed
  } else if (digitalRead(buttonCCW) == HIGH) {
    rotateSelected(-1);  // rotate CCW
    delay(15);
  }
}

void rotateSelected(int delta) {
  if (selected < 4) {
    angles[selected] = constrain(angles[selected] + delta, 0, 180);
    servos[selected].write(angles[selected]);
  } else {
    for (byte i = 0; i < 4; i++) {
      angles[i] = constrain(angles[i] + delta, 0, 180);
      servos[i].write(angles[i]);
    }
  }
}
