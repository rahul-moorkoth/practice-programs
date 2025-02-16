#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "my_mmap_device"
#define MEM_SIZE 4096  // 4KB memory region

static int major;
static void *kernel_buffer;
static dma_addr_t phys_addr;  // Physical address for DMA

// mmap() implementation
static int my_mmap(struct file *filp, struct vm_area_struct *vma) {
    unsigned long phys_page = virt_to_phys(kernel_buffer) >> PAGE_SHIFT;
    
    if (remap_pfn_range(vma, vma->vm_start, phys_page, vma->vm_end - vma->vm_start, vma->vm_page_prot)) {
        pr_err("remap_pfn_range failed\n");
        return -EAGAIN;
    }

    pr_info("Memory mapped successfully: %p\n", kernel_buffer);
    return 0;
}

// Open function
static int my_open(struct inode *inode, struct file *file) {
    return 0;
}

// Release function
static int my_release(struct inode *inode, struct file *file) {
    return 0;
}

// File operations
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
    .mmap = my_mmap,  // Register mmap function
};

// Module initialization
static int __init my_driver_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        pr_err("Failed to register device\n");
        return major;
    }

    kernel_buffer = kmalloc(MEM_SIZE, GFP_KERNEL);
    if (!kernel_buffer) {
        unregister_chrdev(major, DEVICE_NAME);
        return -ENOMEM;
    }

    pr_info("Device registered: /dev/%s, Major: %d\n", DEVICE_NAME, major);
    return 0;
}

// Module cleanup
static void __exit my_driver_exit(void) {
    kfree(kernel_buffer);
    unregister_chrdev(major, DEVICE_NAME);
    pr_info("Device unregistered\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);
MODULE_LICENSE("GPL");
