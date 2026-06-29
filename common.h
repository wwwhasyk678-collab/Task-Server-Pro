#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_PRODUCTS 100
#define MAX_USERS 100
#define MAX_ORDERS 1000
#define MAX_CART_ITEMS 50
#define USERNAME_SIZE 50
#define PASSWORD_SIZE 50
#define EMAIL_SIZE 100
#define NAME_SIZE 100
#define DESCRIPTION_SIZE 500
#define CATEGORY_SIZE 50
#define ADDRESS_SIZE 200

typedef enum {
    REQ_LOGIN,
    REQ_REGISTER,
    REQ_ADMIN_LOGIN,
    REQ_VIEW_PRODUCTS,
    REQ_SEARCH_PRODUCTS,
    REQ_ADD_TO_CART,
    REQ_VIEW_CART,
    REQ_REMOVE_FROM_CART,
    REQ_UPDATE_CART,
    REQ_CHECKOUT,
    REQ_VIEW_ORDERS,
    REQ_VIEW_ORDER_DETAILS,
    REQ_CANCEL_ORDER,
    REQ_ADD_PRODUCT,
    REQ_UPDATE_STOCK,
    REQ_VIEW_ALL_ORDERS,
    REQ_UPDATE_ORDER_STATUS
} RequestType;

typedef enum {
    PAYMENT_CREDIT_CARD,
    PAYMENT_DEBIT_CARD,
    PAYMENT_ACCOUNT_BALANCE
} PaymentMethod;

typedef enum {
    ORDER_PENDING,
    ORDER_PROCESSING,
    ORDER_SHIPPED,
    ORDER_DELIVERED,
    ORDER_CANCELLED
} OrderStatus;

typedef enum {
    USER_CUSTOMER,
    USER_ADMIN
} UserType;

typedef struct {
    int id;
    char name[NAME_SIZE];
    char description[DESCRIPTION_SIZE];
    char category[CATEGORY_SIZE];
    double price;
    int stock;
    int active;
} Product;

typedef struct {
    int product_id;
    int quantity;
    double price;
} CartItem;

typedef struct {
    int user_id;
    CartItem items[MAX_CART_ITEMS];
    int item_count;
    double total;
} Cart;

typedef struct {
    int id;
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    char email[EMAIL_SIZE];
    UserType type;
    double balance;
    Cart cart;
} User;

typedef struct {
    int id;
    int user_id;
    CartItem items[MAX_CART_ITEMS];
    int item_count;
    double total;
    OrderStatus status;
    PaymentMethod payment_method;
    char delivery_address[ADDRESS_SIZE];
    time_t order_date;
} Order;

typedef struct {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
} LoginData;

typedef struct {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    char email[EMAIL_SIZE];
} RegisterData;

typedef struct {
    char search_term[NAME_SIZE];
    char category[CATEGORY_SIZE];
} SearchData;

typedef struct {
    int product_id;
    int quantity;
} CartOperation;

typedef struct {
    PaymentMethod method;
    char delivery_address[ADDRESS_SIZE];
} CheckoutData;

typedef struct {
    int order_id;
} OrderOperation;

typedef struct {
    Product product;
} AddProductData;

typedef struct {
    int product_id;
    int quantity;
} UpdateStockData;

typedef struct {
    int order_id;
    OrderStatus new_status;
} UpdateOrderStatusData;

typedef struct {
    RequestType type;
    union {
        LoginData login;
        RegisterData register_data;
        SearchData search;
        CartOperation cart_op;
        CheckoutData checkout;
        OrderOperation order_op;
        AddProductData add_product;
        UpdateStockData update_stock;
        UpdateOrderStatusData update_order_status;
    };
} Request;

typedef struct {
    int success;
    char message[500];
    User user;
    Product products[MAX_PRODUCTS];
    int product_count;
    Cart cart;
    Order orders[MAX_ORDERS];
    int order_count;
    Order order;
} Response;

#endif