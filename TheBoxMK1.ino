#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int thing = 0;
String substance;
long startTime;
int frequency;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(thing == 0){

    lcd.begin(16,2);
    lcd.print("INPUT ITEM");
    Serial.print("ITEM: ");
    while (Serial.available() == 0){
    }
    substance = Serial.readString();
    lcd.clear();
    lcd.setCursor(0,0);
    if(substance == "milk"){
      frequency = 10; 
    }
    else if(substance == "apple"){
      frequency = 15; 
    }
    else if(substance == "carrot"){
      frequency = 20; 
    }


    lcd.clear();
    thing = 1;
  }

  if(thing == 1){
    delay(frequency*1000);
    startTime = millis();
    thing = 2;
  }
  if(thing == 2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(substance);
    lcd.setCursor(0,1);
    lcd.print((millis()-startTime)/1000);
    Serial.print(startTime);
    Serial.print("\t");
    Serial.print(millis());
    Serial.println("");

    if(analogRead(A0)<100){
      thing = 1;
      lcd.clear();
    }
  }
  delay(250);
}









