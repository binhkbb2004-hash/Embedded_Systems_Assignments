#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 100 // Kích thước mảng của bảng băm

// Định nghĩa Node cho danh sách liên kết
struct node {
    char *word; // Con trỏ lưu chuỗi ký tự
    int count; // Tần suất xuất hiện
    struct node *next; // Con trỏ trỏ đến Node tiếp theo
};

// Mảng chứa các con trỏ đầu của danh sách liên kết
struct node* hashtable[HASH_SIZE];

// Hàm băm để biến 1 chuỗi thành 1 số nguyên
unsigned int hash(const char *word) {
    unsigned int hash = 5381;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % HASH_SIZE;
}

// YÊU CẦU 1: HÀM LOOKUP (TÌM KIẾM VÀ THÊM MỚI)
struct node* lookup(const char *word) {
    // B1: Băm từ để lấy vị trí index trong mảng
    unsigned int index = hash(word);
    
    // B2: Tìm trong danh sách liên kết tại vị trí index
    struct node *current = hashtable[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            // Nếu từ đã tồn tại, tăng biến đếm tần suất và trả về node đó
            current->count++;
            return current;
        }
        current = current->next;
    }
    
    // B3: Nếu đi hết danh sách mà chưa thấy -> từ mới
    // Cấp phát bộ nhớ cho Node mới
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) return NULL; // Hết RAM
    
    // Copy chuỗi ký tự vào bộ nhớ động
    new_node->word = strdup(word);
    new_node->count = 1; // Xuất hiện lần đầu
    
    // Chèn Node mới vào dau danh sách liên kết
    new_node->next = hashtable[index];
    hashtable[index] = new_node;
    
    return new_node;
}

// YÊU CẦU 2: HÀM CLEARTABLE (DỌN DẸP BỘ NHỚ)
void cleartable() {
    // Duyệt qua toàn bộ 100 vị trí của mảng
    for (int i = 0; i < HASH_SIZE; i++) {
        struct node *current = hashtable[i];
        
        // Tại mỗi vị trí duyệt qua danh sách liên kết để giải phóng từng Node
        while (current != NULL) {
            struct node *temp = current;
            current = current->next; // Nhảy sang node tiếp theo trước khi xóa node hiện tại
            free(temp->word); 
            free(temp);       
        }
        hashtable[i] = NULL;
    }
    printf("\nDa giai phong toan bo bo nho cua Hash Table\n");
}

int main() {
    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file book.txt\n");
        return 1;
    }

    char buffer[100];
    // Đọc từng từ trong file cho đến khi eof
    while (fscanf(file, "%99s", buffer) != EOF) {
        lookup(buffer);
    }
    fclose(file);

    // In kết quả
    printf("--- KET QUA THONG KE TU VUNG ---\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        struct node *current = hashtable[i];
        while (current != NULL) {
            printf("Tu: '%s' \t - Xuat hien: %d lan\n", current->word, current->count);
            current = current->next;
        }
    }

    cleartable();

    return 0;
}
