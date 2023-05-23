#include "unity.h"
#include "mock_API_Lcd_port.h"
#include "mock_API_I2C.h"
#include "API_lcd.h"


#define valor_1(x) ((x&0xf0)+EN+BL+DATOS)
#define valor_2(x) ((x&0xf0)+BL+DATOS)
#define valor_3(x) (((x&0x0f)<<4)+EN+BL+DATOS)
#define valor_4(x) (((x&0x0f)<<4)+BL+DATOS)

static uint8_t puerto_virtual[10];

void mock_LCD_Write (uint8_t valor,int num_calls){
    puerto_virtual[num_calls]=valor;
    
}

void test_inicializa_correctamente(void){
    _Bool res=0;
    I2C_HW_init_ExpectAndReturn(false);
    HAL_Delay_CMockIgnore();
    LCD_Write_Byte_CMockIgnore();
    res=Init_Lcd();
    TEST_ASSERT_EQUAL_HEX8(0x00, res);
}

void test_Envia4bitsLcd_envia(void){
    LCD_Write_Byte_StubWithCallback(mock_LCD_Write);
    HAL_Delay_CMockIgnore();
    DatoLcd(0x25);
    TEST_ASSERT_EQUAL_HEX8(valor_1(0x25), puerto_virtual[0]);
    TEST_ASSERT_EQUAL_HEX8(valor_2(0x25), puerto_virtual[1]);
    TEST_ASSERT_EQUAL_HEX8(valor_3(0x25), puerto_virtual[2]);
    TEST_ASSERT_EQUAL_HEX8(valor_4(0x25), puerto_virtual[3]);

}

void test_DatoAsciiLcd_envia(void){
    LCD_Write_Byte_StubWithCallback(mock_LCD_Write);
    HAL_Delay_CMockIgnore();
    DatoAsciiLcd(2);
    TEST_ASSERT_EQUAL_HEX8(valor_1('2'), puerto_virtual[0]);
    TEST_ASSERT_EQUAL_HEX8(valor_2('2'), puerto_virtual[1]);
    TEST_ASSERT_EQUAL_HEX8(valor_3('2'), puerto_virtual[2]);
    TEST_ASSERT_EQUAL_HEX8(valor_4('2'), puerto_virtual[3]);

}

void test_SacaTextoLcd_envia(void){
    LCD_Write_Byte_StubWithCallback(mock_LCD_Write);
    HAL_Delay_CMockIgnore();
    SacaTextoLcd("Hi");
    TEST_ASSERT_EQUAL_HEX8(valor_1('H'), puerto_virtual[0]);
    TEST_ASSERT_EQUAL_HEX8(valor_1('i'), puerto_virtual[4]);

}

void test_DatoBCD_envia(void){
    LCD_Write_Byte_StubWithCallback(mock_LCD_Write);
    HAL_Delay_CMockIgnore();
    DatoBCD(0x25);
    TEST_ASSERT_EQUAL_HEX8(valor_1('2'), puerto_virtual[0]);
    TEST_ASSERT_EQUAL_HEX8(valor_1('5'), puerto_virtual[4]);

}
