//DFRobot.com
//Compatible with the Arduino IDE 1.0 & 1.8
//Library version:1.2
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

#define deg 223
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
#define ind A0

Servo s1;
int s1pos=90,s2pos=90,s3pos=90,s4pos=90,chng=5;

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {s1p,s1m,s2p,s2m},
  {s3p,s3m,s4p,s4m},
  {'B10','B10','B11','B12'},
  {'B13','B14','B15','B16'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; 
byte colPins[COLS] = {7, 6, 5, 4}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

LiquidCrystal_I2C lcd(0x27,16,2); 



void setup() {
lcd.init();
lcd.backlight();
//intro();

  s1.attach(13);s1.write(s1pos);
}


void loop(){

position_display();

char customKey = customKeypad.getKey();

  if (customKey==s1p && s1pos<=180){
    s1pos=s1pos+chng;
    if(s1pos>180){s1pos=180;}s1.write(s1pos);
    blink(); delay(50);
  }
  if (customKey==s1m && s1pos>=0){
    s1pos=s1pos-chng; if(s1pos<0){s1pos=0;}s1.write(s1pos);
    blink();
  }
    if (customKey==s2p && s2pos<=180){
    s2pos=s2pos+chng;delay(50);
    if(s2pos>180){s2pos=180;}//s2.write(s2pos);
    blink();
  }
  if (customKey==s2m && s2pos>=0){
    s2pos=s2pos-chng;delay(50);if(s2pos<0){s2pos=0;}//s2.write(s2pos);
    blink();
  }
    if (customKey==s3p && s3pos<=180){
    s3pos=s3pos+chng;delay(50); if(s3pos>180){s3pos=180;}//s3.write(s3pos);
    blink();
  }
  if (customKey==s3m && s3pos>=0){
    s3pos=s3pos-chng;delay(50);if(s3pos<0){s3pos=0;}//s3.write(s3pos);
    blink();
  }
    if (customKey==s4p && s4pos<=180){
    s4pos=s4pos+chng;delay(50); if(s4pos>180){s4pos=180;}//s4.write(s4pos);
    blink();
  }
  if (customKey==s4m && s4pos>=0){
    s4pos=s4pos-chng;delay(50);if(s4pos<0){s4pos=0;}//s4.write(s4pos);
    blink();
  }
 // if (customKey==chngp && chng>=0){
//    chng=chng+1;
//    blink();
 //  }
     
  // if (customKey==chngm && chng<=5){
   // chng=chng-1;
 //  blink();
//   }
}

void position_display(){lcd.clear();  lcd.print("1)");
  lcd.setCursor(9,0);lcd.print("2)");
  lcd.setCursor(0,1);lcd.print("3)");
  lcd.setCursor(9,1);lcd.print("4)");

  lcd.setCursor(5,0);lcd.printByte(deg);
  lcd.setCursor(5,1);lcd.printByte(deg);
  lcd.setCursor(15,0);lcd.printByte(deg);
  lcd.setCursor(15,1);lcd.printByte(deg);

    lcd.setCursor(2,0);lcd.print(s1pos);
  lcd.setCursor(11,0);lcd.print(s2pos);
  lcd.setCursor(2,1);lcd.print(s3pos);
  lcd.setCursor(11,1);lcd.print(s4pos);}

  void blink(){
  digitalWrite(ind,HIGH);
  delay(80);
  digitalWrite(ind,LOW);}

void intro(){
  lcd.print("Projekt");lcd.setCursor(0,1);lcd.print("Inzynierski"); delay(4000);lcd.clear();
  lcd.print("Ramie");lcd.setCursor(0,1);lcd.print("Robota"); delay(4000);lcd.clear();
  lcd.print("Konard Kruk");lcd.setCursor(0,1);lcd.print("MEGP03");lcd.setCursor(10,1);lcd.print("95012"); delay(4000);lcd.clear();
  lcd.print("Inicjalizacja");lcd.setCursor(0,1);lcd.print("Zakonczona"); delay(4000);lcd.clear();
}