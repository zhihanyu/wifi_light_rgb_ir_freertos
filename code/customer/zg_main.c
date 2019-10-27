/*
 * Copyright (C) 2017 XRADIO TECHNOLOGY CO., LTD. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the
 *       distribution.
 *    3. Neither the name of XRADIO TECHNOLOGY CO., LTD. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "s907x_zg_config.h"
#if !S907X_BUILD_FOR_ZG
#include "common/framework/platform_init.h"
#endif
#include "sys/ZG_system.h"
#include "light/color.h"
static esp_err_t event_handler(void *ctx, ZG_system_event_t *event)
{
    switch(*event)
    {
        case FACTORY_SETTING_EVENT:
        printf("event:factory-setting.\n");
        set_led_switch(MODE_ON);  
        set_led_mode(MODE_FACTORY);
        set_led_speed(0X01);
        break;

        case CONNECTED_ROUTER_EVENT:

            printf("event:router connected");
            if(get_tcp_Client_switch() == 1)
            {
                int status = tcp_Client_start();
                printf("tcp client start status : %d\n\n",status);
                auto_report_init();                    
            }  
            connect_to_routing_Indicator();
            break;
        case OTA_EVENT:
            printf("event:ota");
            break;
    }
    return 0;
}

#if S907X_BUILD_FOR_ZG
int user_main(void)
#else
int main(void)
#endif
{
#if S907X_BUILD_FOR_ZG
    USER_DBG("user_main.\n");
#else
    platform_init();
#endif
    ZG_device_info_conf("AK001-ZJ2131","33_04_20191023_ZG-ZW-IR",0x33,8);
    ZG_event_loop_init(event_handler,NULL);
    ZG_system_start();
  return 0;
}
