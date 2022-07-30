#include <LiquidCrystal.h>
String Menu[] = {"Main Title         ", "Change Brightness      ", "LED Light2        ", "LED Light3        ", "Distance Tracker"};
int currentMenu = 0;
extern LiquidCrystal lcd;

void selectMenuInit()
{

    lcd.setCursor(0, 0);
    lcd.print("Menu            ");
    lcd.setCursor(0, 1);
    lcd.print(Menu[currentMenu]);
}

void selectMenu(int x)
{
    lcd.setCursor(0, 1);
    if (x > 70 && x < 200)
    {
        if (currentMenu == 0)
        {
            currentMenu = *(&Menu + 1) - Menu - 1;
        }
        else
        {
            currentMenu -= 1;
        }
        lcd.print(Menu[currentMenu]);
    }
    else if (x > 200 && x < 450)
    {
        if (currentMenu == *(&Menu + 1) - Menu - 1)
        {
            currentMenu = 0;
        }
        else
        {
            currentMenu += 1;
        }
        lcd.print(Menu[currentMenu]);
    }
    delay(220);
}