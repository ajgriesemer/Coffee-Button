// This #include statement was automatically added by the Particle IDE.
#include "CoffeeButton.h"

#include <string.h>

#define DEBOUNCE_TIME 3000
#define LED_ON_TIME

//CoffeeButton coffee;
CoffeeButton b;

uint8_t state = 1;
double uptime = 0;

unsigned long last_push;
uint8_t led_number;
String notes[6]  = {"E5", "G5", "E6", "C6", "D6", "G6"};
uint8_t i;
void setup() {
    b.begin();
    last_push = millis();
    Particle.variable("uptime", uptime);
}

void loop() {
  //If any button is pressed
  if(b.buttonOn(1))
  {
    if(millis() > last_push + DEBOUNCE_TIME)
    {
        led_number = 1;
        for(i=0; i<6; i++)
        {
            b.ledOn(led_number, random(255), random(255), random(255));
            b.playNote(notes[i],8);
            b.ledOff(led_number);
            led_number += 1;
        }
        Spark.publish("coffee", "Fresh coffee in the kitchen", 60, PRIVATE);
        last_push = millis();
    }
  }
  uptime = millis() / 1000.0;
}
