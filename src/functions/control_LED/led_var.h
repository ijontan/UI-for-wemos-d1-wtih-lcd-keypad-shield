int ledR[] = {0, 50, 100, 150, 200, 255};
int sLedR = 0;
int ledG[] = {0, 50, 100, 150, 200, 255};
int sLedG = 0;
int ledB[] = {0, 50, 100, 150, 200, 255};
int sLedB = 0;
int sColor = 0;

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
