#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process closes standard output
        close(STDOUT_FILENO);
        printf("This will not be printed\n");
    } else {
        // Parent process
        wait(NULL);  // Parent waits for the child to finish
        printf("Parent process...\n");
    }
    return 0;
}


/*********************************************
   Your name: Sotiare Kwizera
   Question 1: The printf() in the child process won’t produce any output because the file descriptor for standard output has been closed.
*********************************************/