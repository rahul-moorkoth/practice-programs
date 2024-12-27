#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep()

// Thread function
void* threadFunction(void* arg) {
    printf("Thread: Performing some work...\n");
    sleep(2); // Simulate some work
    printf("Thread: Work is complete.\n");
    return NULL;
}

int main() {
    pthread_t thread;

    // Create a thread
    pthread_create(&thread, NULL, threadFunction, NULL);

    // Detach the thread
    pthread_detach(thread);

    printf("Main: Thread has been detached. Exiting main function.\n");

    // Sleep to ensure detached thread can complete
    sleep(1);

    return 0;
}
