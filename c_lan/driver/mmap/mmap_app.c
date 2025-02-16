#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/my_mmap_device"
#define MEM_SIZE 4096

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // Map the device memory to user space
    void *mapped_mem = mmap(NULL, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_mem == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    // Write to the mapped memory
    sprintf((char *)mapped_mem, "Hello from mmap!");
    
    printf("Mapped Memory Content: %s\n", (char *)mapped_mem);

    // Unmap and close
    munmap(mapped_mem, MEM_SIZE);
    close(fd);
    return 0;
}
