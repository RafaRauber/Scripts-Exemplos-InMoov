/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo servo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
int maximo = 120;
int minimo = 100;
int velocidade = 7;


void setup() {
  servo2.attach(9);  // attaches the servo on pin 9 to the servo object


}

void loop() {

for(int i=0; i<=10; i+=1){
 for (pos = minimo; pos <= maximo; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(velocidade);   // waits 15 ms for the servo to reach the position
     
  }
  for (pos = maximo; pos >= minimo; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(velocidade);   // waits 15 ms for the servo to reach the position
  }
  
}
// aqui eu posiciono depois de várias aberturas, a boca fechada.
 servo2.write(minimo);
 delay(2000);
  
}
