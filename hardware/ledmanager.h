#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "adapters.h"

class LEDManager
{
public:
    LEDManager(LEDAdapter** adapters, size_t adaptersCnt)
        : adapters(adapters), adaptersCnt(adaptersCnt) {}
    
    void setEnabled(bool enabled);
    bool getEnabled() { return enabled; }
private:
    LEDAdapter** adapters;
    size_t adaptersCnt;
    bool enabled = true;
};

#endif /* LED_DRIVER_H */