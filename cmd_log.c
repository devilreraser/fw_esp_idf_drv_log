/* *****************************************************************************
 * File:   cmd_log.c
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
#include "cmd_log.h"

#include <string.h>
#include <inttypes.h>

#include "esp_log.h"
#include "esp_console.h"
#include "argtable3/argtable3.h"

#include "drv_log.h"

#if CONFIG_DRV_CONSOLE_USE
#include "drv_console.h"
#endif

/* *****************************************************************************
 * Configuration Definitions
 **************************************************************************** */
#define TAG "cmd_log"

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


static struct {
    struct arg_str *command;
    struct arg_end *end;
} log_args;


static int cmd_log_func(int argc, char **argv)
{
    #if CONFIG_DRV_CONSOLE_USE
    #if CONFIG_DRV_CONSOLE_CUSTOM
    #if CONFIG_DRV_CONSOLE_CUSTOM_LOG_DISABLE_FIX
    drv_console_set_other_log_disabled();
    #endif
    #endif
    #endif

    ESP_LOGI(__func__, "argc=%d", argc);
    for (int i = 0; i < argc; i++)
    {
        ESP_LOGI(__func__, "argv[%d]=%s", i, argv[i]);
    }

    int nerrors = arg_parse(argc, argv, (void **)&log_args);

    if (nerrors != ESP_OK)
    {
        arg_print_errors(stderr, log_args.end, argv[0]);
        return ESP_FAIL;
    }

    if (strcmp(log_args.command->sval[1],"allow") == 0)
    { 
        esp_log_level_set(log_args.command->sval[0], ESP_LOG_INFO);
    }    
    else
    if (strcmp(log_args.command->sval[1],"deny") == 0)
    { 
        esp_log_level_set(log_args.command->sval[0], ESP_LOG_NONE);
    }    
    else
    if (strcmp(log_args.command->sval[1],"none") == 0)
    { 
        esp_log_level_set(log_args.command->sval[0], ESP_LOG_NONE);
    }    
    else
    if (strcmp(log_args.command->sval[1],"error") == 0)
    { 
        esp_log_level_set(log_args.command->sval[0], ESP_LOG_ERROR);
    }    
    else
    if (strcmp(log_args.command->sval[1],"warning") == 0)
    { 
        esp_log_level_set(log_args.command->sval[0], ESP_LOG_WARN);
    }    
    else
    if (strcmp(log_args.command->sval[1],"info") == 0)
    { 
        esp_log_level_set(log_args.command->sval[0], ESP_LOG_INFO);
    }    
    else
    if (strcmp(log_args.command->sval[1],"debug") == 0)
    { 
        esp_log_level_set(log_args.command->sval[0], ESP_LOG_DEBUG);
    }    
    else
    if (strcmp(log_args.command->sval[1],"verbose") == 0)
    { 
        esp_log_level_set(log_args.command->sval[0], ESP_LOG_VERBOSE);
    }    
    else
    {
        ESP_LOGE(TAG, "Not implemented log level %s", log_args.command->sval[1]);
    }

    return 0;
}

static void register_log(void)
{

    log_args.command = arg_strn(NULL, NULL, "<tag>", 2, 2, "Command can be : log <TAG> <allow|deny|warning|error|info|debug|verbose>");
    log_args.end = arg_end(1);

    const esp_console_cmd_t cmd_log = {
        .command = "log",
        .help = "Allow Deny or set Level of Log Print\r\n  Command can be : log <TAG> <allow|deny|warning|error|info|debug|verbose>",
        .hint = NULL,
        .func = &cmd_log_func,
    };
    ESP_ERROR_CHECK(esp_console_cmd_register(&cmd_log));
}


void cmd_log_register(void)
{
    register_log();
}