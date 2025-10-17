 #include <stdio.h>
 #include <pthread.h>
 typedef struct {
 float id;
 char* message;
 } ThreadData;
 void* printData(void* arg) {
 ThreadData* data = (ThreadData*)arg;
 printf("My gpa %f My name is: %s\n", data->id, data->message);
 return NULL;
 }
 int main() {
 pthread_t t1, t2;
 ThreadData data1 = {3.5, "Khizar"};
 ThreadData data2 = {3.5, "Khizar"};
 pthread_create(&t1, NULL, printData, &data1);
 pthread_create(&t2, NULL, printData, &data2);
 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 printf("All threads done.\n");
 return 0;
 }