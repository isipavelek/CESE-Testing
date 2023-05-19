

#include "leds.h"

static uint16_t *puerto;
#define OFFSETLED 1
#define FIRSTBIT 1
#define FIRSTLED 1
#define LASTLED 16
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON ~ALL_LEDS_OFF


#define LED_VALIDO(x) (x>=FIRSTLED && x<=LASTLED)
#define LED(x) (FIRSTBIT<<(x-OFFSETLED))

void ledsInit(uint16_t * direccion){
    puerto=direccion;
    *puerto=ALL_LEDS_OFF;

}

void ledsTurnOnSingle(uint8_t led){
    if(LED_VALIDO(led))*puerto |= LED(led);

}

void ledsTurnOffSingle(uint8_t led){
    if(LED_VALIDO(led))*puerto &= ~LED(led);

}

void ledsTurnOnAll(void){
    *puerto = ALL_LEDS_ON;

}

void ledsTurnOffAll(void){
    *puerto = ALL_LEDS_OFF;

}




