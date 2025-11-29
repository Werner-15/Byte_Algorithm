/**
*@file	Byte_Algorithm.c
*@author	Werner17
*@version	0.2
*@date	Nov-28-2025
*@brief	This file tries to manipulate bytes.
*		0.2 Update:Added some calculation functions and comments.
*/

#include "Byte_Algorithm.h"

/**
 *   This variable is intended to record errors appear during the 
 * functions used.
 * 
 *   Each error code is the power of 2,in order to record many
 * errors with one variable.
 * 
 *   Why don't we just return the errors within the functions?
 * This is because these functions are designed to be as
 * quick and convenient as possible.
 *   If we return the error code with functions,it will make the
 * functions harder to use ,as users may have to use a pointer
 * variable to get the results.
 *   When related to pointers ,
 * the module will be more complicated ,
 * which is neither quick nor elegant.
 *   So this variable is a compromise ,as it provides the users
 * with a safe interface while not contaminating the simplicity of
 * all functions.
 *   If errors occur,functions will return the original data byte.
 */
static Byte_Algorithm_Error_Type error_flag=0;

/**
 *@brief	This function gets the lowest bit(LSB) of the byte.
 *@param	byte:The byte to deal with.
 *@return	The lowest bit,it is either 0x00 or 0x01.
*/
uint8_t getLSB(uint8_t byte){
	return byte&1;
}

/**
 *@brief	This function gets the highest bit(MSB) of the byte.
 *@param	byte:The byte to deal with.
 *@return	The highest bit,it is either 0x00 or 0x01.
 */
uint8_t getMSB(uint8_t byte){
	return (byte>>7)&1;
}

/**
 *@brief	This function sets the lowest bit(LSB) of the byte.
 *@param	byte:The byte to deal with.
 *@return	The byte with its LSB set.
 */
uint8_t setLSB(uint8_t byte){
	return byte|1;
}

/**
 *@brief	This function resets the lowest bit(LSB) of the byte.
 *@param	byte:The byte to deal with.
 *@return	The byte with its LSB reset.
 */
uint8_t resetLSB(uint8_t byte){
	return byte&(~1);
}

/**
 *@brief	This function sets the highest bit(MSB) of the byte.
 *@param	byte:The byte to deal with.
 *@return	The byte with its MSB set.
 */
uint8_t setMSB(uint8_t byte){
	return byte|((uint8_t)128);
}

/**
 *@brief	This function resets the highest bit(MSB) of the byte.
 *@param	byte:The byte to deal with.
 *@return	The byte with its MSB reset.
 */
uint8_t resetMSB(uint8_t byte){
	return byte&(~((uint8_t)128));
}

/**
 *@brief	This function flips the lowest bit(LSB) of the byte.
 *@detail	flip means to turn 1 into 0,0 into 1.
 *@param	byte:The byte to deal with.
 *@return	The byte with its LSB flipped.
 */
uint8_t flipLSB(uint8_t byte){
	return byte^1;
}

/**
 *@brief	This function flips the highest bit(MSB) of the byte.
 *@detail	flip means to turn 1 into 0,0 into 1.
 *@param	byte:The byte to deal with.
 *@return	The byte with its MSB flipped.
 */
uint8_t flipMSB(uint8_t byte){
	return byte^128;
}

/**
 *@brief	This function gets the Nst/Nnd/Nrd/Nth bit of the byte.
 *@param	byte:The byte to deal with.
 *@param	n:The bit you want to get.n=0,1,2,3,4,5,6,7,
 *			while 0 means LSB,7 means MSB.
 *			Other values are invalid,and will cause a
 *			Byte_Algorithm_Error_N_over_7 error.
 *@return	The Nst/Nnd/Nrd/Nth bit of the byte,
 *			the return is either 0x00 or 0x01.
 */
uint8_t getBitN(uint8_t byte,uint8_t n){
	if(n>7){
		error_flag|=Byte_Algorithm_Error_N_over_7;
		return byte;
	}
	return ((byte>>n)&1);
}

/**
 *@brief	This function sets the Nst/Nnd/Nrd/Nth bit of the byte.
 *@param	byte:The byte to deal with.
 *@param	n:The bit you want to set.n=0,1,2,3,4,5,6,7,
 *			while 0 means LSB,7 means MSB.
 *			Other values are invalid,and will cause a
 *			Byte_Algorithm_Error_N_over_7 error.
 *@return	The byte with its Nst/Nnd/Nrd/Nth bit set.
 */
uint8_t setBitN(uint8_t byte,uint8_t n){
	if(n>7){
		error_flag|=Byte_Algorithm_Error_N_over_7;
		return byte;
	}
	return (byte|(1<<n));
}

/**
 *@brief	This function resets the Nst/Nnd/Nrd/Nth bit of the byte.
 *@param	byte:The byte to deal with.
 *@param	n:The bit you want to reset.n=0,1,2,3,4,5,6,7,
 *			while 0 means LSB,7 means MSB.
 *			Other values are invalid,and will cause a
 *			Byte_Algorithm_Error_N_over_7 error.
 *@return	The byte with its Nst/Nnd/Nrd/Nth bit reset.
 */
uint8_t resetBitN(uint8_t byte,uint8_t n){
	if(n>7){
		error_flag|=Byte_Algorithm_Error_N_over_7;
		return byte;
	}
	return (byte&(~(1<<n)));
}

/**
 *@brief	This function flips the Nst/Nnd/Nrd/Nth bit of the byte.
 *@detail	flip means to turn 1 into 0,0 into 1.
 *@param	byte:The byte to deal with.
 *@param	n:The bit you want to flip.n=0,1,2,3,4,5,6,7,
 *			while 0 means LSB,7 means MSB.
 *			Other values are invalid,and will cause a
 *			Byte_Algorithm_Error_N_over_7 error.
 *@return	The byte with its Nst/Nnd/Nrd/Nth bit flipped.
 */
uint8_t flipBitN(uint8_t byte,uint8_t n){
	if(n>7){
		error_flag|=Byte_Algorithm_Error_N_over_7;
		return byte;
	}
	return (byte^(1<<n));
}

/**
 * @brief This funtion tells you the current error flag.
 * 
 * @param void 
 * 
 * @return the current error flag.
 */
uint8_t Byte_Algorithm_check_Error(void){
	return error_flag;
}

/**
 * @brief This function tries to clear the error flag.
 * 
 * @param void 
 */
void Byte_Algorithm_clear_Error(void){
	error_flag=0;
}

/**
 * @brief This function allows you to change a few consecutive
 * 		bits while not changing others.
 * 
 * @param byte :The byte to operate.
 * @param length :The length of the changed bits,it should
 * 		be 1,2,3,4,5,6,7, or 8.
 * @param start_bit :The start of the bit sequence.
 * 		It should be 0,1,2,3,4,5,6, or 7.
 * 		While start_bit+length should be no more than 8.
 * @param value :The value to write into the field selected
 * 		by start_bit and length.
 * 		It should be from 0 to (2^length)-1.
 * 
 * @return It returns the operated byte.
 * 		Example:
 * 		byte = 01010101b;
 * 		start_bit = 1;
 * 		length = 3;
 * 		value = 6.
 * 		
 * 		index	:7	6	5	4	3	2	1	0
 * 		bit 	:0	1	0	1	0	1	0	1
 * 		startbit:						|	
 * 	endbit=startbit+length-1:	|
 * 
 * 		Then we write 6(110b) into the field(from index 1 to 3).
 * 
 * 		byte	:0	1	0	1[	0	1	0]	1
 * operated byte:0	1	0	1[	1	1	0]	1
 * 
 * Such that the return value is 01011101b.
 */
uint8_t writeBits(uint8_t byte,uint8_t start_bit, \
uint8_t length,uint8_t value){
	uint8_t maxvalue;
	uint8_t mask;
	uint8_t clear_mask;
	uint8_t cleared_byte;
	uint8_t moved_value;
	
	if(start_bit>=8){
		error_flag|=Byte_Algorithm_Error_Start_Bit_Illegal;
		return byte;
	}
	if(length>8 || length==0){
		error_flag|=Byte_Algorithm_Error_Length_Illegal;
		return byte;
	}
	if(start_bit+length>8){
		error_flag|=Byte_Algorithm_Error_Total_Length_over_8;
		return byte;
	}
	
	maxvalue = (1<<length)-1;
	if(value >  maxvalue){
		error_flag|=Byte_Algorithm_Error_Bits_Setting_Overflow;
		return byte;
	}
	
	
	mask = maxvalue<<start_bit;
	clear_mask = ~mask;
	cleared_byte = byte & clear_mask;
	moved_value = value<<start_bit;
	
	return cleared_byte|moved_value;
	
}


/**
 * @brief This function allows you to get a few consecutive
 * 		bits of a byte.
 * 
 * @param byte :The byte to operate.
 * @param length :The length of the target bits,it should
 * 		be 1,2,3,4,5,6,7, or 8.
 * @param start_bit :The start of the bit sequence.
 * 		It should be 0,1,2,3,4,5,6, or 7.
 * 		While start_bit+length should be no more than 8.
 * 
 * @return It returns the bits get,it is no more than (2^length)-1.
 * 		Example:
 * 		byte = 01010101b;
 * 		start_bit = 1;
 * 		length = 3;
 * 		
 * 		index	:7	6	5	4	3	2	1	0
 * 		bit 	:0	1	0	1	0	1	0	1
 * 		startbit:						|	
 * 	endbit=startbit+length-1:	|
 * 
 * 		Then we get the field(from index 1 to 3).
 * 
 * 		byte	:0	1	0	1[	0	1	0]	1
 * The ret value:010b
 * 
 * Such that the return value is 00000010b.
 */
uint8_t getBits(uint8_t byte,uint8_t start_bit,uint8_t length){
	
	uint8_t ret,mask;
	
	
	if(start_bit>=8){
		error_flag|=Byte_Algorithm_Error_Start_Bit_Illegal;
		return byte;
	}
	if(length>8 || length==0){
		error_flag|=Byte_Algorithm_Error_Length_Illegal;
		return byte;
	}
	if(start_bit+length>8){
		error_flag|=Byte_Algorithm_Error_Total_Length_over_8;
		return byte;
	}
	
	ret = byte>>start_bit;
	mask = 0xFF>>(8-length);
	ret&=mask;
	
	return ret;
}

/**
 * @brief The function figures out if the number is the power of 2.
 * 
 * @param num The number to check.
 * 
 * @return 1->true,0->false.
 */
uint8_t isPowerOf2(int32_t num){
	if((num>0) && ( (num&(num-1))==0 ) ){
		return 1;
	}
	else return 0;
	
}

/**
 * @brief The function figures out if the number is an odd number.
 * 
 * @param num The number to check.
 * 
 * @return 1->true,0->false.
 */
uint8_t isOdd(int32_t num){
	if(num&1)return 1;
	else return 0;
	
}

