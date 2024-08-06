/***************************************************************************************************
 * Include
***************************************************************************************************/
#include<stdint.h>
#include "MKL46Z4.h"
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
uint8_t Fast_IRC_FBI(clockConfig_type clockConfig){
    uint8_t status_u8 = Not_activate;
    uint32_t dummyCount = 0;
    MCG->C1 |= MCG_C1_CLKS(1);
    MCG->C2 |= MCG_C2_IRCS(1);
    /*FCRDIV*/
    MCG->SC &= ~MCG_SC_FCRDIV(1);
    MCG->SC |= MCG_SC_FCRDIV(clockConfig.Fast_ICR_u8);

    while(((MCG->S & 0xC) != 0x4)&& (dummyCount < 10000)){
        dummyCount++;
    }
    status_u8 = Activate;
    return status_u8;

}
uint8_t FLL_Slow_FEI(clockConfig_type clockConfig ){
    uint8_t status_u8 = Not_activate;
    uint32_t dummyCount = 0;
    MCG->C1 &= ~MCG_C1_IREFS(1);
    MCG->C1 |= MCG_C1_IREFS(1);
    MCG->C4 |= MCG_C4_DRST_DRS(clockConfig.Fll_Multi_Factor_u8);
    MCG->C4 |= MCG_C4_DMX32(1);
    MCG->C1 |= MCG_C1_CLKS(0);
    MCG->C6 |= MCG_C6_PLLS(0);

    while(((MCG->S & 0xC) != 0x0)&& (dummyCount < 10000)){
        dummyCount++;
    }
    status_u8 = Activate;
    return status_u8;
}

uint8_t FLL_OSC_FEE(clockConfig_type clockConfig){
    uint8_t status_u8 = Not_activate;
    uint32_t dummyCount = 0;
    /*OSC*/
    MCG->C2 |= MCG_C2_RANGE0(1);
    MCG->C2 |= MCG_C2_HGO0(1);
    MCG->C2 |= MCG_C2_EREFS0(1);
    MCG->C1 |= MCG_C1_CLKS(0);

    /*FRDIV*/
    MCG->C1 |= MCG_C1_FRDIV(3);
    MCG->C1 &= ~(MCG_C1_IREFS_MASK);

    /*DRST & DMX32*/
    MCG->C4 |= MCG_C4_DRST_DRS(clockConfig.Fll_Multi_Factor_u8);
    MCG->C4 |= MCG_C4_DMX32(1);

    /*OSCINIT*/
    while(((MCG->S & 0xC) != 0x8)&& (dummyCount < 10000)){
        dummyCount++;
    }
    /*CLKS*/
    while(((MCG->S & 0x2) != 0x2)&& (dummyCount < 10000)){
        dummyCount++;
    }

    status_u8 = Activate;
    return status_u8;
}
uint8_t PLL_PEE(clockConfig_type clockConfig){
    uint8_t status_u8 = Not_activate;
    uint32_t dummyCount = 0;
    /*OSC*/
    MCG->C2 |= MCG_C2_RANGE0(1);
    MCG->C2 |= MCG_C2_HGO0(1);
    MCG->C2 |= MCG_C2_EREFS0(1);
    MCG->C1 &= ~MCG_C1_CLKS_MASK;
    MCG->C1 |= MCG_C1_CLKS(0);

    /*Multi & Div*/
    MCG->C1 &= ~MCG_C1_IREFS_MASK;
    MCG->C5 |= MCG_C5_PRDIV0(clockConfig.PLL_Divi_Factor_u8);
    MCG->C6 |= MCG_C6_VDIV0(clockConfig.PLL_Multi_Factor_u8);

    /*EX PLL*/
    MCG->C6 |= MCG_C6_PLLS(1);
    while(((MCG->S & 0xC) != 0xC)&& (dummyCount < 10000)){
        dummyCount++;
    }
    while(((MCG->S & 0x40) != 0x40)&& (dummyCount < 10000)){
        dummyCount++;
    }
    while(((MCG->S & 0x20) != 0x20)&& (dummyCount < 10000)){
        dummyCount++;
    }
    status_u8 = Activate;
    return status_u8;
}

uint8_t OSC_FBE(clockConfig_type clockConfig){
    uint8_t status_u8 = Not_activate;
    uint32_t dummyCount = 0;
    /*OSC*/
    MCG->C2 |= MCG_C2_RANGE0(1);
    MCG->C2 |= MCG_C2_HGO0(1);
    MCG->C2 |= MCG_C2_EREFS0(1);
    MCG->C1 |= MCG_C1_CLKS(2); /* OSC */
    MCG->C1 &= ~MCG_C1_IREFS(1);
    /*FRDIV*/
    MCG->C1 |= MCG_C1_FRDIV(3);
    /*PLLS*/
    MCG->C6 |= MCG_C6_PLLS(0);
    while(((MCG->S & 0xC) != 0x8)&& (dummyCount < 10000)){
        dummyCount++;
    }
    while(((MCG->S & 0x2) != 0x2)&& (dummyCount < 10000)){
        dummyCount++;
    }
    status_u8 = Activate;
    return status_u8;
}

uint8_t OSC_PBE(clockConfig_type clockConfig){
    uint8_t status_u8 = Not_activate;
    uint32_t dummyCount = 0;
    /*OSC*/
    MCG->C2 |= MCG_C2_RANGE0(1);
    MCG->C2 |= MCG_C2_HGO0(1);
    MCG->C2 |= MCG_C2_EREFS0(1);
    MCG->C1 |= MCG_C1_CLKS(2); /* OSC */
    MCG->C1 &= ~MCG_C1_IREFS(1);
    MCG->C5 |= MCG_C5_PRDIV0(3);
    MCG->C6 |= MCG_C6_PLLS(1);
    while(((MCG->S & 0xC) != 0xC)&& (dummyCount < 10000)){
        dummyCount++;
    }
    while(((MCG->S & 0x40) != 0x40)&& (dummyCount < 10000)){
        dummyCount++;
    }
    while(((MCG->S & 0x20) != 0x20)&& (dummyCount < 10000)){
        dummyCount++;
    }
    status_u8 = Activate;
    return status_u8;
}

uint32_t mode(clockConfig_type clockConfig){
    uint8_t status_u8 = Not_activate;
    switch(clockConfig.ClkSource){
        case FEE:
            status_u8 = FLL_OSC_FEE(clockConfig);
        break;
        case FBI:
            status_u8 = Fast_IRC_FBI(clockConfig);
            break;
        case FBE:
            status_u8 = OSC_FBE(clockConfig);
            break;
        case PBE:
            status_u8 = OSC_PBE(clockConfig);
            break;
        case PEE:
            status_u8 = PLL_PEE(clockConfig);
        default:
            status_u8 = FLL_Slow_FEI(clockConfig);
    }
    return status_u8;
}
uint32_t GetCpuClockFrequency(clockConfig_type clockConfig){
    uint64_t result_u32 =0;
    uint32_t OSC_u32 = 8000000;
    uint32_t Fast_IRS = 4000000;
    uint32_t multi =0;
    uint32_t div =0;
    switch(clockConfig.ClkSource){
    case FBE:
        result_u32 = OSC_u32;
        break;
    case PBE:
        result_u32 = OSC_u32;
        break;
    case PEE:
        multi = clockConfig.PLL_Multi_Factor_u8 +24;/*Vdiv way Multi 24 unit*/
        div = clockConfig.PLL_Divi_Factor_u8 +1;/*Prdiv way Div 1 unit*/
        result_u32 = (OSC_u32 * multi) / div;
        break;
    case FEE:
        div = 256; /* FRDIV = 011*/
        /*The FLL Factor of "DMX32 = 1" is 732 units apart*/
        multi = (clockConfig.Fll_Multi_Factor_u8 + 1)*732;
        result_u32 = (OSC_u32 * multi) /div;
        break;
    case FEI:
        /*The FLL Factor of "DMX32 = 1" is 732 units apart*/
        multi = (clockConfig.Fll_Multi_Factor_u8 + 1)*732;
        result_u32 = 32768*multi; /* DMX32 = 1  * multi*/
        break;
    case FBI:
        result_u32 = Fast_IRS;
        break;
    }
    return result_u32;
}

/***************************************************************************************************
 * EOF
***************************************************************************************************/
