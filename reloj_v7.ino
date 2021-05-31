#include <Stepper.h>
Stepper myStepper(2048, 8, 10, 9, 11);

#include <Adafruit_NeoPixel.h>
#define PIN 10  // No. de pin conectado
#define NUMPIXELS 36  //Total de leds que se van a ocupar
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(6, 7, 8);
int valorHora;
int valorMinuto;

int inPin = 11; //Button1
int inPin2 = 12;//Button2
int LEDPin=10;
const int stepPin = 3;
const int dirPin = 4;
int vuelta = 200 / 60;
int B_uno_horas;
int B_dos_minuto;
int PsoXSeg = 3;
int StepPin = 3;
const int buttonPin = 12;
const int buttonPin1 = 11;
int buttonState = 1;
int buttonState1 = 0;

void setup() {
  // seconds, minutes, hours, day of the week, day of the month, month, year
  myRTC.setDS1302Time(13, 28, 14, 6, 18, 5, 2021);
  Serial.begin(9600);
  pixels.begin();
  pinMode(buttonPin1, INPUT);
  pinMode(LEDPin, OUTPUT);
  myStepper.setSpeed(2);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  buttonState1 = digitalRead(buttonPin);
  if (buttonState == HIGH) {
        pixels.clear();
    myRTC.hours++;
  
    pixels.show();
    delay(5);
  }
 else if (buttonState == LOW){
   if (myRTC.hours == 1) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 1, 2, 3);
    }
  }
  else if (myRTC.hours == 2) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 4, 5, 6);
    }
  }
  else if (myRTC.hours == 3) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 7, 8, 9);
    }
  }
  else if (myRTC.hours == 4) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 10, 11, 12);
    }
  }
  else if (myRTC.hours == 5) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 13, 14, 15);
    }
  }
  else if (myRTC.hours == 6) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 16, 17, 18);
    }
  }
  else if (myRTC.hours == 7) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 19, 20, 21);
    }
  }
  else if (myRTC.hours == 8) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 22, 23, 24);
    }
  }
  else if (myRTC.hours == 9) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 25, 26, 27);
    }
  }
  else if (myRTC.hours == 10) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 28, 29, 30);
    }
  }
  else if (myRTC.hours == 11) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 31, 32, 33);
    }
  }
  else if (myRTC.hours == 12) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 34, 35, 36);
    }
  }
  else if (myRTC.hours == 13) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 1, 2, 3);
    }
  }
  else if (myRTC.hours == 14) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 4, 5, 6);
    }
  }
  else if (myRTC.hours == 15) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 7, 8, 9);
    }
  }
  else if (myRTC.hours == 16) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 10, 11, 12);
    }

  }
  else if (myRTC.hours == 17) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 13, 14, 15);
    }
  }
  else if (myRTC.hours == 18) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 16, 17, 18);
    }
  }
  else if (myRTC.hours == 19) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 19, 20, 21);
    }
  }
  else if (myRTC.hours == 20) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 22, 23, 24);
    }
  }
  else if (myRTC.hours == 21) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 25, 26, 27);
    }
  }
  else if (myRTC.hours == 22) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 28, 29, 30);
    }
  }
  else if (myRTC.hours == 23) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 31, 32, 33);
    }
  }
  else if (myRTC.hours == 0) {
    for (int i = 0; i < 36; i++) {
      ledoff(i, 34, 35, 36);
    }

 
  }
  //
  if (buttonState1 == HIGH) {
    myRTC.minutes++;
    delay(1000);
  } else {
    valorMinuto = 1;
  }
  if (buttonState == HIGH && buttonState1 == HIGH); {
    myRTC.hours = 12;
    pixels.clear();
    pixels.show();
    myRTC.minutes = 0;
  }









  if (PsoXSeg != myRTC.minutes % 4) {
    for (int i = 0; i < 3; i++) { //segundo
      digitalWrite(StepPin, HIGH);
      delay(1);
      digitalWrite(StepPin, LOW);
    }
  } else if (PsoXSeg == myRTC.minutes % 4) {
    for (int i = 0; i < 4; i++) { //segundo
      digitalWrite(StepPin, HIGH);
      delay(1);
      digitalWrite(StepPin, LOW);
    }
  }
  if (PsoXSeg == valorMinuto) {
    myRTC.minutes;
    digitalWrite(StepPin, HIGH);
    delay(1);
    digitalWrite(StepPin, LOW);
  }



  myRTC.updateTime();

  Serial.print("Current Date / Time: ");                                                                 //|
  Serial.print(myRTC.dayofmonth);                                                                        //|
  Serial.print("/");                                                                                     //|
  Serial.print(myRTC.month);                                                                             //|
  Serial.print("/");                                                                                     //|
  Serial.print(myRTC.year);                                                                              //|
  Serial.print("  ");                                                                                    //|
  Serial.print(myRTC.hours);                                                                             //|
  Serial.print(":");                                                                                     //|
  Serial.print(myRTC.minutes);                                                                           //|
  Serial.print(":");                                                                                     //|
  Serial.println(myRTC.seconds);

  
  }
}
void ledon (int lednumero) {
  pixels.show();
  pixels.setPixelColor(lednumero, pixels.Color(255, 255, 255));

}
void ledoff(int lednumero, int led2, int led3, int led4) {
  pixels.show();
  pixels.setPixelColor(lednumero, pixels.Color(0, 0, 0));
  pixels.setPixelColor(led2, pixels.Color(255, 255, 255));
  pixels.setPixelColor(led3, pixels.Color(255, 255, 255));
  pixels.setPixelColor(led4, pixels.Color(255, 255, 255));

}
