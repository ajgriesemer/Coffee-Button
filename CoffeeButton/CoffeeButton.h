// This #include statement was automatically added by the Particle IDE.
#include "InternetButton.h"


class CoffeeButton : public InternetButton
{
    //Explicitly declare using buttonOn so the declaration here only overloads the method, but doesn't hide it
    //using InternetButton::buttonOn;
    public:
        uint8_t countButtonsOn(void);
        uint8_t anyButtonOn(void);
        uint8_t buttonOn(uint8_t i);
        uint8_t top = 4;
        uint8_t left = 5;
        uint8_t bottom = 6;
        uint8_t right = 7;
};
