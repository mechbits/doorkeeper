#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin =  13;

int pir = 2;
int pirStat = 0;

void setup() {
  lcd.begin();
  lcd.setBacklight(LOW);
  lcd.noBlink();
 
  pinMode(ledPin, OUTPUT);
  pinMode(pir, INPUT);
}

void loop() {
  checkPoten();

  pirStat = digitalRead(pir);
  if(pirStat == HIGH){
    digitalWrite(ledPin, HIGH);
    sendM();
  } else {
    lcd.setBacklight(LOW);
    digitalWrite(ledPin, LOW);
  }
}

void checkPoten(){
  int potenVal = analogRead(A7);
  if(potenVal < 960){
    lcd.setCursor(2,0);
    lcd.print("Do NOT enter");
    lcd.setCursor(4,1);
    lcd.print("- Name");
  } else if(potenVal >= 960 && potenVal < 1014){
    lcd.setCursor(1,0);
    lcd.print("Enter QUIETLY!");
    lcd.setCursor(4,1);
    lcd.print("- Name");
  } else {
    lcd.setCursor(1,0);
    lcd.print("Free to enter!");
    lcd.setCursor(4,1);
    lcd.print("- Name");
  }
}

void sendM(){
  lcd.setBacklight(HIGH);
  lcd.clear();
  int potenVal = analogRead(A1);
}
