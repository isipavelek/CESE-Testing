#include "src/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






static uint16_t puerto_virtual;



void setUp(void){

    ledsInit(&puerto_virtual);



}





void test_todos_los_leds_inician_apagados(void){

    uint16_t puerto_virtual=0xffff;

    ledsInit(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_HEX16);





}







void test_prender_un_led(void){

    ledsTurnOnSingle(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_un_led(void){

    ledsTurnOnSingle(2);

    ledsTurnOffSingle(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_HEX16);

}







void test_prender_y_apagar_varios_leds (void){



    ledsTurnOnSingle(3);

    ledsTurnOnSingle(5);

    ledsTurnOffSingle(3);

    ledsTurnOffSingle(7);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);



}





void test_prender_y_consultar_mismo_led(void){

    ledsTurnOnSingle(6);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0020)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX16);





}





void test_apagar_y_consultar_mismo_led (void){

    ledsTurnOffSingle(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX16);



}





void test_prender_todos_y_verificar_todos_encendidos (void){

    ledsTurnOnAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_HEX16);



}





void test_apagar_todos_y_verificar_todos_apagados (void){

    ledsTurnOnAll();

    ledsTurnOffAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_HEX16);



}





void test_prender_1er_led (void){

    ledsTurnOnSingle(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0001)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_HEX16);





}



void test_apagar_1er_led (void){

    ledsTurnOnSingle(1);

    ledsTurnOffSingle(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_HEX16);





}



void test_prender_ultimo_led (void){

    ledsTurnOnSingle(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_HEX16);



}



void test_apagar_ultimo_led (void){

    ledsTurnOnSingle(16);

    ledsTurnOffSingle(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_HEX16);



}





void test_probar_parametro_erroneo (void){

    ledsTurnOnSingle(3);

    ledsTurnOnSingle(-3);

    ledsTurnOnSingle(20);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0004)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_HEX16);

}
