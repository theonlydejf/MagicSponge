#include "ledmanager.h"

void LEDManager::setEnabled(bool enabled)
{
    if(this->enabled != enabled)
    {
        if(enabled)
            for(int i = 0; i < adaptersCnt; i++)
                adapters[i]->writeState(adapters[i]->getState(), adapters[i]->getBrightness());
        else
            for(int i = 0; i < adaptersCnt; i++)
                adapters[i]->writeState(false, 0);
    }
    this->enabled = enabled;
}
