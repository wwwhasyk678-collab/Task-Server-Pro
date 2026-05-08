#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 9090
#define MAX_BUFFER 1024


typedef struct {
    int id;
    char title[100];
    char status[20];
} Task;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};

   
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("[INFO] TaskServer Pro is running on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

       
        int op_code;
        recv(new_socket, &op_code, sizeof(int), 0);

        if (op_code == 101) { 
            Task incoming_task;
            recv(new_socket, &incoming_task, sizeof(Task), 0);
            printf("[LOG] Received Task ID: %d, Title: %s\n", incoming_task.id, incoming_task.title);
            
            send(new_socket, "Success: Task Synced", 20, 0);
        }

        close(new_socket);
    }

    close(server_fd);
    return 0;
}