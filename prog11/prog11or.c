#include <stdio.h>
#include <pthread.h>

#define COUNT_LIMIT 100

// Thread function
void* countNumbers(void* thread_id) {
    int tid = *(int*)thread_id;

    for (int i = 1; i <= COUNT_LIMIT; i++) {
        printf("Thread %d: %d\n", tid, i);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    // Create threads
    pthread_create(&thread1, NULL, countNumbers, (void*)&id1);
    pthread_create(&thread2, NULL, countNumbers, (void*)&id2);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // After both threads have finished
    printf("Both threads have joined.\n");

    return 0;
}
