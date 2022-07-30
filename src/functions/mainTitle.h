#include <LiquidCrystal.h>
extern LiquidCrystal lcd;

void mainTitleInit()
{
    lcd.setCursor(0, 0);

    lcd.print("Ijon's machine'");
    lcd.setCursor(0, 1);
    lcd.print("Press Key:");
    lcd.setCursor(10, 1);
}
void mainTitle(int x)
{
    lcd.setCursor(10, 1);
    if (x < 70)
    {
        lcd.print("Right ");
    }
    else if (x < 200)
    {
        lcd.print("Up    ");
    }
    else if (x < 450)
    {
        lcd.print("Down  ");
    }
    else if (x < 700)
    {
        lcd.print("Left  ");
    }
    delay(170);
}