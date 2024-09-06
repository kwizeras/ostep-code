#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process...\n");
    } else {
        // Parent process waits for the child to finish
        wait(NULL);
        printf("Child finished, parent continuing...\n");
    }
    return 0;
}


/*********************************************
   Your name: Sotiare Kwizera
   Question 1: if the wait() was in child, the child process should have waited for th parent to complete.
*********************************************/