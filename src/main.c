#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/sys/printk.h>

#define ADC_NODE DT_PATH(zephyr_user)

/* MQ5 = index 0 */
static const struct adc_dt_spec mq5_channel =
    ADC_DT_SPEC_GET_BY_IDX(ADC_NODE, 0);

/* Light sensor = index 1 */
static const struct adc_dt_spec light_channel =
    ADC_DT_SPEC_GET_BY_IDX(ADC_NODE, 1);

int16_t mq5_buf;
int16_t light_buf;

void main(void)
{
    int err;

    printk("ADC MULTI SENSOR START\n");

    /* Setup MQ5 */
    err = adc_channel_setup_dt(&mq5_channel);

    if (err < 0) {
        printk("MQ5 setup failed: %d\n", err);
        return;
    }

    /* Setup LIGHT */
    err = adc_channel_setup_dt(&light_channel);

    if (err < 0) {
        printk("Light setup failed: %d\n", err);
        return;
    }

    while (1) {

        /* ================= MQ5 ================= */

        struct adc_sequence mq5_seq = {
            .buffer = &mq5_buf,
            .buffer_size = sizeof(mq5_buf),
        };

        adc_sequence_init_dt(&mq5_channel, &mq5_seq);

        err = adc_read(mq5_channel.dev, &mq5_seq);

        int32_t mq5_mv = mq5_buf;

        adc_raw_to_millivolts_dt(&mq5_channel, &mq5_mv);

        /* ================= LIGHT ================= */

        struct adc_sequence light_seq = {
            .buffer = &light_buf,
            .buffer_size = sizeof(light_buf),
        };

        adc_sequence_init_dt(&light_channel, &light_seq);

        err = adc_read(light_channel.dev, &light_seq);

        int32_t light_mv = light_buf;

        adc_raw_to_millivolts_dt(&light_channel, &light_mv);

        /* ================= PRINT ================= */

        printk("MQ5   : Raw=%d  %d mV\n",
               mq5_buf,
               mq5_mv);

        printk("LIGHT : Raw=%d  %d mV\n",
               light_buf,
               light_mv);

        printk("--------------------------\n");

        k_sleep(K_SECONDS(0.2));
    }
}