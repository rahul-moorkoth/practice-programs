#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/irq.h>

#define GPIO_IRQ  45  // Example IRQ number

static irqreturn_t gpio_irq_handler(int irq, void *dev_id)
{
    printk(KERN_INFO "GPIO interrupt triggered.\n");

    // Read GPIO pin state to determine rising or falling edge
    if (gpio_get_value(45)) {
        printk(KERN_INFO "Detected Rising Edge.\n");
    } else {
        printk(KERN_INFO "Detected Falling Edge.\n");
    }

    return IRQ_HANDLED;
}

static int __init my_bsp_init(void)
{
    int ret;

    // Request IRQ for both rising and falling edges
    ret = request_irq(GPIO_IRQ, gpio_irq_handler, IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING, "gpio_irq_handler", NULL);
    if (ret) {
        printk(KERN_ERR "Failed to request IRQ\n");
        return ret;
    }

    return 0;
}

static void __exit my_bsp_exit(void)
{
    free_irq(GPIO_IRQ, NULL);
}

module_init(my_bsp_init);
module_exit(my_bsp_exit);
MODULE_LICENSE("GPL");
