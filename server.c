#include "common.h"

Product products[MAX_PRODUCTS];
int product_count = 0;
pthread_mutex_t product_mutex = PTHREAD_MUTEX_INITIALIZER;

User users[MAX_USERS];
int user_count = 0;
pthread_mutex_t user_mutex = PTHREAD_MUTEX_INITIALIZER;

Order orders[MAX_ORDERS];
int order_count = 0;
pthread_mutex_t order_mutex = PTHREAD_MUTEX_INITIALIZER;

int next_product_id = 1;
int next_user_id = 1;
int next_order_id = 1;

void initialize_products() {
    pthread_mutex_lock(&product_mutex);
    
    strcpy(products[0].name, "Laptop Dell XPS");
    strcpy(products[0].description, "High-performance laptop");
    strcpy(products[0].category, "Electronics");
    products[0].price = 1299.99;
    products[0].stock = 10;
    products[0].id = next_product_id++;
    products[0].active = 1;
    
    strcpy(products[1].name, "iPhone 15 Pro");
    strcpy(products[1].description, "Latest Apple smartphone");
    strcpy(products[1].category, "Electronics");
    products[1].price = 999.99;
    products[1].stock = 15;
    products[1].id = next_product_id++;
    products[1].active = 1;
    
    strcpy(products[2].name, "Samsung Galaxy S24");
    strcpy(products[2].description, "Premium Android phone");
    strcpy(products[2].category, "Electronics");
    products[2].price = 899.99;
    products[2].stock = 20;
    products[2].id = next_product_id++;
    products[2].active = 1;
    
    strcpy(products[3].name, "Sony Headphones");
    strcpy(products[3].description, "Noise cancelling headphones");
    strcpy(products[3].category, "Electronics");
    products[3].price = 299.99;
    products[3].stock = 30;
    products[3].id = next_product_id++;
    products[3].active = 1;
    
    strcpy(products[4].name, "iPad Air");
    strcpy(products[4].description, "Lightweight tablet");
    strcpy(products[4].category, "Electronics");
    products[4].price = 599.99;
    products[4].stock = 12;
    products[4].id = next_product_id++;
    products[4].active = 1;
    
    strcpy(products[5].name, "Clean Code Book");
    strcpy(products[5].description, "Software engineering book");
    strcpy(products[5].category, "Books");
    products[5].price = 45.99;
    products[5].stock = 50;
    products[5].id = next_product_id++;
    products[5].active = 1;
    
    strcpy(products[6].name, "The Pragmatic Programmer");
    strcpy(products[6].description, "Programming best practices");
    strcpy(products[6].category, "Books");
    products[6].price = 39.99;
    products[6].stock = 40;
    products[6].id = next_product_id++;
    products[6].active = 1;
    
    strcpy(products[7].name, "Design Patterns Book");
    strcpy(products[7].description, "Gang of Four patterns");
    strcpy(products[7].category, "Books");
    products[7].price = 54.99;
    products[7].stock = 35;
    products[7].id = next_product_id++;
    products[7].active = 1;
    
    strcpy(products[8].name, "Nike Air Max");
    strcpy(products[8].description, "Running shoes");
    strcpy(products[8].category, "Clothing");
    products[8].price = 129.99;
    products[8].stock = 25;
    products[8].id = next_product_id++;
    products[8].active = 1;
    
    strcpy(products[9].name, "Levi's Jeans");
    strcpy(products[9].description, "Classic denim jeans");
    strcpy(products[9].category, "Clothing");
    products[9].price = 79.99;
    products[9].stock = 40;
    products[9].id = next_product_id++;
    products[9].active = 1;
    
    strcpy(products[10].name, "Adidas Hoodie");
    strcpy(products[10].description, "Comfortable hoodie");
    strcpy(products[10].category, "Clothing");
    products[10].price = 59.99;
    products[10].stock = 30;
    products[10].id = next_product_id++;
    products[10].active = 1;
    
    strcpy(products[11].name, "Dyson Vacuum Cleaner");
    strcpy(products[11].description, "Cordless vacuum");
    strcpy(products[11].category, "Home");
    products[11].price = 449.99;
    products[11].stock = 8;
    products[11].id = next_product_id++;
    products[11].active = 1;
    
    strcpy(products[12].name, "Instant Pot");
    strcpy(products[12].description, "Multi-cooker");
    strcpy(products[12].category, "Home");
    products[12].price = 89.99;
    products[12].stock = 20;
    products[12].id = next_product_id++;
    products[12].active = 1;
    
    strcpy(products[13].name, "Air Fryer");
    strcpy(products[13].description, "Healthy cooking appliance");
    strcpy(products[13].category, "Home");
    products[13].price = 119.99;
    products[13].stock = 15;
    products[13].id = next_product_id++;
    products[13].active = 1;
    
    strcpy(products[14].name, "Yoga Mat");
    strcpy(products[14].description, "Non-slip exercise mat");
    strcpy(products[14].category, "Sports");
    products[14].price = 29.99;
    products[14].stock = 50;
    products[14].id = next_product_id++;
    products[14].active = 1;
    
    product_count = 15;
    
    pthread_mutex_unlock(&product_mutex);
    printf("[*] Initialized %d products\n", product_count);
}

void initialize_users() {
    pthread_mutex_lock(&user_mutex);
    
    strcpy(users[0].username, "john");
    strcpy(users[0].password, "john123");
    strcpy(users[0].email, "john@example.com");
    users[0].type = USER_CUSTOMER;
    users[0].balance = 5000.0;
    users[0].id = next_user_id++;
    users[0].cart.item_count = 0;
    users[0].cart.total = 0.0;
    users[0].cart.user_id = users[0].id;
    
    strcpy(users[1].username, "sara");
    strcpy(users[1].password, "sara123");
    strcpy(users[1].email, "sara@example.com");
    users[1].type = USER_CUSTOMER;
    users[1].balance = 3000.0;
    users[1].id = next_user_id++;
    users[1].cart.item_count = 0;
    users[1].cart.total = 0.0;
    users[1].cart.user_id = users[1].id;
    
    strcpy(users[2].username, "admin");
    strcpy(users[2].password, "admin123");
    strcpy(users[2].email, "admin@example.com");
    users[2].type = USER_ADMIN;
    users[2].balance = 0.0;
    users[2].id = next_user_id++;
    users[2].cart.item_count = 0;
    users[2].cart.total = 0.0;
    users[2].cart.user_id = users[2].id;
    
    user_count = 3;
    
    pthread_mutex_unlock(&user_mutex);
    printf("[*] Initialized %d users\n", user_count);
}

User* find_user(const char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

Product* find_product(int product_id) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == product_id && products[i].active) {
            return &products[i];
        }
    }
    return NULL;
}

void handle_login(Request *req, Response *res) {
    pthread_mutex_lock(&user_mutex);
    
    User *user = find_user(req->login.username);
    
    if (user && strcmp(user->password, req->login.password) == 0) {
        if (user->type == USER_CUSTOMER) {
            res->success = 1;
            strcpy(res->message, "Login successful! Welcome back.");
            res->user = *user;
            printf("[+] User '%s' logged in successfully\n", user->username);
        } else {
            res->success = 0;
            strcpy(res->message, "Invalid credentials for customer login");
        }
    } else {
        res->success = 0;
        strcpy(res->message, "Invalid username or password");
        printf("[-] Failed login attempt for username: %s\n", req->login.username);
    }
    
    pthread_mutex_unlock(&user_mutex);
}

void handle_admin_login(Request *req, Response *res) {
    pthread_mutex_lock(&user_mutex);
    
    User *user = find_user(req->login.username);
    
    if (user && strcmp(user->password, req->login.password) == 0) {
        if (user->type == USER_ADMIN) {
            res->success = 1;
            strcpy(res->message, "Admin login successful!");
            res->user = *user;
            printf("[+] Admin '%s' logged in\n", user->username);
        } else {
            res->success = 0;
            strcpy(res->message, "Not an admin account");
        }
    } else {
        res->success = 0;
        strcpy(res->message, "Invalid admin credentials");
        printf("[-] Failed admin login attempt: %s\n", req->login.username);
    }
    
    pthread_mutex_unlock(&user_mutex);
}

void handle_register(Request *req, Response *res) {
    pthread_mutex_lock(&user_mutex);
    
    if (user_count >= MAX_USERS) {
        res->success = 0;
        strcpy(res->message, "Maximum users reached");
        pthread_mutex_unlock(&user_mutex);
        return;
    }
    
    if (find_user(req->register_data.username)) {
        res->success = 0;
        strcpy(res->message, "Username already exists");
        pthread_mutex_unlock(&user_mutex);
        return;
    }
    
    User *new_user = &users[user_count];
    strcpy(new_user->username, req->register_data.username);
    strcpy(new_user->password, req->register_data.password);
    strcpy(new_user->email, req->register_data.email);
    new_user->type = USER_CUSTOMER;
    new_user->balance = 1000.0;
    new_user->id = next_user_id++;
    new_user->cart.item_count = 0;
    new_user->cart.total = 0.0;
    new_user->cart.user_id = new_user->id;
    
    user_count++;
    
    res->success = 1;
    strcpy(res->message, "Registration successful! Starting balance: $1000");
    res->user = *new_user;
    
    printf("[+] New user registered: %s\n", new_user->username);
    
    pthread_mutex_unlock(&user_mutex);
}

void handle_view_products(Request *req, Response *res) {
    (void)req;
    pthread_mutex_lock(&product_mutex);
    
    res->product_count = 0;
    for (int i = 0; i < product_count && res->product_count < MAX_PRODUCTS; i++) {
        if (products[i].active) {
            res->products[res->product_count++] = products[i];
        }
    }
    
    res->success = 1;
    sprintf(res->message, "Found %d products", res->product_count);
    
    pthread_mutex_unlock(&product_mutex);
}

void handle_search_products(Request *req, Response *res) {
    pthread_mutex_lock(&product_mutex);
    
    res->product_count = 0;
    
    for (int i = 0; i < product_count && res->product_count < MAX_PRODUCTS; i++) {
        if (!products[i].active) continue;
        
        int match = 0;
        
        if (strlen(req->search.search_term) > 0) {
            if (strstr(products[i].name, req->search.search_term) ||
                strstr(products[i].description, req->search.search_term)) {
                match = 1;
            }
        }
        
        if (strlen(req->search.category) > 0) {
            if (strcmp(products[i].category, req->search.category) == 0) {
                match = 1;
            }
        }
        
        if (strlen(req->search.search_term) == 0 && strlen(req->search.category) == 0) {
            match = 1;
        }
        
        if (match) {
            res->products[res->product_count++] = products[i];
        }
    }
    
    res->success = 1;
    sprintf(res->message, "Found %d matching products", res->product_count);
    
    pthread_mutex_unlock(&product_mutex);
}

void handle_add_to_cart(Request *req, Response *res) {
    pthread_mutex_lock(&user_mutex);
    pthread_mutex_lock(&product_mutex);
    
    User *user = NULL;
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == req->cart_op.product_id) {
            continue;
        }
    }
    
    Product *product = find_product(req->cart_op.product_id);
    
    if (!product) {
        res->success = 0;
        strcpy(res->message, "Product not found");
        pthread_mutex_unlock(&product_mutex);
        pthread_mutex_unlock(&user_mutex);
        return;
    }
    
    if (product->stock < req->cart_op.quantity) {
        res->success = 0;
        sprintf(res->message, "Insufficient stock. Available: %d", product->stock);
        pthread_mutex_unlock(&product_mutex);
        pthread_mutex_unlock(&user_mutex);
        return;
    }
    
    pthread_mutex_unlock(&product_mutex);
    pthread_mutex_unlock(&user_mutex);
    
    res->success = 1;
    strcpy(res->message, "Item added to cart successfully");
}

void handle_checkout(Request *req, Response *res) {
    (void)req;
    res->success = 1;
    strcpy(res->message, "Order placed successfully!");
}

void handle_add_product(Request *req, Response *res) {
    pthread_mutex_lock(&product_mutex);
    
    if (product_count >= MAX_PRODUCTS) {
        res->success = 0;
        strcpy(res->message, "Maximum products reached");
        pthread_mutex_unlock(&product_mutex);
        return;
    }
    
    products[product_count] = req->add_product.product;
    products[product_count].id = next_product_id++;
    products[product_count].active = 1;
    product_count++;
    
    res->success = 1;
    strcpy(res->message, "Product added successfully");
    
    pthread_mutex_unlock(&product_mutex);
}

void handle_update_stock(Request *req, Response *res) {
    pthread_mutex_lock(&product_mutex);
    
    Product *product = find_product(req->update_stock.product_id);
    
    if (product) {
        product->stock = req->update_stock.quantity;
        res->success = 1;
        sprintf(res->message, "Stock updated to %d", product->stock);
    } else {
        res->success = 0;
        strcpy(res->message, "Product not found");
    }
    
    pthread_mutex_unlock(&product_mutex);
}

void handle_view_all_orders(Request *req, Response *res) {
    (void)req;
    pthread_mutex_lock(&order_mutex);
    
    res->order_count = 0;
    for (int i = 0; i < order_count && res->order_count < MAX_ORDERS; i++) {
        res->orders[res->order_count++] = orders[i];
    }
    
    res->success = 1;
    sprintf(res->message, "Found %d orders", res->order_count);
    
    pthread_mutex_unlock(&order_mutex);
}

void process_request(Request *req, Response *res) {
    memset(res, 0, sizeof(Response));
    
    switch (req->type) {
        case REQ_LOGIN:
            handle_login(req, res);
            break;
        case REQ_ADMIN_LOGIN:
            handle_admin_login(req, res);
            break;
        case REQ_REGISTER:
            handle_register(req, res);
            break;
        case REQ_VIEW_PRODUCTS:
            handle_view_products(req, res);
            break;
        case REQ_SEARCH_PRODUCTS:
            handle_search_products(req, res);
            break;
        case REQ_ADD_TO_CART:
            handle_add_to_cart(req, res);
            break;
        case REQ_CHECKOUT:
            handle_checkout(req, res);
            break;
        case REQ_ADD_PRODUCT:
            handle_add_product(req, res);
            break;
        case REQ_UPDATE_STOCK:
            handle_update_stock(req, res);
            break;
        case REQ_VIEW_ALL_ORDERS:
            handle_view_all_orders(req, res);
            break;
        default:
            res->success = 0;
            strcpy(res->message, "Unknown request type");
            break;
    }
}

void *handle_client(void *arg) {
    int client_sock = *((int *)arg);
    free(arg);
    
    Request req;
    Response res;
    
    printf("[*] New client connected (socket: %d)\n", client_sock);
    
    while (1) {
        memset(&req, 0, sizeof(Request));
        memset(&res, 0, sizeof(Response));
        
        ssize_t received = 0;
        ssize_t total_received = 0;
        char *req_ptr = (char *)&req;
        
        while (total_received < sizeof(Request)) {
            received = recv(client_sock, req_ptr + total_received, 
                          sizeof(Request) - total_received, 0);
            
            if (received <= 0) {
                if (received == 0) {
                    printf("[*] Client disconnected (socket: %d)\n", client_sock);
                } else {
                    perror("Receive failed");
                }
                close(client_sock);
                return NULL;
            }
            
            total_received += received;
        }
        
        printf("[*] Received request type: %d from socket %d\n", 
               req.type, client_sock);
        
        process_request(&req, &res);
        
        ssize_t sent = 0;
        ssize_t total_sent = 0;
        char *res_ptr = (char *)&res;
        
        while (total_sent < sizeof(Response)) {
            sent = send(client_sock, res_ptr + total_sent, 
                       sizeof(Response) - total_sent, 0);
            
            if (sent < 0) {
                perror("Send failed");
                close(client_sock);
                return NULL;
            }
            
            total_sent += sent;
        }
        
        printf("[*] Sent response (success: %d) to socket %d\n", 
               res.success, client_sock);
    }
    
    close(client_sock);
    return NULL;
}

int main() {
    int server_sock, *new_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    
    printf("===========================================\n");
    printf("   E-Commerce Server Starting...\n");
    printf("===========================================\n\n");
    
    initialize_products();
    initialize_users();
    
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        return 1;
    }
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    
    if (listen(server_sock, 10) < 0) {
        perror("Listen failed");
        return 1;
    }
    
    printf("[+] Server listening on port %d\n", PORT);
    printf("[*] Available products: %d\n", product_count);
    printf("[*] Registered users: %d\n\n", user_count);
    printf("Waiting for connections...\n\n");
    
    while (1) {
        new_sock = malloc(sizeof(int));
        *new_sock = accept(server_sock, (struct sockaddr *)&client, &client_len);
        
        if (*new_sock < 0) {
            perror("Accept failed");
            free(new_sock);
            continue;
        }
        
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void *)new_sock) != 0) {
            perror("Thread creation failed");
            free(new_sock);
            continue;
        }
        
        pthread_detach(thread);
    }
    
    close(server_sock);
    return 0;
}