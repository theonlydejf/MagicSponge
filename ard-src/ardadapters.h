#ifndef ARD_ADAPTERS_H
#define ARD_ADAPTERS_H

#include "../display/display.h"

class ArdDisplayAdapter : public DisplayAdapter
{
public:
    static constexpr uint8_t SEGMENT_PIN_OFFSETS[] = 
    {
        6,
        7,
        2,
        1,
        0,
        5,
        4,
        3
    };
    ArdDisplayAdapter(uint8_t segmentStartPin, uint8_t enableStartPin);
    virtual void init() override;
    virtual void pushSegments(uint8_t data) override;
    virtual void enableDigit(uint8_t id) override;
    virtual void disableDigit(uint8_t id) override;
private:
    uint8_t segmentStartPin;
    uint8_t enableStartPin;
};

#endif /* ARD_ADAPTERS_H */