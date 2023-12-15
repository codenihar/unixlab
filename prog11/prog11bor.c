#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to be executed by each thread
void *printHello(void *threadId) {
    long tid = (long)threadId;
    printf("Hello World from Thread %ld\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create five threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, printHello, (void *)t);

        if (rc) {
            printf("Error creating thread; return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }

    // Wait for each thread to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Main thread exiting.\n");

    return 0;
}
