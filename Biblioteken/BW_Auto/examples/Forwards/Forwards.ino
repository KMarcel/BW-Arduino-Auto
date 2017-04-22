#include <BW_Auto.h>
int Pins[8] = {3, 4, 5, 6, 8, 9, 10, 11};
BW_Auto Auto(Pins, 1, 2, 2000);

void setup() {
  Auto.setNewSpeed(2000);
}

void loop() {
  Auto.distanz();
  Auto.Forwards();
}