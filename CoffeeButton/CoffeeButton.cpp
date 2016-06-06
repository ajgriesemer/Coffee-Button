#include "application.h"

#include "CoffeeButton.h"


uint8_t CoffeeButton::countButtonsOn(void)
{
    uint8_t buttons_on = 0;
    buttons_on += buttonOn(top);
    buttons_on += buttonOn(left);
    buttons_on += buttonOn(right);
    buttons_on += buttonOn(bottom);
    return buttons_on;
}

uint8_t CoffeeButton::anyButtonOn(void)
{
    if(countButtonsOn())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint8_t CoffeeButton::buttonOn(uint8_t i){
    if((i>=4) && (i<=7))
        return !digitalRead(i);
    else
        return 0;
}
