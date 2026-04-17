#include <stdio.h>
#include "hashtable.h"

int main() {
    // Tạo mảng các con trỏ (Bảng băm)
    Node *directory[TABLE_SIZE];
    init_table(directory);

    // Test 1: Thêm dữ liệu
    printf("1. Them danh ba:\n");
    insert(directory, "Nguyen Van A", "0901234567");
    insert(directory, "Tran Thi B", "0912345678");
    insert(directory, "Le Van C", "0987654321");
    // Cố tình tạo một tên có khả năng bị trùng index (Collision)
    insert(directory, "A Van Nguyen", "0999999999"); 

    // Hiển thị cấu trúc bên dưới
    display_table(directory);

    // Test 2: Tìm kiếm
    printf("\n2. Tim kiem danh ba:\n");
    char *search_name = "Tran Thi B";
    char *result = search(directory, search_name);
    if (result != NULL) {
        printf("Tim thay '%s': %s\n", search_name, result);
    } else {
        printf("Khong tim thay '%s'\n", search_name);
    }

    // Tìm kiếm người không có thật
    search_name = "Cristiana";
    result = search(directory, search_name);
    if (result != NULL) {
        printf("Tim thay '%s': %s\n", search_name, result);
    } else {
        printf("Khong tim thay '%s'\n", search_name);
    }

    // Dọn dẹp bộ nhớ
    free_table(directory);
    return 0;
}
