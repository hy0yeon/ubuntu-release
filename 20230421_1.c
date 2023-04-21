#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_CHILDREN 5

int main(void) {
    pid_t pid, pid_array[NUM_CHILDREN];
    int i;

    for (i = 0; i < NUM_CHILDREN; i++) {
        pid = fork();
        if (pid < 0) {
            printf("fork failed\n");
            exit(1);
        } else if (pid == 0) {
            printf("I am child %d with pid %d\n", i+1, getpid());
            exit(0);
        } else {
            pid_array[i] = pid;
        }
    }

    // Wait for all child processes to terminate before the parent process continues
    for (i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);
    }

    printf("I am the parent process with pid %d\n", getpid());

    for (i = 0; i < NUM_CHILDREN; i++) {
        if (getpid() == pid_array[i]) {
            printf("I am child %d with pid %d\n", i+1, getpid());
            break;
        }
    }

    return 0;
}

