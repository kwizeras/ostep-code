#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process executes /bin/ls
        execl("/bin/ls", "ls", NULL);
    } else {
        // Parent process waits
        wait(NULL);
    }
    return 0;
}

/*********************************************
   Your name: Sotiare Kwizera
   Question 1: There so many variant of exec() because each of them plays a different role
*********************************************/