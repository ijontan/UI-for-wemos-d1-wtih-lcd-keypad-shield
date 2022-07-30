

#include <LiquidCrystal.h>
#include "src/menu.h"
#include "src/functions/mainTitle.h"
#include "src/functions/controlBL.h"
#include "src/functions/control_LED/control_led2.h"
#include "src/functions/control_LED/control_led3.h"
#include "src/functions/control_LED/led_var.h"
#include "src/functions/distanceTracker.h"

// LCD pin to Arduino
const int pin_RS = D8;
const int pin_EN = D9;
const int pin_d4 = D4;
const int pin_d5 = D5;
const int pin_d6 = D6;
const int pin_d7 = D7;
const int pin_BL = D10;
const int trigPin = D14;
const int echoPin = D15;
LiquidCrystal lcd(pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);

bool selectingMenu;

void setup()
{
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    lcd.begin(16, 2);

    selectingMenu = false;

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
            controlBL(pin_BL, x);
            break;
        case 2:
            controlLed(x);
            break;
        case 3:
            controlLed3(x);
            break;
        case 4:
            distanceTracker();
            break;

        default:
            break;
        }
    }

    if (x >= 700 && x < 1023)
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
                controlBLInit(pin_BL);
                break;
            case 2:
                controlLedInit();
                break;
            case 3:
                controlLed3Init();
                break;
            case 4:
                distanceTrackerInit();
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
}
