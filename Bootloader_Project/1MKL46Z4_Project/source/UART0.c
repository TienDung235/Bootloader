#include "MKL46Z4.h"
#include<stdint.h>
#include "clock.h"
#include "Init.h"
#include "UART0.h"

extern uint8_t g_buffer_u8[100];
extern uint8_t g_ReadFlag_u8;
extern uint32_t g_clock_u32;
extern uint32_t g_realBaudrate_u32;

void init_UART0(){
    /*PEE*/
	OSC0->CR    |= OSC_CR_ERCLKEN_MASK;
	SIM->SOPT2  |= SIM_SOPT2_UART0SRC(2);
//	  SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL(1);
//	    SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);
    SIM->SCGC4  |= SIM_SCGC4_UART0(1);
    SIM->SCGC5  |= SIM_SCGC5_PORTA(1);
    PORTA->PCR[1] |=PORT_PCR_MUX(2);
    PORTA->PCR[2] |=PORT_PCR_MUX(2);
    UART0->C2   |= UART0_C2_TE(1);
    UART0->C2   |= UART0_C2_RE(1);
}
void UART_WriteString(uint8_t *data_u8) {
    volatile uint8_t index_u8;

    for(index_u8 = 0; data_u8[index_u8] != '\r'; index_u8++) {
        while(!(UART0->S1 & UART_S1_TDRE_MASK)) {
            __asm("nop");
        }
        UART0->D = data_u8[index_u8];
    }

    while(!(UART0->S1 & UART_S1_TDRE_MASK)) {
        __asm("nop");
    }
    UART0->D = '\r';

    while(!(UART0->S1 & UART_S1_TDRE_MASK)) {
        __asm("nop");
    }
    UART0->D = '\n';
}


void Config_Baudrate(uint32_t desire_Baudrate , uint8_t* Sele_OSR , uint32_t* Sele_SBR){
    uint32_t SBR;
    uint32_t SBR1;
    uint32_t Error_SBR_u32;
    uint32_t Error_SBR1_u32;
    uint32_t Real_Baudrate_u32 = 0;
    uint32_t BestError_u32 = 0xFFFFFFFF;
    uint32_t Select_OSR_u32 =0;
    uint32_t Select_SBR_u32 =0;
    uint32_t index = 0;
    uint32_t tempError_u32;
    uint32_t tempSBR_u32;

    for(index = 4; index < 32 ; index ++){
        SBR  = (g_clock_u32 / desire_Baudrate ) / (index + 1);
        SBR1 = SBR + 1;

        Real_Baudrate_u32 = g_clock_u32 / (SBR* (index + 1));
        Error_SBR_u32 = Real_Baudrate_u32 - desire_Baudrate;

        Real_Baudrate_u32 = g_clock_u32 / (SBR1* (index + 1));
        Error_SBR1_u32 = desire_Baudrate - Real_Baudrate_u32;

        if(Error_SBR1_u32 < Error_SBR_u32){
            tempError_u32 = Error_SBR1_u32;
            tempSBR_u32 = SBR1;
        }
        else{
            tempError_u32 = Error_SBR_u32;
            tempSBR_u32 = SBR;
        }
        if( (tempError_u32 < BestError_u32) && (tempSBR_u32 < ( 2 << 13))){
            BestError_u32 = tempError_u32;
            Select_SBR_u32 = tempSBR_u32;
            Select_OSR_u32 = index;
            g_realBaudrate_u32 = g_clock_u32 /(Select_SBR_u32*(Select_OSR_u32 +1));
        }
    }
    *Sele_OSR = Select_OSR_u32;
    *Sele_SBR = Select_SBR_u32;
}

void UART0_Baudrate(uint8_t OSR , uint32_t SBR){

    UART0->BDH &= ~UART0_BDH_SBR_MASK;
    UART0->BDH |= SBR >> 8;
    UART0->BDL = SBR & 0xFF;
    UART0->C4  = OSR;
}
__attribute__((section(".ramfunc")))void PrintfString(char data[])
{
    uint8_t index;
    for(index = 0; data[index] != '\0';index++){

    while((UART0->S1 & UART_S1_TDRE_MASK) != UART_S1_TDRE_MASK)
        {
        }
        UART0->D = data[index];
    }
}
uint32_t str_to_int(uint8_t* str){
    uint32_t res_u32 =0;
    uint8_t index =0;
    while(str[index + 1] !=0){
        res_u32 = res_u32 * 10 + (str[index] - '0');
       index++;
    }
    return res_u32;
}

void sendnumber(uint32_t number_u32)
{
    uint8_t buffer[10];
    uint8_t index = 0;
    int8_t index2 ;
    int index3;

    while(number_u32 != 0){
        buffer[index] = number_u32 % 10;
        number_u32 /= 10;
        index ++;
    }
    for(index2 = (index - 1); index2 >= 0; index2 --)
    {
        while((UART0->S1 & UART_S1_TDRE_MASK) != UART_S1_TDRE_MASK)
        {
        }
        UART0->D = (buffer[index2] + 48) ;

    }
    for(index3 = 0; index3 <10000; index3++){
               __asm("nop");
    }
}
