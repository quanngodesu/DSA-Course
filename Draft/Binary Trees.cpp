#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* BTree;
typedef struct Node* BTnode;

BTnode makeNodeBT(char c) {
    BTnode node = (BTnode)malloc(sizeof(struct Node));
    node->data = c;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrderBT(BTree T) {
    if (T == NULL) return;
    printf("%c ", T->data);
    preOrderBT(T->left);
    preOrderBT(T->right);
}

void inOrderBT(BTree T) {
    if (T == NULL) return;
    inOrderBT(T->left);
    printf("%c ", T->data);
    inOrderBT(T->right);
}

void postOrderBT(BTree T) {
    if (T == NULL) return;
    postOrderBT(T->left);
    postOrderBT(T->right);
    printf("%c ", T->data);
}

void printBTree(BTree root) {
    if (root == NULL) return;
    printf("%c --> ", root->data);
    if (root->left) {
        printf("%c ", root->left->data);
    } else {
        printf("NULL ");
    }
    if (root->right) {
        printf("%c\n", root->right->data);
    } else {
        printf("NULL\n");
    }
    printBTree(root->left);
    printBTree(root->right);
}

void freeTree(BTree root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    BTree root = makeNodeBT('A');
    BTnode B = makeNodeBT('B');
    BTnode C = makeNodeBT('C');
    BTnode D = makeNodeBT('D');
    BTnode E = makeNodeBT('E');
    BTnode F = makeNodeBT('F');
    BTnode G = makeNodeBT('G');
    //A-B, A-C
    root->left = B;
    root->right = C;
    //B-D, B-E
    B->left = D;
    B->right = E;
    //C-F, C-G
    C->left = F;
    C->right = G;

    printf("Pre-order Traversal: ");
    preOrderBT(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrderBT(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderBT(root);
    printf("\n");

    printf("Tree Structure:\n");
    printBTree(root);

    freeTree(root);
    return 0;
}
