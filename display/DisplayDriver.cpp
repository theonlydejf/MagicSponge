#include "display.h"

void DisplayDriver::muxStep()
{
    adapter->disableDigit(lastDigitID);
    lastDigitID = (lastDigitID + 1) % DIGIT_CNT;
    adapter->pushSegments(digitSegments[lastDigitID]);
    adapter->enableDigit(lastDigitID);
}

void DisplayDriver::init()
{
    for (uint8_t i = 0; i < DIGIT_CNT; i++)
        digitSegments[i] = 0;

    lastDigitID = 0;
}

void DisplayDriver::setDigit(uint8_t digitID, uint8_t data)
{
    if (digitID < DIGIT_CNT)
        digitSegments[digitID] = data;
}