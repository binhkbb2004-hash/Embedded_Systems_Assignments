#include <stdio.h>

int arr[] = {34, 201, 190, 154, 8, 194, 2, 6};
int len = 8;

/* ====== (a): Cai dat lai ham shift_element bang con tro ====== */
// pElement tro toi phan tu dang bi sai vi tri trong mang arr
void shift_element(int *pElement) {
    int ivalue = *pElement; // Luu lai gia tri cua phan tu dang xet
    int *p = pElement;      // Dung con tro p de chay nguoc ve dau mang

    // p > arr         : Khong lui qua dia chi dau mang
    // *(p - 1) > ivalue : Kiem tra phan tu dung truoc co > gia tri dang xet khong
    while (p > arr && *(p - 1) > ivalue) {
        *p = *(p - 1);      // Dich chuyen phan tu lon hon xuong 1 vi tri
        p--;                // Lui con tro p len phia truoc
    }
    
    *p = ivalue; // Chen gia tri dung vao vi tri xong khi dich xong
}

/* ====== (b): Cai dat lai ham insertion_sort bằng con tro ====== */
void insertion_sort(void) {
    int *p;
    int *end = arr + len; // Con tro tro toi ranh gioi ket thuc mang

    // Bat dau tu phan tu thu 2 (arr + 1), i = 1
    // Chay cho toi khi p cham toi end
    for (p = arr + 1; p < end; p++) {
        // Neu phan tu hien tai (*p) < phan tu ngay truoc no (*(p - 1))
        if (*p < *(p - 1)) {
            shift_element(p); // Goi ham dich chuyen, truyen vao dia chi phan tu loi
        }
    }
}

// Ham in mang
void print_array() {
    int *p;
    int *end = arr + len;
    for (p = arr; p < end; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}
int main() {
    printf("Mang ban dau:          ");
    print_array();

    insertion_sort();

    printf("Mang sau khi sap xep:  ");
    print_array();

    return 0;
}
