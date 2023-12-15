#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(PORT);

    connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    printf("Connected to server at %s:%d\n", SERVER_IP, PORT);

    const char* message = "Hello from the client!";
    send(client_socket, message, strlen(message), 0);

    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Server response: %s\n", buffer);

    close(client_socket);

    return 0;
}
