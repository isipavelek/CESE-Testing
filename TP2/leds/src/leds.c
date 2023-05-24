#include "leds.h"

static uint16_t *puerto;
#define OFFSETLED 1
#define FIRSTBIT 1
#define FIRSTLED 1
#define LASTLED 16
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON ~ALL_LEDS_OFF

#define LED_VALID(x) (x >= FIRSTLED && x <= LASTLED)
#define SHIFT(x) (x - OFFSETLED)
#define LED(x) (FIRSTBIT << (SHIFT(x)))
#define BRING_LED_STATE(x) (((*puerto)&LED(led))>>(SHIFT(led)))

void ledsInit(uint16_t *direccion) {
    puerto = direccion;
    ledsTurnOffAll();
}

void ledsTurnOnSingle(uint8_t led) {
    if (LED_VALID(led))*puerto |= LED(led);
}

void ledsTurnOffSingle(uint8_t led) {
    if (LED_VALID(led))*puerto &= ~LED(led);
}

void ledsTurnOnAll(void) { 
    *puerto = ALL_LEDS_ON; 
}

void ledsTurnOffAll(void) {
    *puerto = ALL_LEDS_OFF; 
}

uint8_t ledsIsOnSingle(uint8_t led) {
    if (LED_VALID(led))return (BRING_LED_STATE(led));
}

uint8_t ledsIsOffSingle(uint8_t led) {
    if (LED_VALID(led))return (BRING_LED_STATE(led)^FIRSTBIT);
}