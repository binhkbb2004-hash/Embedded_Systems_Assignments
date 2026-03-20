#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000 // Do dai toi da 1 dong

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char line1[MAXLINE], line2[MAXLINE];
    char *ptr1, *ptr2;
    int line_num = 1; // Bien dem so thu tu dong

    // B1: Kiem tra nguoi dung da nhap ten 2 file chua 
    if (argc != 3) {
        printf("Cach su dung: %s <file_1> <file_2>\n", argv[0]);
        return 1;
    }

    // B2: Mo file 1, dung ham fopen de mo file o che do doc "r"
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("Loi: Khong the mo file %s\n", argv[1]);
        return 1;
    }

    // B3: Mo file thu 2
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        printf("Loi: Khong the mo file %s\n", argv[2]);
        fclose(fp1); // Dong file 1 da mo truoc do
        return 1;
    }

    // B4: Doc va so sanh tung dong
    while (1) {
        // Doc 1 dong tu ca 2 file dung ham fgets
        ptr1 = fgets(line1, MAXLINE, fp1);
        ptr2 = fgets(line2, MAXLINE, fp2);

        // TH1: Ca 2 file deu doc toi dong cuoi va bao EOF (NULL)
        if (ptr1 == NULL && ptr2 == NULL) {
            printf("Hai file giong nhau hoan toan!\n");
            break;
        } 
        // TH2: File 1 het truoc file 2
        else if (ptr1 == NULL) {
            printf("Khac biet phat hien o dong %d:\n", line_num);
            printf(" - %s da ket thuc.\n", argv[1]);
            printf(" - %s van con noi dung: %s", argv[2], line2);
            break;
        } 
        // TH3: File 2 het truoc file 1
        else if (ptr2 == NULL) {
            printf("Khac biet phat hien o dong %d:\n", line_num);
            printf(" - %s van con noi dung: %s", argv[1], line1);
            printf(" - %s da ket thuc.\n", argv[2]);
            break;
        }
        // TH4: Ca 2 file deu co noi dung, tien hanh so sanh su dung ham strcmp
        if (strcmp(line1, line2) != 0) {
            printf("Khac biet phat hien o dong %d:\n", line_num);
            printf(" - %s: %s", argv[1], line1);
            printf(" - %s: %s", argv[2], line2);
            break;
        }
        line_num++; // Tang bien dem dong len 1
    }
    // B5: Dong file
    fclose(fp1);
    fclose(fp2);
    return 0;
}
