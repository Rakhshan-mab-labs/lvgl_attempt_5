#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include "examples/lv_example_get_started.h"

void main(void)
{
    const struct device *display = DEVICE_DT_GET_ANY(ssd1680);
    if (!device_is_ready(display)) {
        printk("Display not ready\n");
        return;
    }

    display_blanking_off(display);

    /* Run LVGL example */
    lv_example_get_started_1();

    k_msleep(2000);

    while (1) {
        lv_task_handler();
        k_msleep(100);
    }
}
