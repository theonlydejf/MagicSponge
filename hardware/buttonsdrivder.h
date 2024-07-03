#ifndef BUTTONS_DRIVER_H
#define BUTTONS_DRIVER_H

#include "adapters.h"

template<size_t BTN_COUNT>
class ButtonsDriver
{
public:
    ButtonsDriver(ButtonAdapter* adapters, TimeAdapter* timeAdapter,
        unsigned maxBounceDuration = 50);

    void update();
    const Button& getButton(size_t id) { return buttons[id]; }

    class Button
    {
    public:
        bool down();
        bool pressed();
        bool risingEdgeFiltered();
    private:
        ButtonAdapter* adapter;

        Button(ButtonAdapter* adapter) : adapter(adapter) {}

        void update(unsigned long timeStamp);
    }
private:
    Button buttons[BTN_COUNT];
    TimeAdapter* timeAdapter;
    unsigned maxBounceDuration;
};

#endif /* BUTTONS_DRIVER_H */