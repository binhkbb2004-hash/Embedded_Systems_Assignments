#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

// Cấu trúc dữ liệu cho một bệnh nhân
typedef struct {
    char name[50];
    int priority;
} Patient;

// Khai báo mảng heap và biến theo dõi số lượng
Patient heap[MAX_PATIENTS];
int size = 0;

// Hàm hoán đổi 2 phần tử
void swap(Patient *a, Patient *b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm xem bệnh nhân ưu tiên cao nhất (Peek)
Patient peek() {
    return heap[0];
}

// Hàm đẩy phần tử lên trên để duy trì tính chất Max-Heap (Heapify-up)
void heapify_up(int index) {
    int parent = (index - 1) / 2;
    
    // Nếu chưa đến gốc và độ ưu tiên của con lớn hơn cha -> Đổi chỗ
    if (index > 0 && heap[index].priority > heap[parent].priority) {
        swap(&heap[index], &heap[parent]);
        heapify_up(parent); // Gọi đệ quy tiếp lên trên
    }
}

// Hàm thêm bệnh nhân mới vào hàng đợi (Push)
void push(Patient p) {
    if (size >= MAX_PATIENTS) {
        printf("Hang doi da day!\n");
        return;
    }
    heap[size] = p; // Thêm vào cuối mảng
    heapify_up(size); // Đẩy lên vị trí thích hợp
    size++;
    
    // In ra bệnh nhân đứng đầu hàng đợi sau mỗi lần thêm (theo yêu cầu đề)
    printf("-> Da them [%s] (Muc: %d). Dang cho cap cuu: [%s] (Muc: %d)\n", 
           p.name, p.priority, peek().name, peek().priority);
}

// Hàm đẩy phần tử xuống dưới để duy trì tính chất Max-Heap (Heapify-down)
void heapify_down(int index) {
    int max = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // So sánh với nút con trái
    if (left < size && heap[left].priority > heap[max].priority) {
        max = left;
    }
    // So sánh với nút con phải
    if (right < size && heap[right].priority > heap[max].priority) {
        max = right;
    }
    
    // Nếu cha không phải là lớn nhất -> Đổi chỗ với con lớn nhất và tiếp tục
    if (max != index) {
        swap(&heap[index], &heap[max]);
        heapify_down(max);
    }
}

// Hàm lấy bệnh nhân ưu tiên cao nhất ra khỏi hàng đợi (Pop)
Patient pop() {
    Patient highest = heap[0]; // Lưu lại bệnh nhân ưu tiên nhất ở gốc
    
    heap[0] = heap[size - 1]; // Đưa bệnh nhân ở cuối mảng lên gốc
    size--; // Giảm kích thước mảng
    
    heapify_down(0); // Sắp xếp lại cây từ gốc xuống
    
    return highest;
}

int main() {
    printf("--- TIEP NHAN BENH NHAN ---\n");
    // Nhập 5 bệnh nhân với các mức ưu tiên khác nhau
    Patient p1 = {"Benh Nhan A (Gay tay)", 3};
    Patient p2 = {"Benh Nhan B (Dau bung nhe)", 1};
    Patient p3 = {"Benh Nhan C (Nhoi mau co tim)", 5}; // Mức cao nhất
    Patient p4 = {"Benh Nhan D (Sot cao)", 4};
    Patient p5 = {"Benh Nhan E (Dut tay)", 2};

    push(p1);
    push(p2);
    push(p3);
    push(p4);
    push(p5);

    printf("\n--- THU TU GOI KHAM (UU TIEN CAO XUONG THAP) ---\n");
    // Lấy lần lượt từng bệnh nhân ra khỏi hàng đợi
    int order = 1;
    while (size > 0) {
        Patient current = pop();
        printf("Goi kham %d: %s - Muc uu tien: %d\n", order, current.name, current.priority);
        order++;
    }

    return 0;
}
