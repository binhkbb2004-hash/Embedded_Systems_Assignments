#include <stdio.h>
#include <string.h>

// Hàm kiểm tra chuỗi t có nằm ở cuối chuỗi s hay không
int strend(const char *s, const char *t) {
    int len_s = strlen(s); // Tính độ dài chuỗi s
    int len_t = strlen(t); // Tính độ dài chuỗi t

    // Nếu chuỗi t dài hơn chuỗi s => t không nằm ở cuối s
    if (len_t > len_s) {
        return 0;
    }

    // Dịch chuyển con trỏ s đến đúng vị trí bắt đầu phần đuôi cần so sánh
    s += (len_s - len_t);

    // So sánh phần đuôi của s với t
    if (strcmp(s, t) == 0) {
        return 1; // Khớp hoàn toàn
    } else {
        return 0; // Không khớp
    }
}

int main() {
    printf("--- KIEM TRA HAM STREND ---\n");

    // Test case 1: t nằm ở cuối s (Exp: 1)
    printf("Test 1 - strend(\"hello world\", \"world\"): %d\n", strend("hello world", "world"));

    // Test case 2: t nằm ở đầu s, không phải cuối (Exp: 0)
    printf("Test 2 - strend(\"hello world\", \"hello\"): %d\n", strend("hello world", "hello"));

    // Test case 3: t dài hơn s (Exp: 0)
    printf("Test 3 - strend(\"abc\", \"defabc\"): %d\n", strend("abc", "defabc"));

    // Test case 4: Khớp chuỗi ngắn (Exp: 1)
    printf("Test 4 - strend(\"programming\", \"ing\"): %d\n", strend("programming", "ing"));

    return 0;
}
