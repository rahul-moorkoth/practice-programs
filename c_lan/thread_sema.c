#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define THREAD_COUNT 5
#define MAX_RESOURCES 3

sem_t semaphore; // Semaphore declaration

void* worker(void* arg) {
    int id = *(int*)arg;

    printf("Thread %d: Waiting to access the resource...\n", id);

    // Wait (P operation): Decrease the semaphore count
    sem_wait(&semaphore);

    // Critical Section: Access the shared resource
    printf("Thread %d: Accessing the resource.\n", id);
    sleep(2); // Simulate work

    // Signal (V operation): Increase the semaphore count
    printf("Thread %d: Releasing the resource.\n", id);
    sem_post(&semaphore);

    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];

    // Initialize the semaphore with MAX_RESOURCES
    sem_init(&semaphore, 0, MAX_RESOURCES);

    // Create threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

