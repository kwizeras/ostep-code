#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process...\n");
    } else {
        // Parent process waits for specific child using waitpid()
        waitpid(pid, NULL, 0);
        printf("Child finished, parent continuing...\n");
    }
    return 0;
}

/*********************************************
   Your name: Sotiare Kwizera
   Question 1: waitpid() is usefull when you want to wait for a specific child process by its PID.
*********************************************/
