#include <stdio.h>

#define MAX_CHAR 256 // Kích thước bảng mã ASCII chuẩn

int main() {
    int c, i, j;
    int freq[MAX_CHAR];

    // Khởi tạo tất cả tần suất bằng 0
    for (i = 0; i < MAX_CHAR; i++) {
        freq[i] = 0;
    }

    printf("Nhập văn bản:\n");

    // Đọc từng ký tự cho đến khi gặp EOF
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < MAX_CHAR) {
            freq[c]++;
        }
    }

    printf("\n--- Biểu đồ tần suất ký tự ---\n");
    for (i = 0; i < MAX_CHAR; i++) {
        // Chỉ in những ký tự có xuất hiện ít nhất 1 lần
        if (freq[i] > 0) {
            // Xử lý hiển thị cho các ký tự đặc biệt
            if (i == ' ') printf("' '  : ");
            else if (i == '\n') printf("\\n   : ");
            else if (i == '\t') printf("\\t   : ");
            else if (i >= 32 && i <= 126) printf("%-4c : ", i);
            else printf("0x%02X : ", i); // Ký tự không in được hiển thị mã Hex

            // Vẽ bằng dấu '*'
            for (j = 0; j < freq[i]; j++) {
                putchar('*');
            }
            printf(" (%d)\n", freq[i]);
        }
    }

    return 0;
}
