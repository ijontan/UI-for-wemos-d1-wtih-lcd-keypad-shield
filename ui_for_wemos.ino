

#include <LiquidCrystal.h>
#include "src/menu.h"
#include "src/functions/mainTitle.h"
#include "src/functions/controlBL.h"
#include "src/functions/control_LED/control_led2.h"
#include "src/functions/control_LED/control_led3.h"
#include "src/functions/control_LED/led_var.h"

// LCD pin to Arduino
const int pin_RS = D8;
const int pin_EN = D9;
const int pin_d4 = D4;
const int pin_d5 = D5;
const int pin_d6 = D6;
const int pin_d7 = D7;
const int pin_BL = D10;
LiquidCrystal lcd(pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);

bool selectingMenu;

void setup()
{
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);

    lcd.begin(16, 2);

    selectingMenu = false;

    mainTitleInit(lcd);
}

void loop()
{

    int x;
    x = analogRead(0);

    if (selectingMenu)
    {
        selectMenu(lcd, x);
    }
    else
    {
        switch (currentMenu)
        {
        case 0:
            mainTitle(lcd, x);

            break;
        case 1:
            controlBL(lcd, pin_BL, x);
            break;
        case 2:
            controlLed(lcd, x);
            break;
        case 3:
            controlLed3(lcd, x);
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
                mainTitleInit(lcd);

                break;
            case 1:
                controlBLInit(lcd, pin_BL);
                break;
            case 2:
                controlLedInit(lcd);
                break;
            case 3:
                controlLed3Init(lcd);
                break;

            default:
                break;
            }
        }
        else
        {
            selectingMenu = true;
            selectMenuInit(lcd);
        }
    }
    delay(170);
}
