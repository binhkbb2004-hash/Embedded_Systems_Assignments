#include <stdio.h>
#include <string.h> 
#include <ctype.h>  //Thu vien cung cap 2 ham tolower va toupper

int main(int argc, char *argv[]) {
    int c;
    int to_lower = 0; // Co de nho trang thai: 1: in thuong, 0: in hoa

    // Kiem tra ten chuong trinh trong argv[0]
    // Ham strstr se tim lower hoac upper co nam trong chuoi argv[0] khong
    if (strstr(argv[0], "lower") != NULL) {
        to_lower = 1;
    } else if (strstr(argv[0], "upper") != NULL) {
        to_lower = 0;
    } else {
        printf("Loi: Vui long doi ten file chay thanh 'lower' hoac 'upper'\n");
        return 1;
    }

    // Doc tung ki tu cho toi khi gap EOF
    while ((c = getchar()) != EOF) {
        if (to_lower == 1) {
            putchar(tolower(c)); // Bien thanh chu thuong roi in ra
        } else {
            putchar(toupper(c)); // Bien thanh chu hoa roi in ra 
        }
    }

    return 0;
}
