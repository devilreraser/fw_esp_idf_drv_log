/* *****************************************************************************
 * File:   drv_log.c
 * Author: Dimitar Lilov
 *
 * Created on 2022 06 18
 * 
 * Description: ...
 * 
 **************************************************************************** */

/* *****************************************************************************
 * Header Includes
 **************************************************************************** */
#include "drv_log.h"

#include <string.h>

#include "esp_log.h"

#include "sdkconfig.h"

/* *****************************************************************************
 * Configuration Definitions
 **************************************************************************** */
#define TAG "drv_log"

#define LORA_DEBUG  1

/* *****************************************************************************
 * Constants and Macros Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Enumeration Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Type Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Function-Like Macros
 **************************************************************************** */

/* *****************************************************************************
 * Variables Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Prototype of functions definitions
 **************************************************************************** */

/* *****************************************************************************
 * Functions
 **************************************************************************** */
void drv_log_init_on_reset(void)
{

}

void drv_log_init_before_main_loop(void)
{
    #if CONFIG_ESP_BOARD_ALFA00
    esp_log_level_set("main", ESP_LOG_WARN);
    esp_log_level_set("app_socket_udp", ESP_LOG_WARN);
    #if LORA_DEBUG
    esp_log_level_set("smartconfig", ESP_LOG_WARN);
    esp_log_level_set("app_lift_alfa", ESP_LOG_INFO);
    esp_log_level_set("drv_wifi", ESP_LOG_ERROR);
    esp_log_level_set("drv_stream", ESP_LOG_WARN);
    esp_log_level_set("drv_esptouch", ESP_LOG_ERROR);
    esp_log_level_set("drv_socket", ESP_LOG_NONE);
    esp_log_level_set("lora", ESP_LOG_NONE);
    #endif
    #endif

    #if CONFIG_ESP_BOARD_HC00
    esp_log_level_set("main", ESP_LOG_WARN);
    esp_log_level_set("drv_stream", ESP_LOG_WARN);
    esp_log_level_set("drv_socket", ESP_LOG_WARN);
    esp_log_level_set("app_socket_udp", ESP_LOG_INFO);
    #endif

    #if CONFIG_ESP_BOARD_HC00
    esp_log_level_set("mqtt_client", ESP_LOG_VERBOSE);//ESP_LOG_VERBOSE
    esp_log_level_set("drv_mqtt", ESP_LOG_NONE);//ESP_LOG_VERBOSE
    esp_log_level_set("drv_eth", ESP_LOG_NONE);
    #endif


    #if CONFIG_USE_FLD12_SPI
    esp_log_level_set("main", ESP_LOG_WARN);
    esp_log_level_set("drv_stream", ESP_LOG_WARN);
    esp_log_level_set("drv_socket", ESP_LOG_WARN);
    esp_log_level_set("app_socket_udp", ESP_LOG_WARN);
    esp_log_level_set("drv_eth", ESP_LOG_WARN);
    esp_log_level_set("drv_wifi", ESP_LOG_WARN);
    #endif
}