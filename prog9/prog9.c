#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    char message_to_child[] = "Hello from the parent!";
    char message_from_parent[100];

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    if (fork() > 0) {  // Parent process
        close(pipe_fd[0]); // Close the read end of the pipe
        write(pipe_fd[1], message_to_child, sizeof(message_to_child)); // Write to the pipe
        close(pipe_fd[1]); // Close the write end of the pipe
        wait(NULL); // Wait for the child to finish
    } else {  // Child process
        close(pipe_fd[1]); // Close the write end of the pipe
        read(pipe_fd[0], message_from_parent, sizeof(message_from_parent)); // Read from the pipe
        close(pipe_fd[0]); // Close the read end of the pipe
        printf("Child received message: %s\n", message_from_parent); // Display the received message
    }

    return 0;
}
