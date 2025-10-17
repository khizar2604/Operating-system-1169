#include <stdio.h>
#include <pthread.h>

void* show_gpa(void* arg) {
    // Convert the void pointer back to float pointer
    float gpa = *(float*)arg;

    printf("Thread received GPA: %.2f\n", gpa);
    printf("GPA × 2 = %.2f\n", gpa * 2);

    return NULL;
}

int main() {
    pthread_t thread_id;
    float gpa = 3.45;

    printf("Creating thread with GPA: %.2f\n", gpa);

    // Pass address of 'gpa' to the thread
    pthread_create(&thread_id, NULL, show_gpa, &gpa);
    pthread_join(thread_id, NULL);

    printf("Main thread done.\n");
    return 0;
}
