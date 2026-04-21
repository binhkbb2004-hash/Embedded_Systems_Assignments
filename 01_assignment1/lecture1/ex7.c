#include <stdio.h>

#define MAXLINE 1000

// Hàm đọc một dòng, trả về độ dài của dòng đó
int get_line(char line[], int maxline);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        // len-1 là vị trí ký tự ngay trước \0
        // Nếu là \n bắt đầu kiểm tra từ ký tự trước đó
        int i = len - 1;
        
        // Lùi lại nếu gặp \n, ' ' hoặc \t
        if (line[i] == '\n') {
            i--;
        }
        
        while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) {
            i--;
        }

        // Nếu i >= 0 dòng này chứa ký tự thực
        if (i >= 0) {
            line[i + 1] = '\n'; // Thêm lại ký tự xuống dòng
            line[i + 2] = '\0'; // Kết thúc chuỗi
            printf("%s", line);
        }
        // Nếu i < 0 dòng trống hoặc
    }

    return 0;
}

int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
