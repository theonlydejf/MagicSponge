#include "ardadapters.h"

constexpr uint8_t ArdDisplayAdapter::SEGMENT_PIN_OFFSETS[];

ArdDisplayAdapter::ArdDisplayAdapter(uint8_t segmentStartPin, uint8_t enableStartPin)
    : segmentStartPin(segmentStartPin), enableStartPin(enableStartPin)
{

}

void ArdDisplayAdapter::init()
{

}

void ArdDisplayAdapter::pushSegments(uint8_t data)
{
    for(int i = 0; i < 8; i++)
    {
        bool segState = data & 1;
        digitalWrite(segmentStartPin + SEGMENT_PIN_OFFSETS[i], !segState);
        data >>= 1;
    }
}

void ArdDisplayAdapter::enableDigit(uint8_t id)
{
    digitalWrite(enableStartPin + id, HIGH);
}

void ArdDisplayAdapter::disableDigit(uint8_t id)
{
    digitalWrite(enableStartPin + id, LOW);
}
