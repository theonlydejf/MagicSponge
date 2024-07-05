#include "displaygraphics.h"

int pow10(int n)
{
    int a = 1;
    for(int i = 0; i < n; i++)
        a *= 10;
    return a;
}

bool showNum(DisplayDriver& driver, int num, int base)
{
    if(num <= -pow10(DisplayDriver::DIGIT_CNT - 1) || num >= pow10(DisplayDriver::DIGIT_CNT))
        return false;

    int position = 3;

    do
    {
        int digit = num % base;
        driver.setDigit(position, FONT[digit].segments);

        num /= base;
        position--;
    } while (num > 0 && position >= 0);
    
    while(position >= 0)
    {
        driver.setDigit(position, DIGIT_OFF);
        position--;
    }

    return true;
}

uint8_t getCharSegments(char c)
{
    for(int i = 0; i < FONT_CHAR_CNT; i++)
    {
        if(FONT[i].character == c)
            return FONT[i].segments;
    }
    return 0;
}

bool showStr(DisplayDriver& driver, const char* str)
{
    int position = 0;
    for(const char* c = str; *c; str++)
    {
        if(position >= DisplayDriver::DIGIT_CNT)
            return false;

        uint8_t segments = getCharSegments(*c);
        driver.setDigit(position, segments);
        position++;
    }
    return true;
}
