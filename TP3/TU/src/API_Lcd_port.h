/*
 * API_LCDport.h
 *
 *  Created on: 25 mar. 2023
 *      Author: ipave
 */


#include <stdint.h>
#include <stdbool.h>


_Bool LCD_HW_init(void);
void LCD_Write_Byte(uint8_t valor);
void HAL_Delay(uint32_t Delay);


