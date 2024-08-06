#ifndef KL46_H_
#define KL46_H_
#include<stdint.h>
//#include"MKL46Z4.h"

/***************************************************************************************************
 * Macro
 **************************************************************************************************/
#define GPIOC_PDDR       *(volatile uint32_t*)(0x400FF094u)
#define GPIOC_PDIR       *(volatile uint32_t*)(0x400FF090u)
#define GPIOD_PCOR       *(volatile uint32_t*)(0x400FF0C8u)
#define GPIOD_PSOR       *(volatile uint32_t*)(0x400FF0C4u)
#define GPIOD_PTOR       *(volatile uint32_t*)(0x400FF0CCu)
#define GPIOD_PDDR       *(volatile uint32_t*)(0x400FF0D4u)
#define GPIOD_PDIR       *(volatile uint32_t*)(0x400FF0D0u)
#define GPIOE_PCOR       *(volatile uint32_t*)(0x400FF108u)
#define GPIOE_PSOR       *(volatile uint32_t*)(0x400FF104u)
#define GPIOE_PTOR       *(volatile uint32_t*)(0x400FF10Cu)
#define GPIOE_PDIR       *(volatile uint32_t*)(0x400FF110u)
#define GPIOE_PDDR       *(volatile uint32_t*)(0x400FF114u)

#define NVIC_ISER        (0xE000E100u)
#define NVIC_EnableIRQ(x) *(uint32_t *)NVIC_ISER |= (1 << (x))
#define PORTD_PCR5       *(volatile uint32_t*)(0x4004C014u)
#define PORTE_PCR29      *(volatile uint32_t*)(0x4004D074u)
#define PORTC_PCR3       *(volatile uint32_t*)(0x4004B00Cu)
#define PORTC_PCR12      *(volatile uint32_t*)(0x4004B030u)
#define PORTA_PCR1       *(volatile uint32_t*)(0x40049004u)
#define PORTA_PCR2       *(volatile uint32_t*)(0x40049008u)

#define SIM_SCGC5        *(volatile uint32_t*)(0x40048038u)
#define SIM_SCGC4        *(volatile uint32_t*)(0x40048034u)

#define GREEN_LED_ON     GPIOD_PCOR |= (1 << 5)
#define GREEN_LED_OFF    GPIOD_PSOR |= (1 << 5)
#define GREEN_LED_TOGGLE GPIOD_PTOR |= (1 << 5)
#define RED_LED_ON       GPIOE_PCOR |= (1 << 29)
#define RED_LED_OFF      GPIOE_PSOR |= (1 << 29)
#define RED_LED_TOGGLE   GPIOE_PTOR |= (1 << 29)
#define DELAY_COUNT      1333000UL
#define Proces_Clock     21000000U
#define SysTick_Clock    Proces_Clock
#define Systick_RVR      0xE000E014
#define Systick_CSR      0xE000E010
#define ENABLE_CLOCK_PORTC  SIM_SCGC5  |= (1 << 11)
#define ENABLE_CLOCK_PORTD  SIM_SCGC5  |= (1 << 12)
#define ENABLE_CLOCK_PORTE  SIM_SCGC5  |= (1 << 13)
#define PORT_PCR5_MUX       PORTD_PCR5 |= (1 << 8)
#define PORT_PCR29_MUX      PORTE_PCR29|= (1 << 8)
#define BUTTONC12_MUX       PORTC_PCR12 |= (1 << 8)
#define BUTTONC12_Pe_Ps     PORTC_PCR12 |= (1 << 1)|1
#define PORT_PCR_MUX_MASK   (0x700u)
#define PORT_PCR_MUX_SHIFT  (8u)
#define PORT_PCR_MUX(x)     (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)
#define PTD5_MUX4           *(uint32_t *)(0x4004C014u) |= PORT_PCR_MUX(4)
#define PTE29_MUX3          *(uint32_t *)(0x4004D074u) |= PORT_PCR_MUX(3)

#define BUTTONC3_MUX       PORTC_PCR3 |= (1 << 8)
#define BUTTONC3_Pe_Ps     PORTC_PCR3 |= (1 << 1)|1
#define PORT_PCR12_IRQR    PORTC_PCR12 |= (10 << 16);
#define PORT_PCR3_IRQR     PORTC_PCR3 |= (10 << 16);
#define PTD5_Output        GPIOD_PDDR |= (1 << 5);
#define PTE29_Output       GPIOE_PDDR |= (1 << 29);
#define PTC3_Input         GPIOC_PDDR &= ~(1 << 12)
#define PTC12_Input        GPIOC_PDDR &= ~(1 << 12)
#define ACTIVATE_PENDSV     *(uint32_t*)(0xE000ED04u) |= (1 << 28)
#define PORT_PCR_ISF_MASK   (0x1000000U)

#define MCG_C1              *(volatile uint32_t*)(0x40064000u)
#define MCG_C2              *(volatile uint8_t*)(0x40064001u)
#define MCG_C3              *(volatile uint32_t*)(0x40064002u)
#define MCG_C4              *(volatile uint8_t*)(0x40064003u)
#define MCG_C5              *(volatile uint32_t*)(0x40064004u)
#define MCG_C6              *(volatile uint8_t*)(0x40064005u)
#define MCG_S               *(volatile uint8_t*)(0x40064006u)
#define MCG_SC              *(volatile uint32_t*)(0x40064008u)
#define MCG_C1_IREFS_MASK   (0x4U)

#define MCG_C1_IREFS(x)  ((uint32_t)((uint32_t)(x)) << 2u)
#define MCG_C1_CLKS(x)   ((uint32_t)((uint32_t)(x)) << 6u)
#define MCG_C1_FRDIV(x)  ((uint32_t)((uint32_t)(x)) << 3u)

#define MCG_C2_IRCS(x)   ((uint32_t)((uint32_t)(x)) << 0u)
#define MCG_C2_EREFS0(x) ((uint32_t)((uint32_t)(x)) << 2u)
#define MCG_C2_HGO0(x)   ((uint32_t)((uint32_t)(x)) << 3u)
#define MCG_C2_RANGE0(x) ((uint32_t)((uint32_t)(x)) << 4u)

#define MCG_C4_DRST_DRS(x)((uint32_t)((uint32_t)(x)) << 5u)
#define MCG_C4_DMX32(x)   ((uint32_t)((uint32_t)(x)) << 7u)

#define MCG_C5_PRDIV0(x)  ((uint32_t)((uint32_t)(x)) << 0u)

#define MCG_C6_VDIV0(x)   ((uint32_t)((uint32_t)(x)) << 0u)
#define MCG_C6_PLLS(x)    ((uint8_t)((uint8_t)(x)) << 6u)

#define MCG_S_OSCINIT0(x) ((uint32_t)((uint32_t)(x)) << 1u)
#define MCG_S_CLKST(x)    ((uint32_t)((uint32_t)(x)) << 2u)
#define MCG_S_PLLST(x)    ((uint32_t)((uint32_t)(x)) << 5u)
#define MCG_S_LOCK0(x)    ((uint32_t)((uint32_t)(x)) << 6u)

#define MCG_SC_FCRDIV(x)  ((uint32_t)((uint32_t)(x)) << 1u)

#define SIM_SOPT2              *(volatile uint32_t*)(0x40048004u)
#define SIM_SCGC6              *(volatile uint32_t*)(0x4004803Cu)
#define SIM_SCGC6_TPM0_MASK    (0x1000000U)
#define SIM_CLKDIV1            (0x40048044u)

#define SIM_SOPT2_PLLFLLSEL_MASK    (0x10000U)
#define SIM_SOPT2_PLLFLLSEL_SHIFT   (16U)
#define SIM_SOPT2_PLLFLLSEL(x)      (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_PLLFLLSEL_SHIFT)) & SIM_SOPT2_PLLFLLSEL_MASK)
#define SIM_SOPT2_TPMSRC_MASK       (0x3000000U)
#define SIM_SOPT2_TPMSRC_SHIFT      (24U)
#define SIM_SOPT2_TPMSRC(x)         (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_TPMSRC_SHIFT)) & SIM_SOPT2_TPMSRC_MASK)
#define SIM_SOPT2_UART0SRC_MASK     (0xC000000U)
#define SIM_SOPT2_UART0SRC_SHIFT    (26U)
#define SIM_SOPT2_UART0SRC(x)       (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_UART0SRC_SHIFT)) & SIM_SOPT2_UART0SRC_MASK)

#define SIM_SCGC6_TPM0_MASK         (0x1000000U)
#define SIM_SCGC6_TPM0_SHIFT        (24U)
#define SIM_SCGC6_TPM0(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM0_SHIFT)) & SIM_SCGC6_TPM0_MASK)
#define SIM_SCGC6_PIT_MASK          (0x800000U)
#define SIM_SCGC6_PIT_SHIFT         (23U)
#define SIM_SCGC6_PIT(x)            (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PIT_SHIFT)) & SIM_SCGC6_PIT_MASK)
#define SIM_SCGC4_UART0_MASK        (0x400U)
#define SIM_SCGC4_UART0_SHIFT       (10U)
#define SIM_SCGC4_UART0(x)          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART0_SHIFT)) & SIM_SCGC4_UART0_MASK)
#define SIM_SCGC5_PORTA_MASK        (0x200U)
#define SIM_SCGC5_PORTA_SHIFT       (9U)
#define SIM_SCGC5_PORTA(x)          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTA_SHIFT)) & SIM_SCGC5_PORTA_MASK)

#define TPM0_SC                *(volatile uint32_t*)(0x40038000u)
#define TPM0_CONF              *(volatile uint32_t*)(0x40038084u)
#define TPM0_MOD               *(volatile uint32_t*)(0x40038008u)
#define TPM0_C2SC              *(volatile uint32_t*)(0x4003801Cu)
#define TPM0_C2V               *(volatile uint32_t*)(0x40038020u)
#define TPM0_C5SC              *(volatile uint32_t*)(0x40038034u)
#define TPM0_C5V               *(volatile uint32_t*)(0x40038038u)

#define TPM_SC_CMOD(x)         ((uint32_t)((uint32_t)(x)) << 3u)
#define TPM_SC_CPWMS(x)        ((uint32_t)((uint32_t)(x)) << 5u)
#define TPM_CONF_DBGMODE(x)    ((uint32_t)((uint32_t)(x)) << 6u)
#define TPM_CONF_DBGMODE_MASK   (0xC0U)

#define PIT_MCR                *(volatile uint32_t*)(0x40037000u)
#define PIT_CHANNEL0_LDVAL     *(volatile uint32_t*)(0x40037100u)
#define PIT_CHANNEL0_TCTRL     *(volatile uint32_t*)(0x40037108u)
#define PIT_CHANNEL0_TFLG      *(volatile uint32_t*)(0x4003710Cu)

#define PIT_MCR_MDIS(x)        ((uint32_t)((uint32_t)(x)) << 1u)
#define PIT_MCR_MDIS_MASK      (0x2U)
#define OSC0_CR                 *(volatile uint8_t*)(0x40065000u)
#define OSC_CR_ERCLKEN_MASK     (0x80U)
#define OSC_CR_ERCLKEN_SHIFT    (7U)
#define OSC_CR_ERCLKEN(x)       (((uint8_t)(((uint8_t)(x)) << OSC_CR_ERCLKEN_SHIFT)) & OSC_CR_ERCLKEN_MASK)

#define UART0_BDH           *(volatile uint8_t*)(0x4006A000u)
#define UART0_BDL           *(volatile uint8_t*)(0x4006A001u)
#define UART0_C2            *(volatile uint8_t*)(0x4006A003u)
#define UART0_S1            *(volatile uint8_t*)(0x4006A004u)
#define UART0_C4            *(volatile uint8_t*)(0x4006A00Au)
#define UART0_D             *(volatile uint8_t*)(0x4006A007u)

#define UART0_BDH_SBR_MASK  (0x1FU)
#define UART0_BDH_SBR(x)    ((uint32_t)((uint32_t)(x)) << 0u)

#define UART0_BDL_SBR_MASK  (0xFFU)
#define UART0_BDL_SBR(x)    ((uint32_t)((uint32_t)(x)) << 0u)

#define UART0_C2_RE_MASK    (0x4U)
#define UART0_C2_RE(x)      ((uint32_t)((uint32_t)(x)) << 2u)
#define UART0_C2_TE_MASK    (0x8U)
#define UART0_C2_TE(x)      ((uint32_t)((uint32_t)(x)) << 3u)
#define UART0_C2_RIE_MASK   (0x20U)
#define UART0_C2_RIE(x)     ((uint32_t)((uint32_t)(x)) << 5u)

#define UART_S1_TDRE_MASK   (0x80U)
#define UART_S1_TDRE(x)     ((uint32_t)((uint32_t)(x)) << 7u)

#define UART0_C4_OSR_MASK   (0x1FU)
#define UART0_C4_OSR(x)     ((uint32_t)((uint32_t)(x)) << 0u)


#define FTFA_FSTAT          *(volatile uint8_t*)(0x40020000u)
#define FTFA_FCCOB3         *(volatile uint8_t*)(0x40020004u)
#define FTFA_FCCOB2         *(volatile uint8_t*)(0x40020005u)
#define FTFA_FCCOB1         *(volatile uint8_t*)(0x40020006u)
#define FTFA_FCCOB0         *(volatile uint8_t*)(0x40020007u)
#define FTFA_FCCOB7         *(volatile uint8_t*)(0x40020008u)
#define FTFA_FCCOB6         *(volatile uint8_t*)(0x40020009u)
#define FTFA_FCCOB5         *(volatile uint8_t*)(0x4002000Au)
#define FTFA_FCCOB4         *(volatile uint8_t*)(0x4002000Bu)
#define FTFA_FCCOB8         *(volatile uint8_t*)(0x4002000Fu)
#define FTFA_FCCOB9         *(volatile uint8_t*)(0x4002000Eu)
#define FTFA_FSTAT_CCIF_MASK                     (0x80U)

#endif /* KL46_H_ */

/***************************************************************************************************
 * EOF
 ***************************************************************************************************/
