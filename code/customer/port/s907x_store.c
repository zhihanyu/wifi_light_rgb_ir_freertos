#include "s907x.h"
#include "system_debug.h"
#include "s907x_store.h"

fdcm_handle_t *fdcm_open(int idx, int addr, int len)
{
    uint8_t *ptr_addr = NULL;

    ptr_addr = wl_malloc(ZG_FLASH_DATA_SIZE);
    if (NULL == ptr_addr) {
        USER_DBG("Alloc memory for fdcm fail.");
    }

    return ptr_addr;
}


int fdcm_read(fdcm_handle_t *fdcm_hdl, uint8_t *out_data, int in_len)
{
    s907x_hal_flash_read(ZG_FLASH_DATA_ADDR, out_data, in_len);

    return in_len;
}

int fdcm_write(fdcm_handle_t *fdcm_hdl, uint8_t *in_data, int in_len)
{
    s907x_hal_flash_erase(EraseSector, ZG_FLASH_DATA_ADDR);
    s907x_hal_flash_write(ZG_FLASH_DATA_ADDR, in_data, in_len);

    return in_len;
}


