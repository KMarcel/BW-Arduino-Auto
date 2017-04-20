#include <Schrittmotor.h>

Schrittmotor Motoren(0, 1, 2, 3, 8, 9, 10, 11);

void setup() {
  Motoren.setNewSpeed(3000);
}

void loop() {
    Motoren.Forwards();
}
