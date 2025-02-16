#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>        // For GPIO functions
#include <linux/interrupt.h>   // For IRQ functions
#include <linux/irq.h>         // For IRQ types
#include <linux/init.h>        // For module macros

#define GPIO_PIN 24            // GPIO pin number (example)
#define GPIO_DESC "gpio_irq_example"

static int irq_number;         // IRQ number for the GPIO
static int irq_count = 0;      // Counter for interrupt occurrences

// Interrupt handler
static irqreturn_t gpio_irq_handler(int irq, void *dev_id) {
    irq_count++;
    pr_info("GPIO Interrupt: Count = %d\n", irq_count);
    return IRQ_HANDLED;
}

// Module initialization function
static int __init gpio_irq_init(void) {
    int ret;

    pr_info("GPIO IRQ Driver: Initializing\n");

    // Request the GPIO
    ret = gpio_request(GPIO_PIN, GPIO_DESC);
    if (ret) {
        pr_err("Failed to request GPIO %d\n", GPIO_PIN);
        return ret;
    }

    // Set the GPIO direction as input
    ret = gpio_direction_input(GPIO_PIN);
    if (ret) {
        pr_err("Failed to set GPIO %d as input\n", GPIO_PIN);
        gpio_free(GPIO_PIN);
        return ret;
    }

    // Map GPIO to IRQ
    irq_number = gpio_to_irq(GPIO_PIN);
    if (irq_number < 0) {
        pr_err("Failed to map GPIO %d to IRQ\n", GPIO_PIN);
        gpio_free(GPIO_PIN);
        return irq_number;
    }

    pr_info("GPIO %d mapped to IRQ %d\n", GPIO_PIN, irq_number);

    // Request the IRQ
    ret = request_irq(irq_number, gpio_irq_handler, IRQF_TRIGGER_RISING, "gpio_irq_handler", NULL);
    if (ret) {
        pr_err("Failed to request IRQ %d\n", irq_number);
        gpio_free(GPIO_PIN);
        return ret;
    }

    pr_info("GPIO IRQ Driver: Successfully initialized\n");
    return 0;
}

// Module cleanup function
static void __exit gpio_irq_exit(void) {
    pr_info("GPIO IRQ Driver: Cleaning up\n");

    // Free the IRQ
    free_irq(irq_number, NULL);

    // Free the GPIO
    gpio_free(GPIO_PIN);

    pr_info("GPIO IRQ Driver: Successfully unloaded\n");
}

module_init(gpio_irq_init);
module_exit(gpio_irq_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("GPIO Interrupt Driver Example");
MODULE_VERSION("1.0");
