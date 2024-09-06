#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        printf("hello\n");
    } else {
        // Parent process
    sleep(1);  // Ensure the child goes first
        printf("goodbye\n");
    }
    return 0;
}

/*********************************************
   Your name: Sotiare Kwizera
   Question 1: Yes, I can do it by calling sleep()
*********************************************/
