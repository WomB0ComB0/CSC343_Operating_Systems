#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/**
 * Global lock variable used for synchronization between threads.
 * 0 indicates the lock is free, 1 indicates it's taken.
 */
int lock = 0;

/**
 * Thread 1 function.
 * Continuously tries to acquire the lock, perform its critical section,
 * and then release the lock.
 *
 * @param arg Pointer to thread arguments (unused in this case)
 * @return NULL
 */
void *thread1(void *arg) {
    while (1) {
        // Attempt to acquire the lock using atomic test-and-set
        while (__sync_lock_test_and_set(&lock, 1)); // Acquire lock

        // Critical section
        printf("Thread 1 in critical section\n");
        sleep(1);

        // Release the lock
        lock = 0; // Release lock
        sleep(1);
    }
}

/**
 * Thread 2 function.
 * Identical to thread1 function, but prints a different message.
 *
 * @param arg Pointer to thread arguments (unused in this case)
 * @return NULL
 */
void *thread2(void *arg) {
    while (1) {
        // Attempt to acquire the lock using atomic test-and-set
        while (__sync_lock_test_and_set(&lock, 1)); // Acquire lock

        // Critical section
        printf("Thread 2 in critical section\n");
        sleep(1);

        // Release the lock
        lock = 0; // Release lock
        sleep(1);
    }
}

/**
 * Main function.
 * Creates two threads and waits for them to finish (which they never do in this case).
 *
 * @return 0 on successful execution
 */
int main() {
    pthread_t t1, t2;

    // Create two threads
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    // Wait for threads to finish (which they never do in this infinite loop scenario)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}