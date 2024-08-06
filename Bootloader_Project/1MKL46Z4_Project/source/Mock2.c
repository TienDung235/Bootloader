/***************************************************************************************************
 * Include
 **************************************************************************************************/
#include "MKL46Z4.h"
#include<stdint.h>
#include "clock.h"
#include "Init.h"
#include "UART0.h"
#include "Ring_buffe.h"
#include "Flash.h"
#include "programme.h"


/***************************************************************************************************
 * Variables
***************************************************************************************************/
uint32_t g_clock_u32 =0;
uint8_t g_buffer_u8[100];
volatile uint8_t g_ReadFlag_u8 = 0;
uint32_t g_realBaudrate_u32 =0;
volatile uint8_t g_status_u8 = START;
/***************************************************************************************************
 * Prototypes
***************************************************************************************************/

/***************************************************************************************************
 * Main
 **************************************************************************************************/

void main()
{
    uint8_t  OSR  = 0;
    uint32_t SBR = 0;
    uint32_t counter = 0;
    initLed();
    clockConfig_type clock_FBE ={ FBE,0,0,0,0,0};

    //clockConfig_type clock_PEE ={ PEE,0,0,0,6,7};
    mode(clock_FBE);
    g_clock_u32 = GetCpuClockFrequency(clock_FBE);

    init_UART0();
    Config_Baudrate(1000000,&OSR,&SBR);
    UART0_Baudrate(OSR, SBR);
    UART0->C2 |= UART0_C2_RIE_MASK;

    PrintfString("\r\nBAUDRATE START =  1000000");
    PrintfString("\r\nREAL BAUDRATE START: ");
    sendnumber(g_realBaudrate_u32);
    PrintfString("\r\n");
    /*UART0*/
    NVIC_EnableIRQ(12);
    /*Port C_D*/
    PrintfString("\r\nClick SW3 to go to BOOTLOADER. If the file is wrong, click RESET\r\n");

    while(counter < 5000000)
    {
        if(!(GPIOC->PDIR & (1 << 12)))
        {
            PrintfString("\r\n\r\n----------Bootloader----------\r\n");
            Run_Bootloader();
            if(g_status_u8 == ERROR){
                NVIC_SystemReset();
            }
            counter += 1000000;
            PrintfString("Wait 5 seconds to enter Application\r\n");
        }
        counter++;
    }

    PrintfString("\r\n\r\n----------Application----------\r\n");
    PrintfString("RESET !!");
    UART0->C2 = 0;
    Run_Application();

}



/***************************************************************************************************
 * EOF
 ***************************************************************************************************/
