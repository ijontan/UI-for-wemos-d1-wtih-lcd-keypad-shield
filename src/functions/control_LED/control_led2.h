#include <LiquidCrystal.h>
extern int ledR[6];
extern int sLedR;
extern int ledG[6];
extern int sLedG;
extern int ledB[6];
extern int sLedB;
extern String getPadding(int num, String color);
extern LiquidCrystal lcd;

void controlLedInit()
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

static void exitCLED2()
{
    delay(170);
}
void controlLed(int x)
{
    atexit(exitCLED2);
    if (x < 70)
    {
        lcd.setCursor(0, 1);
        if (sLedG == *(&ledG + 1) - ledG - 1)
        {
            sLedG = 0;
        }
        else
        {
            sLedG += 1;
        }
        analogWrite(D0, ledG[sLedG]);
        lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
    }
    else if (x < 200)
    {
        lcd.setCursor(8, 1);
        if (sLedR == *(&ledR + 1) - ledR - 1)
        {
            sLedR = 0;
        }
        else
        {
            sLedR += 1;
        }
        analogWrite(D1, ledR[sLedR]);
        lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
    }
    else if (x < 450)
    {
        lcd.setCursor(8, 1);
        if (sLedR == 0)
        {
            sLedR = 5;
        }
        else
        {
            sLedR -= 1;
        }
        analogWrite(D1, ledR[sLedR]);
        lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
    }
    else if (x < 700)
    {
        lcd.setCursor(0, 1);
        if (sLedG == 0)
        {
            sLedG = 5;
        }
        else
        {
            sLedG -= 1;
        }
        analogWrite(D0, ledG[sLedG]);
        lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
    }
    delay(170);
}