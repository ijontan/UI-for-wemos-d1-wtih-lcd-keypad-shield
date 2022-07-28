

#include <LiquidCrystal.h>

// LCD pin to Arduino
const int pin_RS = D8;
const int pin_EN = D9;
const int pin_d4 = D4;
const int pin_d5 = D5;
const int pin_d6 = D6;
const int pin_d7 = D7;
const int pin_BL = D10;
LiquidCrystal lcd(pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);
String Menu[] = {"Main Title         ", "Change Brightness      ", "Change LED Light    ", "Change LED Light3    "};
bool selectingMenu;
int currentMenu;
int bl[] = {0, 50, 100, 150, 200, 255};
int sbl = 5;
void setup()
{
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    analogWrite(pin_BL, bl[sbl]);
    lcd.begin(16, 2);

    selectingMenu = false;
    currentMenu = 0;
    mainTitleInit();
}

void loop()
{

    int x;
    x = analogRead(0);

    if (selectingMenu)
    {
        selectMenu(x);
    }
    else
    {
        switch (currentMenu)
        {
        case 0:
            mainTitle(x);

            break;
        case 1:
            controlBL(x);
            break;
        case 2:
            controlLed(x);
            break;
        case 3:
            controlLed3(x);
            break;

        default:
            break;
        }
    }

    if (x > 700 && x < 1000)
    {
        lcd.print("Select");
        if (selectingMenu)
        {
            selectingMenu = false;
            switch (currentMenu)
            {
            case 0:
                mainTitleInit();

                break;
            case 1:
                controlBLInit();
                break;
            case 2:
                controlLedInit();
                break;
            case 3:
                controlLed3Init();
                break;

            default:
                break;
            }
        }
        else
        {
            selectingMenu = true;
            selectMenuInit();
        }
    }
    delay(170);
}

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

void controlBLInit()
{
    lcd.setCursor(0, 0);
    lcd.print("Change Brightness            ");
    lcd.setCursor(0, 1);
    lcd.print(String(bl[sbl]) + "              ");
}
void controlBL(int x)
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

int ledG[] = {0, 50, 100, 150, 200, 255};
int sLedG = 5;
int ledR[] = {0, 50, 100, 150, 200, 255};
int sLedR = 5;

void controlLedInit()
{
    lcd.setCursor(0, 0);
    lcd.print("Change LED brightness            ");
    lcd.setCursor(0, 1);
    lcd.print(getPadding(ledG[sLedG], "G") + String(ledG[sLedG]));
    lcd.setCursor(8, 1);
    lcd.print(getPadding(ledR[sLedR], "R") + String(ledR[sLedR]));
}
void controlLed(int x)
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

String getPadding(int num, String color)
{
    int n = 0;
    if (num == 0)
    {
        n += 1;
    }
    while (num != 0)
    {
        num /= 10;
        n += 1;
    }

    String padding = "";
    for (int i = 0; i < 3 - n; i++)
    {
        padding += " ";
    }
    for (int i = 0; i < 1 - color.length(); i++)
    {
        padding += " ";
    }

    return color + padding;
}

int ledB[] = {0, 50, 100, 150, 200, 255};
int sLedB = 5;
int sColor = 0;

void controlLed3Init()
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
void controlLed3(int x)
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
        changeBrightness(true);
    }
    else if (x < 400)
    {
        changeBrightness(false);
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

void changeBrightness(bool i)
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