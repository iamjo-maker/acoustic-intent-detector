#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "mic.h"
#include "intent.h"

void app_main(void)
{
    mic_init();
    intent_init();

    while (1)
    {
        int sample = mic_read_sample();

        bool detected = intent_update(sample);

        printf("Sample: %d, Energy: %.2f, Baseline: %.2f, Detected: %s\n",
               sample, intent_get_energy(), intent_get_baseline(),
               detected ? "Yes" : "No"
        );

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}