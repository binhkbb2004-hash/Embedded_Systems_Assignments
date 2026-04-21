#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXVAL 100 // Kích thước tối đa của ngăn xếp

int sp = 0; // Stack pointer
double val[MAXVAL]; // Mảng chứa các giá trị của ngăn xếp

// Hàm đẩy một số vào ngăn xếp
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("Loi: Ngan xep da day, khong the them %g\n", f);
    }
}

// Hàm rút một số từ đnh ngăn xếp ra
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("Loi: Ngan xep rong!\n");
        return 0.0;
    }
}

int main(int argc, char *argv[]) {
    double op2;

    // Duyệt qua từng đối số dòng lệnh
    for (int i = 1; i < argc; i++) {
        // Nếu đối số bắt đầu bằng số hoặc bắt đầu bằng dấu -
        if (isdigit(argv[i][0]) || (argv[i][0] == '-' && isdigit(argv[i][1]))) {
            push(atof(argv[i])); // Chuyển chuỗi thành số thập phân và đẩy vào Stack
        } 
        // Nếu là toán tử (độ dài chuỗi = 1)
        else if (strlen(argv[i]) == 1) {
            switch (argv[i][0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop(); // Phải rút số thứ 2 ra trước để trừ đúng thứ tự
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0) {
                        push(pop() / op2);
                    } else {
                        printf("Loi: Khong the chia cho 0\n");
                        return 1;
                    }
                    break;
                default:
                    printf("Loi: Khong nhan dien duoc lenh '%s'\n", argv[i]);
                    return 1;
            }
        } else {
            printf("Loi: Doi so khong hop le '%s'\n", argv[i]);
            return 1;
        }
    }

    // In kết quả cuối cùng (số duy nhất còn lại trong Stack)
    if (sp == 1) {
        printf("Ket qua: %g\n", pop());
    } else {
        printf("ERROR roi\n");
    }

    return 0;
}
