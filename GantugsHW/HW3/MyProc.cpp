#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
    } else if (pid == 0) {
            execlp(argv[1], argv[1], NULL);  
    } else {
        int status;
        (void)waitpid(pid, &status, 0);
    }
    return EXIT_SUCCESS;
}