#include <Schrittmotor.h>
byte *PinOut = {0, 1, 2, 3, 8, 9, 10, 11};
Schrittmotor Motoren(PinOut);

void setup() {
  Motoren.setNewSpeed(3000);
}

void loop() {
    Motoren.Forwards();
}
