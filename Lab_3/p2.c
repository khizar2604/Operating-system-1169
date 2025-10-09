#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execlp("date", "date", NULL);
        perror("execlp failed");
    } else if (pid > 0) {
        wait(NULL);
        printf("Child finished\n");
    } else {
        perror("fork failed");
    }

    return 0;
}
