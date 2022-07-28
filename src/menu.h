#include <LiquidCrystal.h>
String Menu[] = {"Main Title         ", "Change Brightness      ", "LED Light2        ", "LED Light3        "};
int currentMenu;
void selectMenuInit(LiquidCrystal lcd)
{
    currentMenu = 0;
    lcd.setCursor(0, 0);
    lcd.print("Menu            ");
    lcd.setCursor(0, 1);
    lcd.print(Menu[currentMenu]);
}

void selectMenu(LiquidCrystal lcd, int x)
{
    lcd.setCursor(0, 1);
    if (x > 60 && x < 200)
    {
        if (currentMenu == 0)
        {
            currentMenu = *(&Menu + 1) - Menu - 1;
            lcd.print(Menu[currentMenu]);
            return;
        }

        currentMenu -= 1;
        lcd.print(Menu[currentMenu]);
    }
    else if (x > 200 && x < 400)
    {
        if (currentMenu == *(&Menu + 1) - Menu - 1)
        {
            currentMenu = 0;
            lcd.print(Menu[currentMenu]);
            return;
        }
        currentMenu += 1;
        lcd.print(Menu[currentMenu]);
    }
}