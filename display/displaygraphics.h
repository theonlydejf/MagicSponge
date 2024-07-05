#ifndef DISPLAY_GRAPHICS_H
#define DISPLAY_GRAPHICS_H

#include "display.h"

constexpr uint8_t DECIMAL_POINT = 0b00000001;
constexpr uint8_t DIGIT_OFF = 0;

constexpr struct { char character; uint8_t segments; } FONT[] = 
{
    { '0', 0b11111100 },
    { '1', 0b01100000 },
    { '2', 0b11011010 },
    { '3', 0b11110010 },
    { '4', 0b01100110 },
    { '5', 0b10110110 },
    { '6', 0b10111110 },
    { '7', 0b11100000 },
    { '8', 0b11111110 },
    { '9', 0b11110110 },
    { 'A', 0b11101110 },
    { 'b', 0b00111110 },
    { 'c', 0b00011010 },
    { 'd', 0b01111010 },
    { 'E', 0b10011110 },
    { 'F', 0b10001110 },
    // G
    { 'H', 0b01101110 },
    { 'i', 0b00100000 },
    { 'J', 0b01111000 },
    // K
    { 'L', 0b00011100 },
    // M
    { 'n', 0b00101010 },
    { 'o', 0b00111010 },
    { 'P', 0b11001110 },
    // Q
    // R
    { 'S', 0b10110110 },
    { 't', 0b00011110 },
    { 'U', 0b01111100 },
    // V
    // W
    // X
    { 'Y', 0b01100110 },
    // Z

    { 'C', 0b10011100 },
    { 'h', 0b00101110 },
    { 'I', 0b01100000 },
    { 'N', 0b11101100 },
    { 'O', 0b11111100 },
    { 'u', 0b00111000 }
};
constexpr size_t FONT_CHAR_CNT = sizeof(FONT) / sizeof(FONT[0]);

bool showNum(DisplayDriver& driver, int num, int base = 10);

// returns 0 if invalid
uint8_t getCharSegments(char c);

bool showStr(DisplayDriver& driver, const char* str);

#endif /* DISPLAY_GRAPHICS_H */