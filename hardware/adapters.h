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

    void setState(bool on) { state = on; writeState(enabled && state, brightness); }
    bool getState() { return state; }
    void setEnabled(bool enabled);
    bool getEnabled() { return enabled; }
private:
    int brightness = 255;
    bool state = false;
    bool enabled = true;
};

#endif /* ADAPTERS_H */