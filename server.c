#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#define PORT 9090
#define MAX_BUFFER 1024
#define MAX_TASKS 100

typedef struct {
    int id;
    char title[100];
    char status[20];
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
pthread_mutex_t tasks_mutex = PTHREAD_MUTEX_INITIALIZER;

void save_tasks_to_file() {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d,%s,%s\n", task_list[i].id, task_list[i].title, task_list[i].status);
    }
    fclose(file);
    printf("[INFO] Tasks autosaved to tasks.txt\n");
}

void* handle_client(void* socket_desc) {
    int new_socket = *(int*)socket_desc;
    free(socket_desc);
    
    int op_code;
    if (recv(new_socket, &op_code, sizeof(int), 0) <= 0) {
        close(new_socket);
        return NULL;
    }

    if (op_code == 101) { 
        Task my_task;
        recv(new_socket, &my_task, sizeof(Task), 0);
        
        pthread_mutex_lock(&tasks_mutex);
        if (task_count < MAX_TASKS) {
            task_list[task_count] = my_task;
            task_count++;
            save_tasks_to_file();
            char *msg = "Task added successfully on Server.";
            send(new_socket, msg, strlen(msg) + 1, 0);
        } else {
            char *msg = "Server task list is full.";
            send(new_socket, msg, strlen(msg) + 1, 0);
        }
        pthread_mutex_unlock(&tasks_mutex);
    } 
    else if (op_code == 202) { 
        pthread_mutex_lock(&tasks_mutex);
        send(new_socket, &task_count, sizeof(int), 0);
        if (task_count > 0) {
            send(new_socket, task_list, sizeof(Task) * task_count, 0);
        }
        pthread_mutex_unlock(&tasks_mutex);
    }

    close(new_socket);
    return NULL;
}

int main() {
    int server_fd, *new_sock;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

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

    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("[INFO] TaskServer Pro Centralized Server is running on port %d...\n", PORT);

    while (1) {
        int client_sock = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_sock < 0) {
            continue;
        }
        
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;
        
        if (pthread_create(&sniffer_thread, NULL, handle_client, (void*)new_sock) < 0) {
            perror("Could not create thread");
            free(new_sock);
        }
        pthread_detach(sniffer_thread);
    }

    close(server_fd);
    return 0;
}