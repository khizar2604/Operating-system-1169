#include <stdio.h>
#include <pthread.h>

typedef struct 
{
    int id;
    int gpa;

}gpa;

void* show_gpa(void* arg) {
    // Convert the void pointer back to float pointer
gpa* data = (gpa*)arg;
    
    printf("Student ID is:  %d\n", data->id);
    printf("Thread received GPA: %d\n", data->gpa);
  
    //printf("GPA × 2 = %d\n", data->gpa * 2);

    return NULL;
}

int main() {
    pthread_t t1 , t2;
    gpa data1 = {1169,3};
    gpa data2 = {1168,1};

   
    

    // Pass address of 'gpa' to the thread
    pthread_create(&t1, NULL, show_gpa, &data1);
     pthread_create(&t2, NULL, show_gpa, &data2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread done.\n");
    return 0;
}
