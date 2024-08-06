#ifndef SREC_H_
#define SREC_H_

/***************************************************************************************************
* Definitions
***************************************************************************************************/
#define NO 0


/* @brief : function to convert from hexa string to integer
 * @param : String
 * @return: convert from hexa string to integer
 */
uint8_t strHex_to_int(uint8_t *str);

/* @brief : Function to check checksum of srecord file
 * @param : input data
 * @return: sum
 */
uint32_t check_sum(uint8_t *data);

/* @brief : Function to check checkbyte of srecord file
 * @param : input data
 * @return: equal or not equal
 */
uint32_t check_byte(uint8_t *data);

/* @brief : function to get data from file srec
 * @param : Address of the srec line to read in ringbuffer
 * @param : Line lenght srec
 * @return: read value in screc
 */
uint8_t* getdata(uint8_t *data_u8, uint8_t *len_u8);

/* @brief : Function to get address Srec
 * @param : Ring buffer address to read
 * @return: Address
 */
uint32_t getAddressSrec(uint8_t *rb);

#endif /* SREC_H_ */
/***************************************************************************************************
* EOF
***************************************************************************************************/
