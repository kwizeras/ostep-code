#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 50;
    int pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child: x = %d\n", x);
        x = 20;
        printf("Child: x changed to %d\n", x);
    } else {
        // Parent process
        printf("Parent: x = %d\n", x);
        x = 10;
        printf("Parent: x changed to %d\n", x);
    }
    return 0;
}

/*********************************************
   Your name: Sotiare Kwizera
   Question 1: Child: x = 50
   Question 2: Parent: x changed to 10
               Child: x changed to 20
*********************************************/