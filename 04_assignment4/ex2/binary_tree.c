#include <stdio.h>
#include <stdlib.h>
// 1. Dinh nghia cau truc Node cua cay nhi phan
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
//------------------------1. Ham cap phat bo nho cho 1 Node moi
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
//------------------------2. Ham Insert vao cay nhi phan tim kiem (BST)
struct TreeNode* insert(struct TreeNode* root, int value) {
    // Neu cay rong, Node moi chinh la goc (root)
    if (root == NULL) {
        return createNode(value);
    }
    // Neu gia tri nho hon goc, re sang nhanh trai
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    // Neu gia tri lon hon goc, re sang nhanh phai
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Tra ve con tro goc khong doi
    return root;
}
// -----------------------3. Ham Duyet cay - Theo thu tu Trai -> Goc -> Phai
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);       // Duyet nhanh trai
        printf("%d -> ", root->data);       // In gia tri Node hien tai
        inorderTraversal(root->right);      // Duyet nhanh phai
    }
}
// -----------------------4. Ham Free Memory
// Xoa con truoc roi moi xoa cha
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);   // Giai phong toan bo nhanh trai
        freeTree(root->right);  // Giai phong toan bo nhanh phai
        free(root);             // Giai phong chinh no
    }
}
int main() {
    struct TreeNode* root = NULL;
    printf("--- BAT DAU TEST BINARY TREE ---\n");
    // Them cac phan tu vao cay
    // Cay se co cau truc
    //        50
    //      |    |
    //    30      70
    //   |  |    |  |
    //  20  40  60   80
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Da them cac phan tu vao cay.\n");
    // In ra man hinh
    printf("Duyet cay theo thu tu In-order (Tang dan):\n");
    inorderTraversal(root);
    printf("NULL\n");
    // Free memory
    freeTree(root);
    printf("Da giai phong toan bo bo nho cua cay nhi phan.\n");
    return 0;
}
