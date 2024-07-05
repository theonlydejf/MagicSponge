#include "adapters.h"

void LEDAdapter::setEnabled(bool enabled)
{
    this->enabled = enabled;
    if(enabled)
        writeState(state, brightness);
    else
        writeState(false, 0);
}