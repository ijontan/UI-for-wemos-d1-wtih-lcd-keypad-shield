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
    lcd.print("Distance: ");

    lcd.setCursor(14, 1);
    lcd.print("cm");
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
    lcd.print(getPaddingD(distance) + String(distance));
    delay(200);
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