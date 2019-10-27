#ifndef S907X_STORE_H
#define S907X_STORE_H

#include "hal_flash.h"

#define fdcm_handle_t           uint8_t

#define ZG_FLASH_DATA_ADDR      FLASH_DATA_USER_START
#define ZG_FLASH_DATA_SIZE      SECTOR_SIZE

fdcm_handle_t * fdcm_open(int idx, int addr, int len);
int fdcm_read(fdcm_handle_t *fdcm_hdl, uint8_t *out_data, int in_len);
int fdcm_write(fdcm_handle_t *fdcm_hdl, uint8_t *in_data, int in_len);

#endif

