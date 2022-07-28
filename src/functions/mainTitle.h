#include <LiquidCrystal.h>

void mainTitleInit(LiquidCrystal lcd)
{
    lcd.setCursor(0, 0);

    lcd.print("Ijon's machine'");
    lcd.setCursor(0, 1);
    lcd.print("Press Key:");
    lcd.setCursor(10, 1);
}
void mainTitle(LiquidCrystal lcd, int x)
{
    lcd.setCursor(10, 1);
    if (x < 60)
    {
        lcd.print("Right ");
    }
    else if (x < 200)
    {
        lcd.print("Up    ");
    }
    else if (x < 400)
    {
        lcd.print("Down  ");
    }
    else if (x < 700)
    {
        lcd.print("Left  ");
    }
}