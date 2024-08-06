/***************************************************************************************************
 * Include
***************************************************************************************************/
#include "MKL46Z4.h"
#include<stdint.h>
#include "clock.h"
#include "Init.h"
#include "UART0.h"
#include "Ring_buffe.h"
/***************************************************************************************************
 * Variables
***************************************************************************************************/
uint8_t g_Ring_Buffer[Row_RingBuffer][Colum_RingBuffer];
uint8_t g_RingSize_u8 = 0;
uint8_t g_IndexSrec_u8 = 0;
uint32_t g_readIndex_u32 = 0;
uint32_t g_writeIndex_u32 = 0;

/***************************************************************************************************
 * Definitions
***************************************************************************************************/
/***************************************************************************************************
 * Prototypes
***************************************************************************************************/

uint8_t *getReadAddress(){
	uint8_t *address_u8;
	address_u8 = g_Ring_Buffer[g_readIndex_u32];
	return address_u8;
}

__attribute__((section(".ramfunc")))uint8_t *getWriteAddress(){
	uint8_t *address_u8;
	address_u8 = g_Ring_Buffer[g_writeIndex_u32];
	return address_u8;
}
void Increace_Read_Data(){
	if(g_readIndex_u32 >= (Row_RingBuffer - 1)){
		g_readIndex_u32 = 0;
	}
	else{
		g_readIndex_u32 ++;
	}
	g_RingSize_u8 -- ;
}

__attribute__((section(".ramfunc")))void Increace_Write_Data(){
	if(g_writeIndex_u32 >= (Row_RingBuffer - 1)){
		g_writeIndex_u32 = 0;
	}
	else{
		g_writeIndex_u32 ++;
	}
	g_RingSize_u8 ++ ;
}

__attribute__((section(".ramfunc")))uint8_t RingBuffer_CheckFull(){
	uint8_t result_u8 = NO;
	if( g_RingSize_u8 > Row_RingBuffer){
		g_readIndex_u32 = 0;
		result_u8 = OK;
	}
	return result_u8;
}

uint8_t RingBuffer_CheckEmpty(){
	uint8_t result_u8 = NO;
	if(g_RingSize_u8 == 0){
		result_u8 = OK;
	}
	return result_u8;
}
/***************************************************************************************************
 * EOF
***************************************************************************************************/



