/*
 *CAPITULO IV: PERIFERICOS ESPECIALES
 *DEBER 4.1: CONVERSORES ANALOGO DIGITALES Y PWM
 *OBJETIVO: Realizar un sistema en el cual se conecten 2 motores (parecido al diagrama que se utilizo en clase). 
 *          Los datos de CAD, V y PWM se deben visulizar en una LCD para cada motor.   
 *          A travez de la activación de un botón y un switch (el funcionamiento de un motor dependerá de la activación de un botón 
 *          y el otro dependerá de la activación de un switch, a su elección) entrará en funcionamiento el motor que corresponda y se 
 *          visualizará en la LCD de ese motor los datos de CAD, Voltaje y PWM.
 *NOMBRE: RAFAEL FARINANGO
 *FUNCIONES:  analogRead(conversor) A0 - A5
 *            analogWrite(pin,dutty) pin: pines con ~ , dutty: 0 - 255
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);
LiquidCrystal lcd2(A0,A1,9,8,7,6);

int conversor;
float voltaje;
int dutty;

int conversor2;
float voltaje2;
int dutty2;

void setup() {
  lcd.begin(16,2);
  lcd2.begin(16,2);
}

void loop() {
  conversor=analogRead(A5);
  voltaje=(conversor*5.0)/1023;
  dutty=conversor/4;
  analogWrite(11,dutty);
  lcd.setCursor(0,0);
  lcd.print("CAD:");
  lcd.setCursor(6,0);
  lcd.print(conversor);
  lcd.setCursor(0,1);
  lcd.print("V:");
  lcd.setCursor(3,1);
  lcd.print(voltaje);
  lcd.setCursor(9,1);
  lcd.print("PWM:");
  lcd.setCursor(13,1);
  lcd.print((dutty*100)/255);
  delay(300);
  //lcd.clear();
  ///////////////////////
  conversor2=analogRead(A4);
  voltaje2=(conversor2*5.0)/1023;
  dutty2=conversor2/4;
  analogWrite(10,dutty2);
  lcd2.setCursor(0,0);
  lcd2.print("CAD:");
  lcd2.setCursor(6,0);
  lcd2.print(conversor);
  lcd2.setCursor(0,1);
  lcd2.print("V:");
  lcd2.setCursor(3,1);
  lcd2.print(voltaje);
  lcd2.setCursor(9,1);
  lcd2.print("PWM:");
  lcd2.setCursor(13,1);
  lcd2.print((dutty2*100)/255);
  delay(300);
  //lcd2.clear();
}
