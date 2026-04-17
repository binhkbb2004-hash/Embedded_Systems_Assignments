#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 100 // Kích thước của bảng băm (mảng buckets)

// Cấu trúc một Nút trong danh sách liên kết
typedef struct Node {
    char name[50];
    char phone[20];
    struct Node *next;
} Node;

// Khai báo các hàm sẽ sử dụng
unsigned int hash(char *str);
void init_table(Node **buckets);
void insert(Node **buckets, char *name, char *phone);
char* search(Node **buckets, char *name);
void display_table(Node **buckets);
void free_table(Node **buckets);

#endif
