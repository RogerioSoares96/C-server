#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>


int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect Number Of Arguments\n");
        return 1;
    }

    char message[256] = "Si Senor it's a C server!\0";

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = (htons(atoi(argv[1])));
    server_address.sin_addr.s_addr = INADDR_ANY;


    int check_bind = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (check_bind == -1) {
        printf("Socket Binding Error\n");
        return 2;
    }
    int check_listen = listen(server_socket, 1);
    if (check_bind == 0) {
        printf("Server Listening on port: %i", (atoi(argv[1])));
    }
    if (check_bind == -1) {
        printf("Listening Error\n");
    }
    int client_socket = accept(server_socket, NULL, NULL);

    send(client_socket, message, sizeof(message), 0);

    close(server_socket);

    return 0;
}