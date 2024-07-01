#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

class DisplayAdapter
{
public:
    virtual void init() = 0;
    virtual void pushSegments(uint8_t data) = 0;
    virtual void enableDigit(uint8_t id) = 0;
    virtual void disableDigit(uint8_t id) = 0;
private:
    friend class DisplayDriver;
};

class DisplayDriver
{
public:
    static constexpr uint8_t DIGIT_CNT = 4;
    DisplayDriver(DisplayAdapter* adapter) : adapter(adapter) {}
    void step();
    void init();
    void setDigit(uint8_t digitID, uint8_t data);
private:
    DisplayAdapter* adapter;
    uint8_t digitSegments[DIGIT_CNT];
    uint8_t lastDigitID;
};

#endif /* DISPLAY_H */