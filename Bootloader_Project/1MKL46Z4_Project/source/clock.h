#ifndef CLOCK_H_
#define CLOCK_H_

/***************************************************************************************************
* Definitions
***************************************************************************************************/
#define Activate 1
#define Not_activate 0
typedef enum {
    FEI,
    FEE,
    FBI,
    FBE,
    PBE,
    PEE
}Mode_diagram;

typedef enum {
    FLL_IRC_Slow,
    FLL_OSC
}Fll_Source;
typedef struct clockConfigtype{
    Mode_diagram ClkSource;
    uint8_t Fast_ICR_u8;
    Fll_Source FLLSOURCE;
    uint8_t Fll_Multi_Factor_u8;
    uint8_t PLL_Multi_Factor_u8;
    uint8_t PLL_Divi_Factor_u8;
}clockConfig_type;

/***************************************************************************************************
* API
***************************************************************************************************/
/* @brief :Fast_irc configuration function
 * @param : struct contains configuration for clock
 * @return: status
 */
uint8_t Fast_IRC_FBI(clockConfig_type clockConfig);

/* @brief :FLL Slow configuration function
 * @param : struct contains configuration for clock
 * @return: status
 */
uint8_t FLL_Slow_FEI(clockConfig_type clockConfig );

/* @brief :FLL_OSC configuration function
 * @param : struct contains configuration for clock
 * @return: status
 */
uint8_t FLL_OSC_FEE(clockConfig_type clockConfig);

/* @brief :PLL configuration function
 * @param : struct contains configuration for clock
 * @return: status
 */
uint8_t PLL_PEE(clockConfig_type clockConfig);

/* @brief : OSC FBE configuration function
 * @param : struct contains configuration for clock
 * @return: status
 */
uint8_t OSC_FBE(clockConfig_type clockConfig);

/* @brief : OSC PBE configuration function
 * @param : struct contains configuration for clock
 * @return: status
 */
uint8_t OSC_PBE(clockConfig_type clockConfig);

/* @brief :function to select mode for clock
 * @param : struct contains configuration for clock
 * @return: status
 */
uint32_t mode(clockConfig_type clockConfig);

/* @brief : clock calculation function
 * @param : struct contains configuration for clock
 * @return: status
 */
uint32_t GetCpuClockFrequency(clockConfig_type clockConfig);

#endif /* CLOCK_H_ */
/***************************************************************************************************
* EOF
***************************************************************************************************/
