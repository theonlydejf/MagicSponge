#include "buttonsdriver.h"

template<size_t BTN_COUNT>
ButtonsDriver<BTN_COUNT>::ButtonsDriver(ButtonAdapter* adapters, TimeAdapter* timeAdapter)
    : timeAdapter(timeAdapter)
{
    for (size_t i = 0; i < BTN_COUNT; ++i)
        buttons[i] = Button(adapters + i);
}

template<size_t BTN_COUNT>
bool ButtonsDriver<BTN_COUNT>::update()
{
    bool foundPressed = false;
    unsigned long currentTimestamp = timeAdapter->timeStamp();
    for (size_t i = 0; i < BTN_COUNT; ++i)
    {
        buttons[i].update(currentTimestamp);
        if(buttons[i].pressed())
            foundPressed = true;
    }
    return foundPressed;
}

template<size_t BTN_COUNT>
void ButtonsDriver<BTN_COUNT>::Button::update(unsigned long timeStamp)
{
    bool newState = adapter->readState();
    if(!state && newState)
        pressStart = timeStamp;
    state = newState;
    _pressed = state && timeStamp - pressStart > ButtonsDriver::maxBounceDurationMs;
}

template<size_t BTN_COUNT>
bool ButtonsDriver<BTN_COUNT>::Button::down()
{
    return state;
}

template<size_t BTN_COUNT>
bool ButtonsDriver<BTN_COUNT>::Button::pressed()
{
    return _pressed;
}