#include <stdio.h>
#include <stdlib.h>

#define N 3

struct Node {
    int data;
    struct Node* children[N];
};

typedef struct Node* Tree;
typedef struct Node* Tnode;

// Function to create a new node
Tnode createNode(char c) {
    Tnode newNode = (Tnode)malloc(sizeof(struct Node));
    newNode->data = c;
    for (int i = 0; i < N; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to print tree structure
void printTree(Tree root) {
    if (root == NULL) return;
    for (int i = 0; i < N; i++) {
        if (root->children[i] != NULL) {
            printf("%c --> %c\n", root->data, root->children[i]->data);
            printTree(root->children[i]);
        }
    }
}

// Pre-order traversal
void preOrder(Tree T) {
    if (T == NULL) return;
    printf("%c ", T->data);
    for (int i = 0; i < N; i++) {
        preOrder(T->children[i]);
    }
}

// In-order traversal (adapted for N-ary tree)
void inOrder(Tree T) {
    if (T == NULL) return;
    int mid = N / 2;
    // Traverse first half of children
    for (int i = 0; i < mid; i++) {
        inOrder(T->children[i]);
    }
    // Visit root
    printf("%c ", T->data);
    // Traverse second half of children
    for (int i = mid; i < N; i++) {
        inOrder(T->children[i]);
    }
}

// Post-order traversal
void postOrder(Tree T) {
    if (T == NULL) return;
    for (int i = 0; i < N; i++) {
        postOrder(T->children[i]);
    }
    printf("%c ", T->data);
}


int main() {
    Tree T;
    Tnode A = createNode('A');
    Tnode B = createNode('B');
    Tnode C = createNode('C');
    Tnode D = createNode('D');
    Tnode E = createNode('E');
    Tnode F = createNode('F');
    Tnode G = createNode('G');
    Tnode H = createNode('H');
    Tnode I = createNode('I');

    // Building the tree
    T = A; //A is the root 
    A->children[0] = B; 
    A->children[1] = C;
    A->children[2] = D;
    B->children[0] = E;
    B->children[1] = F;
    C->children[0] = G;
    D->children[0] = H;
    D->children[1] = I;

    printf("Tree structure:\n");
    printTree(T);

    printf("\nPre-order traversal: ");
    preOrder(T);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(T);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(T);
    printf("\n");

    return 0;
}
