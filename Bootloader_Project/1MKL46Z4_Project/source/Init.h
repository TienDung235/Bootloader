#ifndef INIT_H_
#define INIT_H_
#include<stdint.h>
/***************************************************************************************************
* Definitions
***************************************************************************************************/
/***************************************************************************************************
* API
***************************************************************************************************/
/* @brief : This function initialize led
 * @param : None
 * @return: None
 */
void initLed();

/* @brief : This function initialize Systick_config
 * @param : None
 * @return: None
 */
void init_Systick_timer(uint32_t tick_hz);

/* @brief : This function initialize PWM Moldul
 * @param : None
 * @return: None
 */
void init_TPM0();

/* @brief : This function initialize PIT
 * @param : None
 * @return: None
 */
void init_PIT();

#endif /* INIT_H_ */
