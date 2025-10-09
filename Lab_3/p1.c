#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // Child process: run "top"
        printf("Child Process (PID: %d) is running 'top'...\n", getpid());
        execlp("top", "top", NULL);
        perror("exec failed"); // only runs if execlp fails
    } 
    else {
        // Parent process
        printf("Parent Process (PID: %d) created child with PID: %d\n", getpid(), pid);
        wait(NULL); // wait for child to finish
        printf("Child terminated. Parent exiting.\n");
    }

    return 0;
}
