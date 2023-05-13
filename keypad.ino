#include <Servo.h>
#include <Keypad.h>
#define s1p 1
#define s1m 2
#define s2p 3
#define s2m 4
#define s3p 5
#define s3m 6
#define s4p 7
#define s4m 8
#define chngp 9
#define chngm 10
#define ind 8
Servo s1,s2,s3,s4;
int s1pos,s2pos,s3pos,s4pos,chng=5;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {s1p,s1m,s2p,s2m},
  {s3p,s3m,s4p,s4m},
  {'B10','B10','B11','B12'},
  {'B13','B14','B15','B16'}
};
byte rowPins[ROWS] = {0, 1, 2, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11, 10}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  int chng=2;
  Serial.begin(9600);
  s1.attach(3);s2.attach(5);s3.attach(6);s4.attach(9);
  s1.write(s1pos);s2.write(s2pos);s3.write(s3pos);s4.write(s4pos);
}
  
  void blink(){
  digitalWrite(ind,HIGH);
  delay(80);
  digitalWrite(ind,LOW);
}
void loop(){
  char customKey = customKeypad.getKey();
  if (customKey==s1p && s1pos>=0){
    s1pos=s1pos+chng;s1.write(s1pos);
    blink(); delay(50);
  }
  if (customKey==s1m && s1pos<=180){
    s1pos=s1pos-chng;s1.write(s1pos);
    blink();
  }
    if (customKey==s2p && s2pos>=0){
    s2pos=s2pos+chng;delay(50);s2.write(s2pos);
    blink();
  }
  if (customKey==s2m && s2pos<=180){
    s2pos=s2pos-chng;delay(50);s2.write(s2pos);
    blink();
  }
    if (customKey==s3p && s3pos>=0){
    s3pos=s3pos+chng;delay(50);s3.write(s3pos);
    blink();
  }
  if (customKey==s3m && s3pos<=180){
    s3pos=s3pos-chng;delay(50);s3.write(s3pos);
    blink();
  }
    if (customKey==s4p && s4pos>=0){
    s4pos=s4pos+chng;delay(50);s4.write(s4pos);
    blink();
  }
  if (customKey==s4m && s4pos<=180){
    s4pos=s4pos-chng;delay(50);s4.write(s4pos);
    blink();
  }
  if (customKey==chngp && chng>=0){
    chng=chng+1;
    blink();
   }
     
   if (customKey==chngm && chng<=5){
    chng=chng-1;
    blink();
   }
}