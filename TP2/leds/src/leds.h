#ifndef LEDS_H
#define LEDS_H
#include<stdint.h>

void ledsInit(uint16_t * direccion);
void ledsTurnOnSingle(uint8_t led);
void ledsTurnoffSingle(uint8_t led);
void ledsTurnOnAll(voi);
void ledsTurnOffAll(void);
uint8_t ledsIsOnSingle(uint8_t led);
uint8_t ledsIsOffSingle(uint8_t led);

#endif