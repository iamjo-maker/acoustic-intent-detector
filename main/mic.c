#include "mic.h"
#include "driver/adc.h"

#define MIC_ADC_CHANNEL ADC1_CHANNEL_6  // GPIO34
#define MIC_ADC_ATTEN   ADC_ATTEN_DB_11

void mic_init(void)
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(MIC_ADC_CHANNEL, MIC_ADC_ATTEN);
}

int mic_read_sample(void)
{
    return adc1_get_raw(MIC_ADC_CHANNEL);
}