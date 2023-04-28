#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect Number of Arguments\n");
        return 1;
    }
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socket_address;
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = (atoi(argv[1]));
    socket_address.sin_addr.s_addr = INADDR_ANY;

    int connection = connect(network_socket, (struct sockaddr *) &socket_address, sizeof(socket_address));
    if (connection == -1) {
        printf("Connection unsuccessful - Client Side\n");
        return 2;
    }
    char buffer[3000];
    recv(network_socket, &buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    close(network_socket);
    return 0;
}