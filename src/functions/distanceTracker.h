#include <LiquidCrystal.h>
extern const int trigPin;
extern const int echoPin;

extern LiquidCrystal lcd;
String getPaddingD(int num);
long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement

void distanceTrackerInit()
{
    lcd.setCursor(0, 0);
    lcd.print("Distance Tracker");
    lcd.setCursor(0, 1);
    lcd.print("Distance:       ");
}

void distanceTracker()
{
    // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    lcd.setCursor(11, 1);
    if (distance <= 500)
    {
        lcd.print(getPaddingD(distance) + String(distance) + "cm");
    }
    else
    {
        lcd.print("error");
    }
    if (distance <= 8 && distance >= 0)
    {
        analogWrite(D0, 255);
    }
    else if (distance < 150 && distance > 8)
    {
        float rR = abs(2000 / distance);
        analogWrite(D0, rR);
        analogWrite(D2, 0);
        analogWrite(D1, 0);
        Serial.print(rR);
    }

    if (distance < 300 && distance >= 292)
    {
        analogWrite(D2, 255);
    }
    else if (distance < 292 && distance > 150)
    {
        float rB = abs(2000 / (distance - 300));
        analogWrite(D2, rB);
        analogWrite(D0, 0);
        analogWrite(D1, 0);
        Serial.print(rB);
    }

    if (distance >= 142 && distance <= 158)
    {
        analogWrite(D1, 255);
    }
    else if (distance < 300 && distance > 0)
    {
        float rG = abs(2000 / (distance - 150));
        analogWrite(D1, rG);
        Serial.print(rG);
    }

    delay(100);
}

String getPaddingD(int num)
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
    return padding;
}