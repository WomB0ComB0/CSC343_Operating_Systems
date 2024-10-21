/**
 * @file atomic_increment.c
 * @brief Demonstrates atomic operations and multi-threading in C.
 *
 * This program creates two threads that concurrently increment a shared atomic integer.
 * It uses atomic operations to ensure thread-safe access to the shared value.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

/** @brief Shared atomic integer that will be incremented by multiple threads. */
atomic_int shared_value = 0;

/**
 * @brief Thread function that increments the shared value atomically.
 * @param arg Pointer to the thread ID.
 * @return NULL
 */
void *thread_func(void *arg) {
    int thread_id = *(int *)arg;
    int old_value, new_value;

    // Each thread increments the shared value 5 times
    for (int i = 0; i < 5; i++) {
        do {
            // Atomically load the current value
            old_value = atomic_load(&shared_value);
            new_value = old_value + 1;
            // Attempt to update the shared value using compare-and-swap
        } while (!atomic_compare_exchange_weak(&shared_value, &old_value, new_value));

        printf("Thread %d: updated shared value to %d\n", thread_id, new_value);
    }

    pthread_exit(NULL);
}

/**
 * @brief Main function that creates and manages threads.
 * @return 0 on successful execution.
 */
int main() {
    pthread_t thread1, thread2;
    int thread_id1 = 1, thread_id2 = 2;

    // Create two threads
    pthread_create(&thread1, NULL, thread_func, &thread_id1);
    pthread_create(&thread2, NULL, thread_func, &thread_id2);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final value of the shared atomic integer
    printf("Final shared value: %d\n", atomic_load(&shared_value));

    return 0;
}