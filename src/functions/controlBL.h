#include <LiquidCrystal.h>

int bl[] = {0, 50, 100, 150, 200, 255};
int sbl = 5;
extern LiquidCrystal lcd;

void controlBLInit(int pin_BL)
{
    analogWrite(pin_BL, bl[sbl]);
    lcd.setCursor(0, 0);
    lcd.print("Change Brightness            ");
    lcd.setCursor(0, 1);
    lcd.print(String(bl[sbl]) + "              ");
}
void controlBL(int pin_BL, int x)
{
    lcd.setCursor(0, 1);
    if (x < 70)
    {
        if (sbl == 0)
        {
            sbl = 5;
        }
        else

        {
            sbl -= 1;
        }
    }
    else if (x > 450 && x < 700)
    {

        if (sbl == *(&bl + 1) - bl - 1)
        {
            sbl = 0;
        }

        else
        {
            sbl += 1;
        }
    }
    analogWrite(pin_BL, bl[sbl]);
    lcd.print(String(bl[sbl]) + "              ");
    delay(170);
}