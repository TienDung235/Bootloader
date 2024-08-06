/***************************************************************************************************
 * Include
***************************************************************************************************/
#include "MKL46Z4.h"
#include<stdint.h>
#include "clock.h"
#include "Init.h"
#include "UART0.h"

/***************************************************************************************************
 * Variables
***************************************************************************************************/
/***************************************************************************************************
 * Definitions
***************************************************************************************************/
/***************************************************************************************************
 * Prototypes
***************************************************************************************************/
void Delete_Flash(uint32_t address_u32) {
	FTFA->FCCOB0 = 0x09;
	FTFA->FCCOB1 = (address_u32 >> 16) & 0xFF;
	FTFA->FCCOB2 = (address_u32 >> 8) & 0xFF;
	FTFA->FCCOB3 =  address_u32 & 0xFF;
	//__asm volatile ("cpsid i");
	FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;
    while((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0);
    //__asm volatile ("cpsie i");
}


void Flash_WritePage(uint32_t address_u32, uint8_t data[])
{
        FTFA->FCCOB0 = 0x06;
        /* Write Flash Address */
        FTFA->FCCOB1 = (uint8_t)(address_u32 >> 16);
        FTFA->FCCOB2 = (uint8_t)(address_u32 >> 8);
        FTFA->FCCOB3 = (uint8_t)address_u32;
        /* Write data */
        FTFA->FCCOB7 = data[0];
        FTFA->FCCOB6 = data[1];
        FTFA->FCCOB5 = data[2];
        FTFA->FCCOB4 = data[3];
        /* Writing a 1 to CCIF to launch a command */
       // __asm volatile ("cpsid i"); /* Disable Interrupt */
        FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;
        while((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0);
        //__asm volatile ("cpsie i"); /* re-enable Interrupt */
}

/* The address must be divisible by 4 */
void Flash_Write(uint32_t address_u32, uint8_t data[], uint16_t numByte_u16)
{
    uint16_t index_u16 = 0;

    for(index_u16 = 0; index_u16 < numByte_u16; index_u16 += 4u)
    {
        Flash_WritePage(address_u32, data);
        address_u32 += 4u;
        data += 4u;
    }

}
/***************************************************************************************************
 * EOF
***************************************************************************************************/
