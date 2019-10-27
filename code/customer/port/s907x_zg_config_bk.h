#ifndef _S907X_ZG_CONFIG_H_
#define _S907X_ZG_CONFIG_H_

#include "s907x.h"
#include "system_config.h"

#define ZG_PWM_ENABLE                       0
#define ZG_NET_SERVER_ENBALE                0
#define ZG_OTA_ENABLE                       0
#define ZG_OTA_REBOOT_ENABLE                0
#define ZG_OTA_TASK_ENABLE                  0

#define S907X_NET_SERVER_ENABLE             1
#define S907X_OTA_TASK_ENABLE               1
#define S907X_BUILD_FOR_ZG                  ZG_BUILD

#define ZG_PWM_PRESCALER_SET              0
#define ZG_PWM_PERIOD_SET                 40000
#define ZG_PWM_CHANNEL_R                  1
#define ZG_PWM_CHANNEL_G                  2
#define ZG_PWM_CHANNEL_B                  5
#define ZG_PWM_POLARITY_ZERO              0

#define PWM_GROUP1_CH2          ZG_PWM_CHANNEL_R
#define PWM_GROUP1_CH3          ZG_PWM_CHANNEL_G
#define PWM_GROUP2_CH4          ZG_PWM_CHANNEL_B


#define WLAN_MODE_HOSTAP        S907X_MODE_AP
#define WLAN_MODE_STA           S907X_MODE_STA
#define HAL_Status              hal_status_e
#define malloc                  wl_malloc
#define free                    wl_free





#ifdef USER_TASK_PRIO
#undef USER_TASK_PRIO
#endif
#ifdef USER_TASK_STACK_SZ
#undef USER_TASK_STACK_SZ
#endif
#define USER_TASK_PRIO                  (MAIN_TASK_PRIO+5)
#define USER_TASK_STACK_SZ              (4096)

#define LIGHT_TASK_PRIO                 (tskIDLE_PRIORITY + 4)
#define LIGHT_TASK_STACK_SZ             (1024)

#define LIGHT_REMOTE_TASK_PRIO          (tskIDLE_PRIORITY + 2)
#define LIGHT_REMOTE_TASK_STACK_SZ      (512)

#define STORE_TASK_PRIO                 (tskIDLE_PRIORITY + 2)
#define STORE_TASK_STACK_SZ             (512)

#define TCP_SERVER_TASK_PRIO            (tskIDLE_PRIORITY + 6)
#define TCP_SERVER_TASK_STACK_SZ        (1024 * 2)

#define TCP_CLIENT_TASK_PRIO            (tskIDLE_PRIORITY + 7)
#define TCP_CLIENT_TASK_STACK_SZ        (1024 * 2)

#define TCP_CLIENT_SEND_TASK_PRIO       (tskIDLE_PRIORITY + 2)
#define TCP_CLIENT_SEND_TASK_STACK_SZ   (1024)

#define UDP_SERVER_TASK_PRIO            (tskIDLE_PRIORITY + 5)
#define UDP_SERVRE_TASK_STACK_SZ        (1024)

#define TIMER_CLOCK_TASK_PRIO           (tskIDLE_PRIORITY + 1)
#define TIMER_CLOCK_TASK_STACK_SZ       (512)

#define AUTO_REPORT_TASK_PRIO           (tskIDLE_PRIORITY + 4)
#define AUTO_REPORT_TASK_STACK_SZ       (512)

#define FOTA_TASK_PRIO                  (tskIDLE_PRIORITY + 3)
#define FOTA_TASK_STACK_SZ              (2048)

#define ZG_EVENT_LOOP_TASK_PRIO         (configMAX_PRIORITIES - 6)
#define ZG_EVENT_LOOP_TASK_STACK_SZ     (1024)

//test  macro
#define ZG_WIFI_BLOCK_TIME               20000

#endif

