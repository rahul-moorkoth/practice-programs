#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/irq.h>

#define SHARED_IRQ  45  // Example IRQ number

static irqreturn_t device1_irq_handler(int irq, void *dev_id)
{
    printk(KERN_INFO "Device 1 interrupt handler called.\n");
    // Check if this device triggered the IRQ and handle it
    return IRQ_HANDLED;
}

static irqreturn_t device2_irq_handler(int irq, void *dev_id)
{
    printk(KERN_INFO "Device 2 interrupt handler called.\n");
    // Check if this device triggered the IRQ and handle it
    return IRQ_HANDLED;
}

static int __init my_bsp_init(void)
{
    int ret;

    // Request shared IRQ
    ret = request_irq(SHARED_IRQ, device1_irq_handler, IRQF_SHARED, "device1", (void *)1);
    if (ret) {
        printk(KERN_ERR "Failed to register IRQ for device 1\n");
        return ret;
    }

    ret = request_irq(SHARED_IRQ, device2_irq_handler, IRQF_SHARED, "device2", (void *)2);
    if (ret) {
        printk(KERN_ERR "Failed to register IRQ for device 2\n");
        free_irq(SHARED_IRQ, (void *)1);
        return ret;
    }

    return 0;
}

static void __exit my_bsp_exit(void)
{
    free_irq(SHARED_IRQ, (void *)1);
    free_irq(SHARED_IRQ, (void *)2);
}

module_init(my_bsp_init);
module_exit(my_bsp_exit);
MODULE_LICENSE("GPL");
