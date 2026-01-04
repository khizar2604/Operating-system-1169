// Name: Khizar Hameed
// Reg_No: 23-NTU-CS-1169
// Task: Task 1 - Personalized Greeting Threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *greet(void *arg) {
    char *name = (char*)arg;
    printf("Thread says: Assalamu Alaikum, %s! Welcome to the world of threads.\n", name);
    free(name);
    return NULL;
}

int main() {
    pthread_t tid;
    char *name = strdup("Khizar");

    printf("Main thread: Waiting for greeting...\n");
    pthread_create(&tid, NULL, greet, name);
    pthread_join(tid, NULL);
    printf("Main thread: Greeting Done.\n");
    return 0;
}
