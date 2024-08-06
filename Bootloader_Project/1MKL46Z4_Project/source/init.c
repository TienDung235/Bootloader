/***************************************************************************************************
 * Include
 **************************************************************************************************/
#include "Kl46.h"
#include<stdint.h>
#include "clock.h"
#include "Init.h"
#include "UART0.h"
/***************************************************************************************************
 * Variables
***************************************************************************************************/
/***************************************************************************************************
 * Function
***************************************************************************************************/
void initLed()
{
    /* Enable clock for PORTD, PORTE, PORTC */
    ENABLE_CLOCK_PORTD;    /* Set bit 12 */
    ENABLE_CLOCK_PORTE;    /* Set bit 13 */
    ENABLE_CLOCK_PORTC;    /* Set bit 13 */

    PTD5_MUX4;
    PTE29_MUX3;

    /* Button C12 */
    BUTTONC12_MUX;
    /*PS = 1, PE =1*/
    BUTTONC12_Pe_Ps;

    BUTTONC3_MUX;
    BUTTONC3_Pe_Ps;

    /* cho phep ngat suon xuong*/
    PORT_PCR12_IRQR;
    PORT_PCR3_IRQR;


    /* Configure PTD5 and PTE29 as output */
    PTD5_Output;
    PTE29_Output;
    /* PTC3 is input */
    PTC3_Input;

    /* Clear PTD5 and PTE29 */
    RED_LED_ON;
    GREEN_LED_ON;
}
void init_Systick_timer(uint32_t tick_hz){
    /*xoa 24 bit*/
    *(uint32_t*)Systick_RVR &=~(0x00FFFFFFFF);
    /*ghi vao CsR*/
    *(uint32_t*)Systick_RVR |= tick_hz;

    *(uint32_t*)Systick_CSR |= (1 << 1);
    *(uint32_t*)Systick_CSR |= (1 << 2);
    *(uint32_t*)Systick_CSR |= (1 << 0);

}
void init_TPM0(){
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
    SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL(0);
    SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;
    TPM0_SC   |= TPM_SC_CPWMS(1);
    TPM0_SC   |= TPM_SC_CMOD(1);
    /*period = Fll(22.8MHz) / 2*500 Hz */
    TPM0_MOD  = 22875;
    TPM0_CONF = TPM_CONF_DBGMODE_MASK;
    /*edge aligne pwm polarity = LOW*/
    TPM0_C2SC = 0x24;
    TPM0_C5SC = 0x24;
}

void init_PIT(){
    SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
    PIT_MCR   &=~PIT_MCR_MDIS_MASK;
    PIT_CHANNEL0_LDVAL = 105000;
    PIT_CHANNEL0_TCTRL = 3;
}
