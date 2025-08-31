/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo servo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo servo2;

int pos = 90;
int posi = 100;    // variable to store the servo position
int led = 6;           // the PWM pin the LED is attached to
  int brightness = 255;    // how bright the LED is
  int estado = 0;    // how many points to fade the LED by
  int vermelho = 4;
  int azul = 5;
  int verde = 7;
  int maximo = 120;
  int minimo = 100;
  int velocidade = 7;



void setup() {
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);
  pinMode(vermelho, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  analogWrite(led, brightness);
//digitalWrite(vermelho, LOW); 
  digitalWrite(verde, HIGH);
//  digitalWrite(azul, HIGH);


  
//  digitalWrite(vermelho, HIGH);
 // troca_led(); 
}

void loop() {

 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);   // waits 15 ms for the servo to reach the position
    if (pos == 90){
    delay(1000);
    fade();
    boca();
    }
        
       
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);   // waits 15 ms for the servo to reach the position
  }

  
}

void troca_led(){

if( estado == 1)
  {
  digitalWrite(vermelho, LOW); 
  digitalWrite(verde, LOW);
  digitalWrite(azul, HIGH); // acende o azul
  }

else if( estado == 2)
  {
  digitalWrite(verde, LOW); 
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, HIGH);  // acende o vermelho
  estado = 0;  //zera e volta para a primeira cor, comentar esta linha que quiser que troque para a próxima cor que é a verde.

  }

else if( estado == 3)
  {
  digitalWrite(vermelho, LOW); 
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);  // acende o verde

  estado = 0;
  }
  
 
}

void fade(){

if( brightness <= 0)
  {
  for (brightness = 0; brightness <= 255; brightness += 1){
       analogWrite(led, brightness);
       delay(10);
  }
  estado ++;
  troca_led();
  }

if( brightness >= 255)
  {
  for (brightness = 254; brightness >= 0; brightness -= 1){
       analogWrite(led, brightness);
       delay(10);
       
  }
 
  }  
 
}

void boca(){

for(int i=0; i<=10; i+=1){
 for (posi = minimo; posi <= maximo; posi += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo2.write(posi);              // tell servo to go to position in variable 'pos'
    delay(velocidade);   // waits 15 ms for the servo to reach the position
     
  }
  for (posi = maximo; posi >= minimo; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo2.write(posi);              // tell servo to go to position in variable 'pos'
    delay(velocidade);   // waits 15 ms for the servo to reach the position
  }
  
}
// aqui eu posiciono depois de várias aberturas, a boca fechada.
 servo2.write(minimo);
 delay(500);
 
}
