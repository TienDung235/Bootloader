#ifndef FLASH_H_
#define FLASH_H_

/* @brief : Flash erase function
 * @param : address to delete
 * @return: None
 */
void Delete_Flash(uint32_t address_u32);


/* @brief : Function writes to flash
 * @param : address to write
 * @param : data to be recorded
 * @param : length
 * @return: None
 */
void Flash_Write(uint32_t address_u32, uint8_t data[], uint16_t numByte_u16);

/* @brief : Function writes to flash
 * @param : address to write
 * @param : data to be recorded
 * @return: None
 */
void Flash_WritePage(uint32_t address_u32, uint8_t data[]);

#endif /* FLASH_H_ */
