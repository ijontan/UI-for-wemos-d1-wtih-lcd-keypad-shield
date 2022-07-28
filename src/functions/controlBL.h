#include <LiquidCrystal.h>

int bl[] = {0, 50, 100, 150, 200, 255};
int sbl = 5;

void controlBLInit(LiquidCrystal lcd, int pin_BL)
{
    analogWrite(pin_BL, bl[sbl]);
    lcd.setCursor(0, 0);
    lcd.print("Change Brightness            ");
    lcd.setCursor(0, 1);
    lcd.print(String(bl[sbl]) + "              ");
}
void controlBL(LiquidCrystal lcd, int pin_BL, int x)
{
    lcd.setCursor(0, 1);
    if (x < 60)
    {
        if (sbl == 0)
        {
            sbl = 5;
            analogWrite(pin_BL, bl[sbl]);
            lcd.print(String(bl[sbl]) + "              ");
            return;
        }

        sbl -= 1;
        analogWrite(pin_BL, bl[sbl]);
        lcd.print(String(bl[sbl]) + "              ");
    }
    else if (x > 400 && x < 700)
    {

        if (sbl == *(&bl + 1) - bl - 1)
        {
            sbl = 0;
            analogWrite(pin_BL, bl[sbl]);
            lcd.print(String(bl[sbl]) + "              ");
            return;
        }

        sbl += 1;
        analogWrite(pin_BL, bl[sbl]);
        lcd.print(String(bl[sbl]) + "              ");
    }
}