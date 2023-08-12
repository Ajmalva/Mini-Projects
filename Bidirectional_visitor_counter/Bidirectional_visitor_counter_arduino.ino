#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#define in 5
#define out 3
#define relay 2
int count=0;

void setup()
{
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(3000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(relay, OUTPUT);
  lcd.clear();
  Serial.begin(9600);

}
void loop()
{  
  
  if(digitalRead(in)==0)
  IN();
  if(digitalRead(out)==0)
  OUT();
  
  if(count<=0)
  {
    lcd.clear();
    digitalWrite(relay, HIGH);
    lcd.clear();
    lcd.print("Nobody In Room");
    Serial.println("nobody In Room");
    Serial.println("Lights OFF");
    lcd.setCursor(0,1);
    lcd.print("Light Is Off");
    delay(500);
  }
   else
    digitalWrite(relay, LOW);
}

void IN()
{
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
   Serial.println("people in");
   Serial.println("Lights ON");

   Serial.println(count);
    delay(500);
}
void OUT()
{
    count--;
    if(count<=0)
    {
      count=0;
    }
    else
    {
      Serial.println("Lights ON");
    }
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    Serial.println("people out");
    Serial.println(count);
    delay(500);
}
