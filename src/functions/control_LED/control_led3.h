#include <LiquidCrystal.h>
extern int ledR[6];
extern int sLedR;
extern int ledG[6];
extern int sLedG;
extern int ledB[6];
extern int sLedB;
extern int sColor;
extern String getPadding(int num, String color);

void changeBrightness(LiquidCrystal lcd, bool i);

void controlLed3Init(LiquidCrystal lcd)
{
    lcd.setCursor(0, 0);
    lcd.print("Change LED brightness            ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
    lcd.setCursor(5, 1);
    lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
    lcd.setCursor(10, 1);
    lcd.print(getPadding(ledB[sLedB], "B") + String(ledB[sLedB]));
}
void controlLed3(LiquidCrystal lcd, int x)
{
    if (x < 60)
    {
        if (sColor == 2)
        {
            sColor = 0;
        }
        else
        {
            sColor += 1;
        }
    }
    else if (x < 200)
    {
        changeBrightness(lcd, true);
    }
    else if (x < 400)
    {
        changeBrightness(lcd, false);
    }
    else if (x < 700)
    {
        if (sColor == 0)
        {
            sColor = 2;
        }
        else
        {
            sColor -= 1;
        }
    }
}

void changeBrightness(LiquidCrystal lcd, bool i)
{
    lcd.setCursor(sColor * 5, 1);
    switch (sColor)
    {
    case 0:
        if (i)
        {
            if (sLedR == *(&ledR + 1) - ledR - 1)
            {
                sLedR = 0;
                analogWrite(D0, ledR[sLedR]);
                lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
                return;
            }

            sLedR += 1;
            analogWrite(D0, ledR[sLedR]);
            lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
        }
        else
        {
            if (sLedR == 0)
            {
                sLedR = 5;
                analogWrite(D0, ledR[sLedR]);
                lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
                return;
            }

            sLedR -= 1;
            analogWrite(D0, ledR[sLedR]);
            lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
        }

        break;
    case 1:
        if (i)
        {
            if (sLedG == *(&ledG + 1) - ledG - 1)
            {
                sLedG = 0;
                analogWrite(D1, ledG[sLedG]);
                lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
                return;
            }

            sLedG += 1;
            analogWrite(D1, ledG[sLedG]);
            lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
        }
        else
        {
            if (sLedG == 0)
            {
                sLedG = 5;
                analogWrite(D1, ledG[sLedG]);
                lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
                return;
            }

            sLedG -= 1;
            analogWrite(D1, ledG[sLedG]);
            lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
        }

        break;
    case 2:
        if (i)
        {
            if (sLedB == *(&ledB + 1) - ledB - 1)
            {
                sLedB = 0;
                analogWrite(D2, ledB[sLedB]);
                lcd.print(getPadding(ledB[sLedB], "B") + String(ledB[sLedB]));
                return;
            }

            sLedB += 1;
            analogWrite(D2, ledB[sLedB]);
            lcd.print(getPadding(ledB[sLedB], "B") + String(ledB[sLedB]));
        }
        else
        {
            if (sLedB == 0)
            {
                sLedB = 5;
                analogWrite(D2, ledB[sLedB]);
                lcd.print(getPadding(ledB[sLedB], "B") + String(ledB[sLedB]));
                return;
            }

            sLedB -= 1;
            analogWrite(D2, ledB[sLedB]);
            lcd.print(getPadding(ledB[sLedB], "B") + String(ledB[sLedB]));
        }

        break;

    default:
        break;
    }
}