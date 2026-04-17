#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

// 1. Hàm Băm (Hash Function) - Áp dụng nhân với số nguyên tố 31
unsigned int hash(char *str) {
    unsigned int hash_value = 0;
    while (*str) {
        hash_value = (hash_value * 31) + *str; // Nhân 31 và cộng mã ASCII của ký tự
        str++;
    }
    return hash_value % TABLE_SIZE; // Chia lấy dư để ép giá trị vào mảng buckets
}

// Hàm khởi tạo mảng buckets ban đầu với các con trỏ NULL
void init_table(Node **buckets) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        buckets[i] = NULL;
    }
}

// 2. Hàm Thêm liên hệ (Insert) với cơ chế Chaining
void insert(Node **buckets, char *name, char *phone) {
    unsigned int index = hash(name);
    
    // Cấp phát bộ nhớ cho nút mới
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    
    // Chèn vào ĐẦU danh sách liên kết tại vị trí index (để xử lý collision nhanh nhất)
    newNode->next = buckets[index];
    buckets[index] = newNode;
    
    printf("Da them: %s - %s (Index: %d)\n", name, phone, index);
}

// 3. Hàm Tìm kiếm (Search)
char* search(Node **buckets, char *name) {
    unsigned int index = hash(name);
    Node *current = buckets[index];
    
    // Duyệt qua danh sách liên kết tại ô index đó
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->phone; // Trả về số điện thoại nếu tên khớp
        }
        current = current->next;
    }
    return NULL; // Không tìm thấy
}

// Hàm hiển thị toàn bộ danh bạ (Hỗ trợ kiểm tra)
void display_table(Node **buckets) {
    printf("\n--- DANH BA DIEN THOAI ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (buckets[i] != NULL) {
            printf("Bucket [%d]: ", i);
            Node *current = buckets[i];
            while (current != NULL) {
                printf("[%s: %s] -> ", current->name, current->phone);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("--------------------------\n");
}

// Hàm giải phóng bộ nhớ để tránh Memory Leak
void free_table(Node **buckets) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = buckets[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        buckets[i] = NULL;
    }
}
