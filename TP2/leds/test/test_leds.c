/*
1-Al iniciar la biblioteca todos los leds quedan apagados
2-Con todos los leds apagados, prendo el led 2, verifico que el bit 1 vale1
3-Con el led 2 prendido, apago el led2, verifico que se enciende el bit1 vale 0
4-Con todos los les pagados, prendo el 3, prendo el 5, apago el 3 y apago el 7
Deberian quedar el bit 4 en 1 y el resto en 0
5-Prendo un led, consulto el estado y tiene que estar prendido
6-Apago un led, consulto el estado y tiene que estar apagado.
7-Con todos los leds apagados, prendo todos los leds y verffico que se enciende
8-Con todos los leds prendidos, apago todos los leds y verifico que se apaguen
9- Revisar los valores limites de los argumentos
10- Revisar que pasa con los valores erroneos en los argumentos
*/

#include "unity.h"
#include <stdint.h>
#include "leds.h"


static uint16_t puerto_virtual;

void setUp(void){
    ledsInit(&puerto_virtual);
    
}
//1-Al iniciar la biblioteca todos los leds quedan apagados

void test_todos_los_leds_inician_apagados(void){
    uint16_t puerto_virtual=0xffff;
    ledsInit(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puerto_virtual);


}

//2-Con todos los leds apagados, prendo el led 2, verifico que el bit 1 vale1

void test_prender_un_led(void){
    ledsTurnOnSingle(2);
    TEST_ASSERT_EQUAL_HEX16(0x0002,puerto_virtual);
}
//3-Con el led 2 prendido, apago el led2, verifico que se enciende el bit1 vale 0

void test_prender_y_apagar_un_led(void){
    ledsTurnOnSingle(2);
    ledsTurnOffSingle(2);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puerto_virtual);
}

//4-Con todos los les pagados, prendo el 3, prendo el 5, apago el 3 y apago el 7

void test_prender_y_apagar_varios_leds (void){

    ledsTurnOnSingle(3);
    ledsTurnOnSingle(5);
    ledsTurnOffSingle(3);
    ledsTurnOffSingle(7);
    TEST_ASSERT_EQUAL_HEX16(0x0010,puerto_virtual);

}
//5-Prendo un led, consulto el estado y tiene que estar prendido

void test_prender_y_consultar_mismo_led(void){
    ledsTurnOnSingle(6);
    TEST_ASSERT_EQUAL_HEX16(0x0020,puerto_virtual);


}
//6-Apago un led, consulto el estado y tiene que estar apagado.

void test_apagar_y_consultar_mismo_led (void){
    ledsTurnOffSingle(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puerto_virtual);

}
//7-Con todos los leds apagados, prendo todos los leds y verffico que se enciende

void test_prender_todos_y_verificar_todos_encendidos (void){
    ledsTurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,puerto_virtual);

}
//8-Con todos los leds prendidos, apago todos los leds y verifico que se apaguen

void test_apagar_todos_y_verificar_todos_apagados (void){
    ledsTurnOnAll();
    ledsTurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000,puerto_virtual);

}
//9- Revisar los valores limites de los argumentos

void test_prender_1er_led (void){
    ledsTurnOnSingle(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001,puerto_virtual);


}

void test_apagar_1er_led (void){
    ledsTurnOnSingle(1);
    ledsTurnOffSingle(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puerto_virtual);


}

void test_prender_ultimo_led (void){
    ledsTurnOnSingle(16);
    TEST_ASSERT_EQUAL_HEX16(0x8000,puerto_virtual);

}

void test_apagar_ultimo_led (void){
    ledsTurnOnSingle(16);
    ledsTurnOffSingle(16);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puerto_virtual);

}
//10- Revisar que pasa con los valores erroneos en los argumentos

void test_probar_parametro_erroneo (void){
    ledsTurnOnSingle(3);
    ledsTurnOnSingle(-3);
    ledsTurnOnSingle(20);
    TEST_ASSERT_EQUAL_HEX16(0x0004,puerto_virtual);
}