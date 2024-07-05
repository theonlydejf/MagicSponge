#ifndef ARD_ADAPTERS_H
#define ARD_ADAPTERS_H

#include <Arduino.h>

#include "../display/display.h"
#include "../hardware/adapters.h"

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

class ArdButtonAdapter : public ButtonAdapter
{
public:
    ArdButtonAdapter(uint8_t pin, bool inverted = false) : pin(pin), inverted(inverted) { }

    bool readState() { return inverted != digitalRead(pin); }
private:
    uint8_t pin;
    bool inverted;
};

class ArdTimeAdapter : public TimeAdapter
{
public:
    unsigned long timeStamp() override { return millis(); }
};

class ArdDigitalLEDAdapter : public LEDAdapter
{
public:
    ArdDigitalLEDAdapter(uint8_t pin) : pin(pin) { }

    void writeState(bool on, int brightness) override { digitalWrite(pin, on && brightness != 0); }
private:
    uint8_t pin;
};

#endif /* ARD_ADAPTERS_H */