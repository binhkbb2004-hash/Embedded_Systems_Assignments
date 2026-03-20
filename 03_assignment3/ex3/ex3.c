#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000       // Do dai toi da 1 dong
#define LINES_PER_PAGE 40  // So dong toi da 1 trang

// Ham in noi dung của 1 file kem theo phan trang
void print_file(FILE *fp, char *filename) {
    char line[MAXLINE];
    int line_count = 0;
    int page_number = 1;

    // In tieu de cho trang dau tien cua file
    printf("\n--- File: %s | Page: %d ---\n\n", filename, page_number);

    // Doc tung dong cho toi het file
    while (fgets(line, MAXLINE, fp) != NULL) {
        printf("%s", line); // In dong van ban ra
        line_count++;

        // Khi in du so dong cua 1 trang thi ngat trang
        if (line_count >= LINES_PER_PAGE) {
            page_number++;
            printf("\f"); // Ki tu \f de ra lenh sang trang moi
            printf("\n--- File: %s | Page: %d ---\n\n", filename, page_number);
            line_count = 0; // Reset lai dem dong cho trang moi
        }
    }
    
    // In ki tu sang trang cuoi moi file de sang trang khi sang file moi
    printf("\f"); 
}

int main(int argc, char *argv[]) {
    FILE *fp;

    // Kiem tra nguoi dung co nhap ten file nao khong 
    if (argc == 1) {
        printf("Cach su dung: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    // Duyet qua tat ca cac file duoc truyen vao
    for (int i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            // Neu khong mo duoc file nao thi in ra loi
            fprintf(stderr, "Loi: Khong the mo file %s\n", argv[i]);
            continue; 
        }
        
        // Goi ham in
        print_file(fp, argv[i]);
        fclose(fp);
    }

    return 0;
}
