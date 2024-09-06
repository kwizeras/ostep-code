#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int pid = fork();

    if (pid == 0) {
        // Child process
        write(fd, "Child writing...\n", 17);
    } else {
        // Parent process
        write(fd, "Parent writing...\n", 18);
    }

    close(fd);
    return 0;
}
