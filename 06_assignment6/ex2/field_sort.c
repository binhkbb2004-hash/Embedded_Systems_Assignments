#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#define MAXLINES 1000
#define MAXLEN 1000

char *lineptr[MAXLINES]; // Mảng lưu các dòng đọc vào
int numeric = 0;         // Cờ sắp xếp kiểu số
int fold = 0;            // Cờ sắp xếp không phân biệt hoa thường
int field = 1;           // Cột/Trường cần sắp xếp

// Hàm trích xuất từ thứ 'n' (cột n) ra khỏi một dòng
void get_field(char *line, int n, char *word) {
    int i, j = 0, curr_field = 1;
    int len = strlen(line);
    word[0] = '\0'; // Mặc định chuỗi rỗng nếu không tìm thấy

    for (i = 0; i < len; i++) {
        if (isspace(line[i])) {
            // Chuyển sang cột mới khi gặp khoảng trắng
            if (i > 0 && !isspace(line[i-1])) {
                curr_field++;
            }
        } else if (curr_field == n) {
            word[j++] = line[i]; // Chép ký tự vào word nếu đúng cột
        } else if (curr_field > n) {
            break; // Đã qua cột cần tìm => dừng lại
        }
    }
    word[j] = '\0';
}

// Hàm so sánh kiểu số
int numcmp(const char *s1, const char *s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return 0;
}

// Hàm Callback dùng cho qsort
int compare_lines(const void *p1, const void *p2) {
    char word1[MAXLEN], word2[MAXLEN];
    char *s1 = *(char **)p1;
    char *s2 = *(char **)p2;

    // Lấy ra đúng cột để so sánh thay vì so sánh cả dòng
    get_field(s1, field, word1);
    get_field(s2, field, word2);

    // Áp dụng luật so sánh tùy theo các cờ người dùng nhập
    if (numeric) {
        return numcmp(word1, word2);
    } else if (fold) {
        return strcasecmp(word1, word2); // So sánh không phân biệt hoa thường
    } else {
        return strcmp(word1, word2);     // So sánh chuỗi tiêu chuẩn
    }
}

// Hàm đọc các dòng từ giao diện dòng lệnh
int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char line[MAXLEN];
    
    while (fgets(line, MAXLEN, stdin) != NULL && nlines < maxlines) {
        len = strlen(line);
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0'; // Xóa dấu xuống dòng
        
        char *p = malloc(len + 1); // Cáp phát bộ nhớ cho dòng
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

int main(int argc, char *argv[]) {
    // 1. Phân tích các đối số dòng lệnh
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            numeric = 1;
        } else if (strcmp(argv[i], "-f") == 0) {
            fold = 1;
        } else if (strcmp(argv[i], "-k") == 0 && i + 1 < argc) {
            field = atoi(argv[++i]);
        }
    }

    // 2. Đọc dữ liệu đầu vào
    int nlines = readlines(lineptr, MAXLINES);

    // 3. Tiến hành sắp xếp
    qsort(lineptr, nlines, sizeof(char *), compare_lines);

    // 4. In kết quả
    printf("\n--- KET QUA SAP XEP ---\n");
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
        free(lineptr[i]); // Dọn dẹp bộ nhớ đã malloc
    }

    return 0;
}
