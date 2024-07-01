#include "display.h"
#include "ardadapters.h"

ArdDisplayAdapter dispAdapter(2, 10);
DisplayDriver displayDriver(&dispAdapter);

void setup()
{
    Serial.begin(9600);

    for (uint8_t i = 2; i <= 13; i++)
    {
        pinMode(i, OUTPUT);
    }
    
    for (uint8_t i = 2; i <= 9; i++)
        digitalWrite(i, LOW);

    for (uint8_t i = 10; i <= 13; i++)
        digitalWrite(i, LOW);

    cli();
    TCCR1A = 0;
    TCCR1B = 0;

    TCCR1B |= 0b00000100;
    TIMSK1 |= 0b00000010;
    OCR1A = 30;
    sei();

    // for(int i = 0; i < 4; i++)
    //     displayDriver.setDigit(i, 0xFF);
}

void loop()
{
    displayDriver.setDigit(0, 0xF0);
    displayDriver.setDigit(1, 0x0F);
    displayDriver.setDigit(2, 0xF0);
    displayDriver.setDigit(3, 0x0F);
    delay(500);
    displayDriver.setDigit(1, 0xF0);
    displayDriver.setDigit(0, 0x0F);
    displayDriver.setDigit(3, 0xF0);
    displayDriver.setDigit(2, 0x0F);
    delay(500);
}

bool smth = false;

ISR(TIMER1_COMPA_vect)
{
    TCNT1 = 0;
    displayDriver.step();
}