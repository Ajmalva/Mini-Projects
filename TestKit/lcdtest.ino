// include the library code:
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(13,12,11,10,9,8);
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(" Hello World!");
  delay(2000);
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Count!");
  // print the number of seconds since reset:
}
void loop() {
  for (int i = 0; i < 10; i ++)
  {
    lcd.setCursor(8, 1);
    // print the number of seconds since reset:
    lcd.print(i);
    delay(1000);
  }
}
