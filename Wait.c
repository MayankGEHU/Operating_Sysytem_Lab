#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is running...\n", getpid());
        // Simulate some work in the child process
        sleep(2); // Child sleeps for 2 seconds
        printf("Child process (PID: %d) finished.\n", getpid());
        exit(5); // Exit with status 5
    } 
    else {
        // Parent process
        printf("Parent process (PID: %d) waiting for child...\n", getpid());
        // Wait for the child process to finish
        pid = wait(&status);

        if (pid == -1) {
            perror("wait failed");
            return 1;
        }

        // Check if the child terminated normally
        if (WIFEXITED(status)) {
            printf("Child process (PID: %d) terminated with exit status: %d\n", pid, WEXITSTATUS(status));
        } else {
            printf("Child process (PID: %d) did not terminate normally.\n", pid);
        }
    }

    return 0;
}
