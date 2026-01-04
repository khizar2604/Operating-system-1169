
//Write a C program that:

//1.  Defines a structure containing:   Student ID (integer)

 // Student Name (string - max 50 chars)   Marks (float)

  //Grade (char - to be calculated by thread)

//2.  Create an array of 3 student records with sample data

//3.  Create 3 threads, each thread receives one student structure and:   Determines grade based on marks:

  //= 85: Grade A

 

 

  //= 70: Grade B

 

 

  //= 60: Grade C

 

 

  //= 50: Grade D

 

  //< 50: Grade F

  //Prints the student information with the calculated grade

//4.  Main thread waits for all threads to complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
typedef struct 
{
  // structure of student data
  int id;
  char name[50];
  float marks;
  char grade;
}Student;
char getGrade(float marks){
  // loop to evaluate marks.
  if (marks>=85) return 'A';
  else if (marks>=70) return 'B';
  else if (marks>=60) return 'C';
  else if (marks>=50) return 'D';
  else return 'F';
}
void* calculatorGrade(void* arg){ 
  Student* s = (Student*)arg; // convert void pointer to student
  s->grade = getGrade(s->marks); // it evaluate grade and store in student structure

  //printout the data of student
  printf("Student ID: %d\n",s->id);
  printf("STUDENT NAME: %s\n",s->name);
  printf("MARKS : %.2f\n",s->marks);
  printf("Garade: %c\n",s->grade);
  pthread_exit(NULL);
}
 int main(){
  Student students[3]={ // Array of three students
    {1129,"Ahmad",70.5, ' '},
    {1169,"Khizar",92.5, ' '},
    {1144,"Dawar",48.5, ' '}
  };
  pthread_t threads[3]; //it hold id and create thread

  for(int i=0; i<3; i++){
    if (pthread_create(&threads[i], NULL, calculatorGrade, &students[i]) !=0) // craete a thread
    {
      printf("Error in Creating Thread %d\n", i + 1);
      return 1;
    }
  }
  for (int i=0; i<3; i++){
    pthread_join(threads[i], NULL); // wait for all thread to complete
  }
  printf("\n All Thread finished. Grade is calculated successfully!\n");
  return 0;
}