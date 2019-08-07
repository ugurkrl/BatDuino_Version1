#include "MAX17043.h"
#include "Wire.h"
MAX17043 fg;
float voltage;
float soc;
int levl;
float rcomp;

void setup() {
//pinMode(2,OUTPUT);
//pinMode(3,OUTPUT);
//pinMode(4,OUTPUT);
//pinMode(5,OUTPUT);
//pinMode(6,OUTPUT);
digitalWrite(2,1);
delay(100);
digitalWrite(3,1);
delay(100);
digitalWrite(4,1);
delay(100);
digitalWrite(5,1);
delay(100);
digitalWrite(6,1);
Wire.begin();
delay(50);
Serial.begin(9600);
digitalWrite(2,0);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
//rcomp=fg.getCompensateValue();
//Serial.println(rcomp);

}

void loop() {
soc=fg.getSoC();
delay(250);
voltage=fg.getVCell()*10;


Serial.print(soc,4);
Serial.print("  ");
Serial.println(voltage,4);
levl = map(soc, 5, 90, 0, 5);
digitalWrite(2,0); digitalWrite(3,0); digitalWrite(4,0); digitalWrite(5,0); digitalWrite(6,0);
if(levl == 1){ digitalWrite(2,1); }
if(levl == 2){ digitalWrite(2,1); digitalWrite(3,1); }
if(levl == 3){ digitalWrite(2,1); digitalWrite(3,1); digitalWrite(4,1); }
if(levl == 4){ digitalWrite(2,1); digitalWrite(3,1); digitalWrite(4,1); digitalWrite(5,1);  }
if(levl == 5){ digitalWrite(2,1); digitalWrite(3,1); digitalWrite(4,1); digitalWrite(5,1); digitalWrite(6,1); }
delay(5000);


}
