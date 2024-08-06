#ifndef PROGRAMME_H_
#define PROGRAMME_H_
/***************************************************************************************************
* Definitions
***************************************************************************************************/
#define START 1
#define ERROR 0
#define END   2
#define MAIN_APP_ADDRESS (0x8000u)

/* @brief : The function calls bootloader
 * @param : None
 * @return: None
 */
void Run_Bootloader();

/* @brief : The function calls application
 * @param : None
 * @return: None
 */
void Run_Application();

/* @brief : The function puts the vector table into ram
 * @param : None
 * @return: None
 */
void My_VectorTable();

#endif /* PROGRAMME_H_ */

/***************************************************************************************************
* EOF
***************************************************************************************************/
