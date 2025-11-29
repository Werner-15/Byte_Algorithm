/**
*@file	Byte_Algorithm.h
*@author	Werner17
*@version	0.2
*@date	Nov-28-2025
*@brief	This file tries to manipulate bytes.
*		0.2 Update:Added some calculation functions and comments.
*/
#ifndef __BYTE_ALGORITHM_H__
#define __BYTE_ALGORITHM_H__

#include <stdint.h>

typedef enum Byte_Algorithm_Error_Type{
	Byte_Algorithm_Error_N_over_7=1,
	Byte_Algorithm_Error_Bits_Setting_Overflow=2,
	Byte_Algorithm_Error_Length_Illegal=4,
	Byte_Algorithm_Error_Start_Bit_Illegal=8,
	Byte_Algorithm_Error_Total_Length_over_8=16
} Byte_Algorithm_Error_Type;


uint8_t getLSB(uint8_t byte);
uint8_t getMSB(uint8_t byte);
uint8_t setLSB(uint8_t byte);
uint8_t resetLSB(uint8_t byte);
uint8_t setMSB(uint8_t byte);
uint8_t resetMSB(uint8_t byte);
uint8_t flipLSB(uint8_t byte);
uint8_t flipMSB(uint8_t byte);
uint8_t getBitN(uint8_t byte,uint8_t n);
uint8_t setBitN(uint8_t byte,uint8_t n);
uint8_t resetBitN(uint8_t byte,uint8_t n);
uint8_t flipBitN(uint8_t byte,uint8_t n);
uint8_t Byte_Algorithm_check_Error(void);
void Byte_Algorithm_clear_Error(void);
uint8_t writeBits(uint8_t byte,uint8_t start_bit, \
uint8_t length,uint8_t value);
uint8_t getBits(uint8_t byte,uint8_t start_bit,uint8_t length);
uint8_t isPowerOf2(int32_t num);
uint8_t isOdd(int32_t num);

#endif
