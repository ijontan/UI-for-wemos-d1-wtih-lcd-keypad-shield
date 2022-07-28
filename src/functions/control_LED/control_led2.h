#include <LiquidCrystal.h>
extern int ledR[6];
extern int sLedR;
extern int ledG[6];
extern int sLedG;
extern int ledB[6];
extern int sLedB;
extern String getPadding(int num, String color);

void controlLedInit(LiquidCrystal lcd)
{
    lcd.setCursor(0, 0);
    lcd.print("Change LED brightness            ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
    lcd.setCursor(8, 1);
    lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
}
void controlLed(LiquidCrystal lcd, int x)
{
    if (x < 60)
    {
        lcd.setCursor(0, 1);
        if (sLedG == *(&ledG + 1) - ledG - 1)
        {
            sLedG = 0;
            analogWrite(D0, ledG[sLedG]);
            lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
            return;
        }

        sLedG += 1;
        analogWrite(D0, ledG[sLedG]);
        lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
    }
    else if (x < 200)
    {
        lcd.setCursor(8, 1);
        if (sLedR == *(&ledR + 1) - ledR - 1)
        {
            sLedR = 0;
            analogWrite(D1, ledR[sLedR]);
            lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
            return;
        }

        sLedR += 1;
        analogWrite(D1, ledR[sLedR]);
        lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
    }
    else if (x < 400)
    {
        lcd.setCursor(8, 1);
        if (sLedR == 0)
        {
            sLedR = 5;
            analogWrite(D1, ledR[sLedR]);
            lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
            return;
        }

        sLedR -= 1;
        analogWrite(D1, ledR[sLedR]);
        lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
    }
    else if (x < 700)
    {
        lcd.setCursor(0, 1);
        if (sLedG == 0)
        {
            sLedG = 5;
            analogWrite(D0, ledG[sLedG]);
            lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
            return;
        }

        sLedG -= 1;
        analogWrite(D0, ledG[sLedG]);
        lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
    }
}