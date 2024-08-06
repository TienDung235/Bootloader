/***************************************************************************************************
 * Include
***************************************************************************************************/
#include<stdint.h>
#include "clock.h"
#include "Init.h"
#include "UART0.h"
#include "Ring_buffe.h"
#include "Flash.h"
#include "programme.h"
#include "srec.h"
#include "MKL46Z4.h"

/***************************************************************************************************
 * Variables
***************************************************************************************************/
static uint32_t firstData = 0;
extern uint8_t g_status_u8;
/***************************************************************************************************
 * Definitions
***************************************************************************************************/
typedef void(*pFunction)(void);
__attribute__((section(".ramfunc")))void UART0_IRQHandler(void);
extern uint8_t g_writableLine_u8[];
uint32_t MyVectorTable[48] __attribute__ ((aligned (0x100)));

/***************************************************************************************************
 * Prototypes
***************************************************************************************************/

void My_VectorTable(){
	uint8_t index;
	uint32_t *ptr = 0x0000;
	for(index = 0; index < 48; index++){
		MyVectorTable[index] =*(ptr+index);
	}
	SCB->VTOR = (uint32_t)MyVectorTable;
}
void Run_Bootloader(){
	uint32_t index_u32;
	uint8_t *readAddress_u8;
	uint8_t length_u8 = 0;
	uint8_t temp;
	uint32_t count_u32 =0;
	uint32_t address = 0;
	My_VectorTable();
	for(index_u32 =0 ; index_u32 <=0x40000; index_u32 += 0x400){
		Delete_Flash(0x8000 + index_u32);
	}
	PrintfString("Send file Binary Srecord \r\n");
	while(g_status_u8 == START){
		temp = RingBuffer_CheckEmpty();
		if(!temp){
			count_u32 ++;
			if((check_byte(getReadAddress()) != 1) || ((check_sum(getReadAddress()) & 0xFF) != 0xFF)){
				PrintfString("\r\nERROR: CHECK BYTE AND CHECK SUM NUMBER LINE : ");
				sendnumber(count_u32);
				PrintfString("\r\n");
				PrintfString(getReadAddress());
				g_status_u8 = ERROR;
			}
			if(getReadAddress()[1] == '0'){
				Increace_Read_Data();
			}
			else if(getReadAddress()[1] == '9'){
			    Flash_Write(0x8000, &firstData, 4);
                g_status_u8 =  END;
            }
			else{
				if(g_status_u8 == ERROR){
					for(index_u32 =0 ; index_u32 <=0x40000; index_u32 += 0x400){
						Delete_Flash(0x8000 + index_u32);
					}
				}
				else{
			        address = getAddressSrec(getReadAddress());
					readAddress_u8 = getdata(getReadAddress(), &length_u8);
					Flash_Write(address, g_writableLine_u8, length_u8);

					if(address == 0x8000)
					{
					    g_status_u8 = START;
                        firstData = *(uint32_t*)g_writableLine_u8;
					}
					Increace_Read_Data();
				}

			}
		}
	}
}

__attribute__((section(".ramfunc")))void UART0_IRQHandler(void){
    uint8_t *writeAddress_u8 = 0;
    uint8_t writeByte_u8 = 0;
    uint8_t status_u8 = 0;
    static uint8_t index_u8 =0;

    status_u8 = RingBuffer_CheckFull();

    if(!status_u8 ){
        writeByte_u8 = UART0->D;
        writeAddress_u8 = getWriteAddress();
        writeAddress_u8 += index_u8;
        *(uint8_t*)writeAddress_u8 = writeByte_u8;
        if(writeByte_u8 == '\n'){
            Increace_Write_Data();
            index_u8 = 0;
        }
        else{
            index_u8 ++;
        }
    }
    else{
        PrintfString("ERROR: RING BUFFER FULL \r\n");
    }
}

void Run_Application(){
	  uint32_t resetAddress_u32 = 0;
	    pFunction jump_to_address;

	    __disable_irq();
	    /* Relocate exception vector table */
	    SCB->VTOR = MAIN_APP_ADDRESS;
	    /* Set main stack pointer */
	    __set_MSP(*(uint32_t*)MAIN_APP_ADDRESS);
	    /* Reset interrupt handler address */
	    resetAddress_u32 = *(uint32_t*)(MAIN_APP_ADDRESS + 4);
	    /* Call reset interrupt handler */
	    jump_to_address = (pFunction)(resetAddress_u32);
//	    __enable_irq();
	    /* Jump to application = set PC*/
	    jump_to_address();
}
/***************************************************************************************************
 * EOF
***************************************************************************************************/
