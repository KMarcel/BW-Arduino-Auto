# Arduino Auto


## Selbst erstellte Library Schrittmotor

### Einbinden der Library
Einbinden der Library in den Arduino Kopf
```sh
#include <Schrittmotor.h>
```
### Pins
![test](https://cloud.githubusercontent.com/assets/21289932/25196996/b00b48ec-2542-11e7-8a40-eb81a331f3d4.png)
### Funktionen

#### Konstruktor 
// return nichts
 ```c++
Schrittmotor <Objektname>(Pin 1, Pin 2, Pin 3, Pin 4, Pin 5, Pin 6, Pin 7, Pin 8);
```
`````
Schrittmotor      = heißt die Klasse die ein neues Objekt erzeugen soll
Objektname        = das ist der Objektname dieser kann einen x belibigen namen besitzen
(
  Pin 1,            = Pin "B" vom ersten Schrittmotor
  Pin 2,            = Pin "B Nicht" vom ersten Schrittmotor
  Pin 3,            = Pin "A" vom ersten Schrittmotor
  Pin 4,            = Pin "A Nicht" vom ersten Schrittmotor
  Pin 5,            = Pin "B" vom zweiten Schrittmotor
  Pin 6,            = Pin "B Nicht" vom zweiten Schrittmotor
  Pin 7,            = Pin "A" vom zweiten Schrittmotor
  Pin 8             = Pin "A Nicht" vom zweiten Schrittmotor
 );
`````
 #### Setze Geschwindigkeit
 // return nichts
```c++
<Objektname>.setNewSpeed(Geschwindigkeit);
```
`````
"Objektname"        = Der Objektname
"."                 = Ruft eine Public (Öffentliche) Funktion der Klasse auf
"setNewSpeed"       = Name der Funktion in der Klasse
(
  Geschwindigkeit   = Hier kann man die Geschwindigkeit der Motoren regeln
);
`````

#### Links Fahren auf der Stelle
```c++
<Objektname>.Left();
```
`````
"Objektname"        = Der Objektname
"."                 = Ruft eine Public (Öffentliche) Funktion der Klasse auf
"Left"              = Name der Funktion in der Klasse
();
`````
#### Rechts Fahren auf der Stelle
 
```c++
<Objektname>.Right();
```
`````
"Objektname"        = Der Objektname
"."                 = Ruft eine Public (Öffentliche) Funktion der Klasse auf
"Right"             = Name der Funktion in der Klasse
();
`````
#### Nach Vorne Fahren
 
```c++
<Objektname>.Forwards();
```
`````
"Objektname"        = Der Objektname
"."                 = Ruft eine Public (Öffentliche) Funktion der Klasse auf
"Forwards"          = Name der Funktion in der Klasse
();
`````
#### Nach Hinten Fahren
 
```c++
<Objektname>.Backwards();
```
`````
"Objektname"        = Der Objektname
"."                 = Ruft eine Public (Öffentliche) Funktion der Klasse auf
"Backwards"         = Name der Funktion in der Klasse
();
`````

