/***************************************************************************************************
 * Include
***************************************************************************************************/
#include "MKL46Z4.h"
#include<stdint.h>
#include "clock.h"
#include "Init.h"
#include "UART0.h"
#include "srec.h"

/***************************************************************************************************
 * Variables
***************************************************************************************************/
uint8_t g_writableLine_u8[16];
/***************************************************************************************************
 * Definitions
***************************************************************************************************/
/***************************************************************************************************
 * Prototypes
***************************************************************************************************/
uint8_t strHex_to_int(uint8_t *str){
    uint8_t res_u32 =0;
    uint8_t index =0;
    uint8_t strHex_u8 =0;

    for(index = 0; index < 2; index ++){
    	if((str[index]>='0') && (str[index]<='9')){
    		strHex_u8 = str[index]- '0';
    	}
    	else if((str[index]>='A') && (str[index]<='F')){
    	    strHex_u8 = 10 + str[index]-'A';
    	}
    	res_u32 = res_u32 * 16 + strHex_u8;
    }
    return res_u32;
}

uint32_t check_sum(uint8_t *data){
    uint8_t hex[3];
    uint32_t sum_u32 =0;
    uint8_t *index;

    for(index = data + 2; *index !='\r' ;index += 2){

        /*Save 2 elements in the string into hex array*/
        hex[0] = *index;
        hex[1] = *(index+1);
        hex[2] = '\0';

        /*Convert from string to int*/
        sum_u32 += strHex_to_int(hex);
        }
     return sum_u32;
}

uint32_t check_byte(uint8_t *data){
    uint8_t hex[3];
    uint32_t byte_u32 =0;
    uint32_t count_u32 =0;
    uint8_t *ptr;

    /*The array stores 2 byte count elements*/
    hex[0] = *(data + 2);
    hex[1] = *(data + 3);
    hex[2] ='\0';
    byte_u32 += strHex_to_int(hex);

    /*Variable that counts the number of characters remaining after byte count*/
    for(ptr = data+4;*ptr!='\r';ptr++){
    	count_u32 ++;
    }
    /*1 byte count = 2 characters*/
    return byte_u32*2 == count_u32;
}
uint32_t getAddressSrec(uint8_t *rb)
{
    uint32_t address = 0;
    uint8_t hex1 = strHex_to_int(rb + 4);
    uint8_t hex2 = strHex_to_int(rb + 6);
    address = (hex1 << 8) | hex2;

    return address;
}


uint8_t* getdata(uint8_t *data_u8, uint8_t *len_u8) {

    uint8_t  lineIdx_u8   = 0u;
    uint8_t  lineLen_u8   = 0u;
    uint8_t  outputLen_u8 = 0u;
    uint8_t  temp_u8      = 0u;

    lineLen_u8 = strHex_to_int(data_u8 + 2) * 2 - 6u;
    while (lineIdx_u8 < lineLen_u8) {
        g_writableLine_u8[outputLen_u8] = strHex_to_int(data_u8 + lineIdx_u8 + 8);
        lineIdx_u8 += 2u;
        outputLen_u8++;
    }

    temp_u8 = outputLen_u8;
    if (temp_u8 % 4u != 0u) {
        temp_u8 = outputLen_u8 - (outputLen_u8 % 4u) + 4u;
    }

    *len_u8 = temp_u8;

    return g_writableLine_u8;
}

/***************************************************************************************************
 * EOF
***************************************************************************************************/


