#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    char buffer[128];
    pipe(pipefd);  // Create a pipe

    int pid1 = fork();

    if (pid1 == 0) {
        // First child process: write to the pipe
        close(pipefd[0]);  // Close reading end
        write(pipefd[1], "Hello from child 1!\n", 21);
        close(pipefd[1]);  // Close writing end
        exit(0);
    }

    int pid2 = fork();

    if (pid2 == 0) {
        // Second child process: read from the pipe
        close(pipefd[1]);  // Close writing end
        read(pipefd[0], buffer, sizeof(buffer));  // Read from pipe
        printf("Child 2 received: %s", buffer);
        close(pipefd[0]);  // Close reading end
        exit(0);
    }

    // Parent process waits for both children
    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}
