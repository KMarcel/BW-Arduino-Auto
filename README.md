# Arduino Auto

![c5314cb9-837c-4445-99a3-fc61a4d38c56](https://cloud.githubusercontent.com/assets/21289932/25248952/6044145a-2610-11e7-8672-9535b41763db.jpg)


## Selbst erstellte Library Schrittmotor

### Einbinden der Library
Einbinden der Library in den Arduino Kopf
```sh
#include <BW_Auto.h>
```
### Pins
![asdasda](https://cloud.githubusercontent.com/assets/21289932/25406892/9b9c42b0-2a08-11e7-9c41-8f75b44c1005.png)
### Schrittmotor Funktionen

#### Konstruktor 

 ```Arduino
int Pins[8] = {Pin 1, Pin 2, Pin 3, Pin 4, Pin 5, Pin 6, Pin 7, Pin 8};
BW_Auto <Objektname>(Pins);
```
`````
BW_Auto      = heißt die Klasse die ein neues Objekt erzeugen soll
Objektname        = das ist der Objektname dieser kann einen x belibigen namen besitzen
(
  Pins            = Pin Array
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
#### Distanz Messung
 ```Arduino
<Objektname>.distanz(Millis Aktivieren);
```
`````
"Objektname"        = Der Objektname
"."                 = Ruft eine Public (Öffentliche) Funktion der Klasse auf
"distanz"         = Name der Funktion in der Klasse
();
`````
