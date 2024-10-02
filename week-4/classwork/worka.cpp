#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_function(void *arg) {
    printf("thread function Process id %d\n", getpid());
    return NULL;
}

int main() {
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    printf("Hello from the main!\n");
    printf("After thread 1 call, the thread id = %d\n", thread1);

    pthread_create(&thread2, NULL, thread_function, NULL);
    printf("Hello from the main-1\n");
    printf("After thread 2 call, the thread id = %d\n", thread2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Hello from the main-2\n");
    return 0;
}