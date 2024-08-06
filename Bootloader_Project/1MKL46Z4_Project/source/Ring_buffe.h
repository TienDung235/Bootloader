#ifndef RING_BUFFE_H_
#define RING_BUFFE_H_

/***************************************************************************************************
* Definitions
***************************************************************************************************/
#define Row_RingBuffer 10
#define Colum_RingBuffer 100
#define OK 1
#define NO 0

/* @brief : The function gets the address to read
 * @param : None
 * @return: Address
 */
uint8_t *getReadAddress();

/* @brief : The funcition gets the address to write
 * @param : None
 * @return: Address
 */
__attribute__((section(".ramfunc")))uint8_t *getWriteAddress();

/* @brief : The function increases the line of reading data
 * @param : None
 * @return: None
 */
void Increace_Read_Data();

/* @brief : The function increases the data recording line
 * @param : None
 * @return: None
 */
__attribute__((section(".ramfunc")))void Increace_Write_Data();

/* @brief : The function checks to see if the ring buffer is full
 * @param : None
 * @return: Status
 */
__attribute__((section(".ramfunc")))uint8_t RingBuffer_CheckFull();

/* @brief : The function checks to see if the ring buffer is empty
 * @param : None
 * @return: status
 */
uint8_t RingBuffer_CheckEmpty();

#endif /* RING_BUFFE_H_ */

/***************************************************************************************************
* EOF
***************************************************************************************************/
