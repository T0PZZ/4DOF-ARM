# 4DOF-ARM
In this project Arduino UNO R3 was used to control [DIY 4DOF robot arm](https://abc-rc.pl/pl/products/ramie-robota-4-dof-diy-model-oparty-o-projekt-edukacyjny-arduino-15901.html).

## Libraries
```
#include <U8glib.h>
#include <Servo.h>
```

## Component list:
- 4 x Serwo MG-90S [CLICK](https://abc-rc.pl/pl/products/serwo-mg-90s-13g-1-8kg-cm-metalowe-zebatki-micro-1227.html)
- 1 x Oled screen compatible with SH1106, 128X64 resolution, screen size 0.96"  [CLICK](https://allegro.pl/oferta/wyswietlacz-oled-0-96-spi-bialy-12423557849)
- 4 x Servo extension [CLICK](https://abc-rc.pl/pl/products/przedluzacz-do-serw-jr-90-cm-3x0-33-skrecony-z-blokada-3074.html?query_id=2) ⚠️ (OPTIONAL)
- 8 x Tact switch 6x6mm [CLICK](https://allegro.pl/oferta/tact-switch-6x6mm-5mm-tht-2pin-5szt-8290767903)
- Male and female connecting cables 
- Big breadboard 
- External power supply for servos

### PSU 
Power supply was made of old USB cable (using only GND and VCC 5V wires) and a powerbank.
![PSU](https://i.imgur.com/fSs3CMM.png)

## Functionality
1) Servomotors **positions are controlled by pushbuttons**. Each servo has 2 buttons : 
  - servo_n_plus (for **incrementation** of nth servo position value)
  - servo_n_minus (for **decrementation** of nth servo position value).
2) If statements check if button is pressed and servo position is within ** avaiable move range** in order to avoid damages to platform and servos themselfs.
3) OLED display shows Electrical Engineering and Computer Science Faculty from Lublin University of Technology [logo](https://i.imgur.com/vS5dOGg.png) **reconstructed by myself in GIMP** as a bitmap.
4) Oled display shows [GUI](https://i.imgur.com/QYVi5hX.png) bitmap with drawings and descriptions of what moves particular servomotor is capable of.
5) Servo angular position is calculated to percent usage of avaiable angular range and drawn near corresponding servo description in GUI.
6) There's a progress bar to visualise percent usage of particular servo.
7) ⚠️  **WORK IN PROGRESS** Button that switches between manual steering mode and auto mode⚠️
8) ⚠️ **WORK IN PROGRESS** Auto mode for arm to lift, move and release object without any user actions ⚠️
 
### **Bitmaps**

  ![WE_logo](https://i.imgur.com/vS5dOGg.png)
    WE logo bitmap
    
    
  ![GUI](https://i.imgur.com/QYVi5hX.png) 
    GUI bitmap

## *DISCLAIMER* ⚠️
<b><i> SPI OLED display is currently not supported by wokwi.com, so I have used I2C one in example below</b></i>.

### Virtual arduino build 
Virtual build was made using  [wokwi.com](https://wokwi.com/)

Virtual model ⚠️ **WORK IN PROGRESS** [CLICK]().⚠️

### Electrical Scheme 
⚠️ **WORK IN PROGRESS** ![Scheme]() ⚠️
