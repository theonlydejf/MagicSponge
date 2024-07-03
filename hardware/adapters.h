#ifndef ADAPTERS_H
#define ADAPTERS_H

class ButtonAdapter
{
    virtual bool readState() = 0;
};

class TimeAdapter
{
    virtual unsigned long timeStamp() = 0;
};

class LEDAdapter
{
    // TODO global disable
};

#endif /* ADAPTERS_H */