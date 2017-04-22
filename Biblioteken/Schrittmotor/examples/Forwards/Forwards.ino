#include <Schrittmotor.h>
int Pins[8] = {3, 4, 5, 6, 8, 9, 10, 11};
Schrittmotor Motoren(Pins);
Sensor Ultraschall(1, 2, 2000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Ultraschall.distanz();
  Motoren.Forwards();
}
