#ifndef UART0_H_
#define UART0_H_

/* @brief : UART initialization function
 * @param : None
 * @return: None
 */
void init_UART0();

/* @brief : The function writes a string to the UART
 * @param : String data
 * @return: None
 */
void UART_WriteString(uint8_t *data_u8);

/* @brief : calculation function baudrate
 * @param : baudrate input
 * @param : selected OSR
 * @param : selected SBR
 * @return: None
 */
void Config_Baudrate(uint32_t desire_Baudrate , uint8_t* Sele_OSR , uint32_t* Sele_SBR);

/* @brief : baudrate setting function for UART
 * @param : OSR,SBR
 * @return: None
 */
void UART0_Baudrate(uint8_t OSR , uint32_t SBR);

/* @brief : function prints a string
 * @param : string data
 * @return: None
 */
__attribute__((section(".ramfunc")))void PrintfString(char data[]);

/* @brief : covert function from string to integer
 * @param : string
 * @return: Convertible number
 */
uint32_t str_to_int(uint8_t* str);

/* @brief : function sends number to UART
 * @param : number
 * @return: None
 */
void sendnumber(uint32_t number_u32);

#endif /* UART0_H_ */
