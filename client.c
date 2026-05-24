#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 9090
typedef struct {
    int id;
    char title[100];
    char status[20];
} Task;
void connect_to_server(int *sock) {
    struct sockaddr_in serv_addr;
    if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    if (connect(*sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed. Ensure Server is running! \n");
        exit(EXIT_FAILURE);
    }
}
int main() {
    int sock;
    char buffer[1024] = {0};
    int choice;

    printf("=== Task Server Pro CLI Client ===\n");
    printf("1. Add New Task (Op-Code 101)\n");
    printf("2. List & Sync Tasks (Op-Code 202)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int op_code = 101;
        Task my_task;
        
        printf("Enter Task ID (Integer): ");
        scanf("%d", &my_task.id);
        getchar(); // تنظيف البافر
        printf("Enter Task Title: ");
        fgets(my_task.title, sizeof(my_task.title), stdin);
        my_task.title[strcspn(my_task.title, "\n")] = 0; 
        strcpy(my_task.status, "Pending");

        connect_to_server(&sock);
        send(sock, &op_code, sizeof(int), 0);
        send(sock, &my_task, sizeof(Task), 0);

        read(sock, buffer, 1024);
        printf("\nServer Response: %s\n", buffer);
        close(sock);
    }
     else if (choice == 2) {
        int op_code = 202;
        int total_tasks = 0;
        connect_to_server(&sock);
        send(sock, &op_code, sizeof(int), 0);
        recv(sock, &total_tasks, sizeof(int), 0);
        printf("\n--- Synchronized Task List (%d Tasks Found) ---\n", total_tasks);

        if (total_tasks > 0) {
            Task *received_tasks = malloc(sizeof(Task) * total_tasks);
            recv(sock, received_tasks, sizeof(Task) * total_tasks, 0);
            
            for (int i = 0; i < total_tasks; i++) {
                printf("[%d] Title: %s | Status: %s\n", received_tasks[i].id, received_tasks[i].title, received_tasks[i].status);
            }
            free(received_tasks);
        } else {
            printf("No tasks on the server database.\n");
        }
        close(sock);
    } else {
        printf("Invalid Choice.\n");
    }

    return 0;
}