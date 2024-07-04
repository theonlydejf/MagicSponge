#ifndef ADAPTERS_H
#define ADAPTERS_H

class ButtonAdapter
{
public:
    virtual bool readState() = 0;
};

class TimeAdapter
{
public:
    virtual unsigned long timeStamp() = 0;
};

class LEDAdapter
{
public:
    virtual void writeState(bool on, int brightness) = 0;
    void setBrightness(int brightness) { this->brightness = brightness; }
    int getBrightness() { return brightness; }

    void setState(bool on) { state = on; writeState(state, brightness); }
    bool getState() { return state; }
private:
    int brightness = 255;
    bool state = false;
};

#endif /* ADAPTERS_H */