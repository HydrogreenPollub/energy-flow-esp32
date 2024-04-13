#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "driver/gpio.h"

#include "esp_log.h"
#include "esp_sleep.h"
#include "esp_timer.h"

#include "CANopenNode_ESP32.h"
#include "OD.h"

static const char *TAG = "EFU";

void app_main(void)
{
    CO_ESP32_init();

    while (1)
    {
        // OD_requestTPDO(OD_getFlagsPDO(OD_ENTRY_H6400_vehicleSpeedFromMCU), 0x00);
        ESP_LOGI(TAG, "Speed: %.3f", OD_RAM.x6400_vehicleSpeedFromMCU);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}