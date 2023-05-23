#include "src/API_lcd.h"
#include "build/test/mocks/mock_API_I2C.h"
#include "build/test/mocks/mock_API_Lcd_port.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"














static uint8_t puerto_virtual[10];



void mock_LCD_Write (uint8_t valor,int num_calls){

    puerto_virtual[num_calls]=valor;



}



void test_inicializa_correctamente(void){

    _Bool res=0;

    I2C_HW_init_CMockExpectAndReturn(21, 

   0

   );

    HAL_Delay_CMockIgnore();

    LCD_Write_Byte_CMockIgnore();

    res=Init_Lcd();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x00)), (UNITY_INT)(UNITY_INT8 )((res)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_HEX8);

}



void test_Envia4bitsLcd_envia(void){

    LCD_Write_Byte_Stub(mock_LCD_Write);

    HAL_Delay_CMockIgnore();

    DatoLcd(0x25);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((((0x25&0xf0)+(1<<2)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[0])), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((((0x25&0xf0)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[1])), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((((0x25&0x0f)<<4)+(1<<2)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[2])), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((((0x25&0x0f)<<4)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[3])), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX8);



}



void test_DatoAsciiLcd_envia(void){

    LCD_Write_Byte_Stub(mock_LCD_Write);

    HAL_Delay_CMockIgnore();

    DatoAsciiLcd(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((('2'&0xf0)+(1<<2)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[0])), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((('2'&0xf0)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[1])), (

   ((void *)0)

   ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((((('2'&0x0f)<<4)+(1<<2)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[2])), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((((('2'&0x0f)<<4)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[3])), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_HEX8);



}



void test_SacaTextoLcd_envia(void){

    LCD_Write_Byte_Stub(mock_LCD_Write);

    HAL_Delay_CMockIgnore();

    SacaTextoLcd("Hi");

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((('H'&0xf0)+(1<<2)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[0])), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((('i'&0xf0)+(1<<2)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[4])), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX8);



}



void test_DatoBCD_envia(void){

    LCD_Write_Byte_Stub(mock_LCD_Write);

    HAL_Delay_CMockIgnore();

    DatoBCD(0x25);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((('2'&0xf0)+(1<<2)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[0])), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((('5'&0xf0)+(1<<2)+(1<<3)+1))), (UNITY_INT)(UNITY_INT8 )((puerto_virtual[4])), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX8);



}
