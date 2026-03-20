#include <stdio.h>
#include <stdlib.h>
// 1. Dinh nghia cau truc Node
struct Node {
    int data;
    struct Node* next;
};
//------------------------------ 2. Ham Insert: Them 1 Node moi vao dau danh sach
void insert(struct Node** head_ref, int new_data) {
    // Cap phat bo nho cho Node moi
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Gan du lieu va tro next cua Node moi toi Node dau tien hien tai
    new_node->data = new_data;
    new_node->next = (*head_ref);
    
    // Cap nhat lai con tro head de tro toi Node moi
    (*head_ref) = new_node;
    printf("Da them: %d\n", new_data);
}
//------------------------------ 3. Ham Search
int search(struct Node* head, int key) {
    struct Node* current = head; // Bat dau tu Node dau tien
    while (current != NULL) {
        if (current->data == key)
            return 1; // Tim thay
        current = current->next; // Nhay sang Node tiep theo
    }
    return 0; // Khong tim thay
}
//------------------------------ 4. Ham Delete: Xoa 1 Node chua gia tri cu the
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    // Neu Node can xoa nam ngay dau danh sach
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Chuyen head sang Node thu 2
        free(temp);             // Giai phong Node cu
        printf("Da xoa: %d\n", key);
        return;
    }

    // Tim Node can xoa và giu lai Node dung ngay truoc no (prev)
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Neu duyet he ma khong tim thay
    if (temp == NULL) {
        printf("Khong tim thay %d de xoa.\n", key);
        return;
    }

    // Bo qua Node can xoa bang cach noi Node truoc voi Node sau
    prev->next = temp->next;
    free(temp); // Giai phong bo nho
    printf("Da xoa: %d\n", key);
}

// Ham in danh sach
void printList(struct Node* node) {
    printf("Danh sach hien tai: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// 5. Ham Free Memory
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next_node;

    while (current != NULL) {
        next_node = current->next; // Luu lai dia chi Node tiep theo
        free(current);             // Giai phong Node hien tai
        current = next_node;       // Tien len Node tiep theo
    }
    *head_ref = NULL;
    printf("Da giai phong toan bo bo nho cua danh sach.\n");
}
int main() {
    // Khoi tao danh sach rong
    struct Node* head = NULL;
    printf("--- BAT DAU TEST LINKED LIST ---\n");
    // Test Insert
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    printList(head);
    // Test Search
    int target = 20;
    if (search(head, target)) {
        printf("Tim thay %d trong danh sach.\n", target);
    } else {
        printf("Khong tim thay %d.\n", target);
    }
    // Test Delete
    deleteNode(&head, 20);
    printList(head);
    // Test Free Memory
    freeList(&head);
    printList(head);
    return 0;
}
