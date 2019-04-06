#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

int BCD_inputA = 2;
int BCD_inputB = 3;
int BCD_inputC = 4;
int BCD_inputD = 5;
int BCD_map0;
int BCD_map1;
int BCD_map2;
int BCD_map3;
int BCD[] = {BCD_inputA,BCD_inputB,BCD_inputC,BCD_inputD};
void setup() 
{
pinMode(BCD_inputA, INPUT);
pinMode(BCD_inputB, INPUT); 
pinMode(BCD_inputC, INPUT);
pinMode(BCD_inputD, INPUT);
lcd.begin(16,2);
Serial.begin(9600);
}


void loop() 
{
 

 
 BCD_map0 = digitalRead(BCD[0]);
 BCD_map0 = map(BCD_map0, LOW, HIGH,1,0);
 BCD_map1 = digitalRead(BCD[1]);
 BCD_map1 = map(BCD_map1, LOW, HIGH,1,0);
 BCD_map2 = digitalRead(BCD[2]);
 BCD_map2 = map(BCD_map2, LOW,HIGH,1,0);
 BCD_map3 = digitalRead(BCD[3]);
 BCD_map3 = map(BCD_map3, LOW,HIGH,1,0);
 byte a;
 
 bitWrite(a, 0, BCD_map0);
 bitWrite(a, 1, BCD_map1);
 bitWrite(a, 2, BCD_map2);
 bitWrite(a, 3, BCD_map3);
 word lcd_display = a;
 
 do{
  lcd.setCursor(0,0);
 
 
 lcd.print(lcd_display);
 
  
 }while(lcd_display != 0);
 
 
  
 
 
 
 
 }
