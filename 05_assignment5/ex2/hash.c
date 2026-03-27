#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 100 // Kích thước mảng của bảng băm

// 1. Định nghĩa Node cho danh sách liên kết
struct node {
    char *word;           // Con trỏ lưu chuỗi ký tự (từ)
    int count;            // Tần suất xuất hiện
    struct node *next;    // Con trỏ trỏ đến Node tiếp theo (chaining)
};

// Mảng chứa các con trỏ đầu (head) của danh sách liên kết
struct node* hashtable[HASH_SIZE];

// Hàm băm cơ bản (djb2) để biến 1 chuỗi thành 1 số nguyên (index)
unsigned int hash(const char *word) {
    unsigned int hash = 5381;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % HASH_SIZE;
}

// ==========================================
// YÊU CẦU 1: HÀM LOOKUP (TÌM KIẾM VÀ THÊM MỚI)
// ==========================================
struct node* lookup(const char *word) {
    // Bước 1: Băm từ để lấy vị trí index trong mảng
    unsigned int index = hash(word);
    
    // Bước 2: Tìm trong danh sách liên kết tại vị trí index
    struct node *current = hashtable[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            // Nếu từ đã tồn tại, tăng biến đếm tần suất và trả về node đó
            current->count++;
            return current;
        }
        current = current->next;
    }
    
    // Bước 3: Nếu đi hết danh sách mà chưa thấy -> Từ này là từ mới
    // Cấp phát bộ nhớ cho Node mới
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) return NULL; // Hết RAM
    
    // Copy chuỗi ký tự vào bộ nhớ động (dùng strdup, nó tự động gọi malloc cho chuỗi)
    new_node->word = strdup(word);
    new_node->count = 1; // Xuất hiện lần đầu
    
    // Chèn Node mới vào dau danh sách liên kết
    new_node->next = hashtable[index];
    hashtable[index] = new_node;
    
    return new_node;
}

// ==========================================
// YÊU CẦU 2: HÀM CLEARTABLE (DỌN DẸP BỘ NHỚ)
// ==========================================
void cleartable() {
    // Duyệt qua toàn bộ 100 vị trí của mảng
    for (int i = 0; i < HASH_SIZE; i++) {
        struct node *current = hashtable[i];
        
        // Tại mỗi vị trí, duyệt qua danh sách liên kết để giải phóng từng Node
        while (current != NULL) {
            struct node *temp = current;
            current = current->next; // Nhảy sang node tiếp theo trước khi xóa node hiện tại
            
            // Chú ý: Vì strdup tự malloc cho chuỗi, ta phải free(word) trước
            free(temp->word); 
            // Sau đó mới free bản thân cái Node
            free(temp);       
        }
        hashtable[i] = NULL; // Tránh lỗi con trỏ lơ lửng
    }
    printf("\nDa giai phong toan bo bo nho cua Bang bam (Hash Table).\n");
}

// ==========================================
// HÀM MAIN ĐỂ CHẠY THỬ VÀ ĐỌC FILE
// ==========================================
int main() {
    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file book.txt\n");
        return 1;
    }

    char buffer[100];
    // Đọc từng từ trong file cho đến khi kết thúc (EOF)
    while (fscanf(file, "%99s", buffer) != EOF) {
        // Có thể thêm bước chuẩn hóa: chuyển chữ thường, bỏ dấu câu ở đây nếu cần
        lookup(buffer);
    }
    fclose(file);

    // In kết quả thống kê
    printf("--- KET QUA THONG KE TU VUNG ---\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        struct node *current = hashtable[i];
        while (current != NULL) {
            printf("Tu: '%s' \t - Xuat hien: %d lan\n", current->word, current->count);
            current = current->next;
        }
    }

    // Dọn dẹp RAM trước khi thoát
    cleartable();

    return 0;
}
