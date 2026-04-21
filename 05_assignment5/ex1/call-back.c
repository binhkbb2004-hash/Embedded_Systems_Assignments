#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cấu trúc bản ghi cho 1 người
typedef struct {
    char firstname[50];
    char lastname[50];
    int age;
} Record;

// YÊU CẦU 1: CÁC HÀM CALLBACK CHO QSORT

// Hàm callback để sắp xếp theo Tên
int compare_firstname(const void* pa, const void* pb) {
    // Ép kiểu con trỏ vô kiểu về lại con trỏ Record
    const Record* r1 = (const Record*)pa;
    const Record* r2 = (const Record*)pb;
    
    // Sử dụng strcmp để so sánh 2 chuỗi
    return strcmp(r1->firstname, r2->firstname);
}

// Hàm callback để sắp xếp theo Họ
int compare_lastname(const void* pa, const void* pb) {
    const Record* r1 = (const Record*)pa;
    const Record* r2 = (const Record*)pb;
    
    return strcmp(r1->lastname, r2->lastname);
}

// YÊU CẦU 2: HÀM APPLY VÀ ISOLDER

// Hàm isolder: In ra màn hình nếu tuổi > 20
void isolder(Record* rec) {
    if (rec->age > 20) {
        printf("  - %s %s, Age: %d\n", rec->firstname, rec->lastname, rec->age);
    }
}

// Hàm apply: Duyệt qua mảng và gọi một hàm callback cho từng phần tử
void apply(Record* arr, int num, void (*fp)(Record*)) {
    for (int i = 0; i < num; i++) {
        fp(&arr[i]); // Truyền địa chỉ vào hàm callback
    }
}

// Hàm in toàn bộ mảng
void print_array(Record* arr, int num) {
    for(int i = 0; i < num; i++){
        printf("  %s %s, Age: %d\n", arr[i].firstname, arr[i].lastname, arr[i].age);
    }
    printf("\n");
}

int main() {
    // Khởi tạo một mảng chứa thông tin người
    Record class_records[] = {
        {"Tom", "Messi", 60},
        {"Cristiana", "Vinicius", 27},
        {"Tom", "Florentino", 27},
        {"Kylian", "Lukaka", 19},
        {"Keanu", "Reeves", 58},
        {"Iain", "Armitage", 15}
    };
    int num_records = sizeof(class_records) / sizeof(class_records[0]);

    printf("--- DANH SACH GOC ---\n");
    print_array(class_records, num_records);

    // Sắp xếp theo First Name
    printf("--- SAP XEP THEO FIRST NAME ---\n");
    qsort(class_records, num_records, sizeof(Record), compare_firstname);
    print_array(class_records, num_records);

    //  Sắp xếp theo Last Name
    printf("--- SAP XEP THEO LAST NAME ---\n");
    qsort(class_records, num_records, sizeof(Record), compare_lastname);
    print_array(class_records, num_records);

    //  những người > 20 tuổi
    printf("--- DANH SACH NHUNG NGUOI TREN 20 TUOI ---\n");
    apply(class_records, num_records, isolder);
    printf("\n");

    return 0;
}
