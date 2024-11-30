#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Search for a value in the BST
TreeNode* search(TreeNode* node, int target) {
    if (node == NULL || node->data == target) {
        return node;
    }
    if (target < node->data) {
        return search(node->left, target);
    } else {
        return search(node->right, target);
    }
}

// Insert a value into the BST
TreeNode* insert(TreeNode* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Print the BST in-order
void printTree(TreeNode* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Find the node with the minimum value
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete a value from the BST
TreeNode* deleteFromBST(TreeNode* node, int data) {
    if (node == NULL) {
        return NULL;
    }
    if (data < node->data) {
        node->left = deleteFromBST(node->left, data);
    } else if (data > node->data) {
        node->right = deleteFromBST(node->right, data);
    } else {
        // Node with only one child or no child
        if (node->left == NULL) {
            TreeNode* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            TreeNode* temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children: Get the inorder successor
        TreeNode* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteFromBST(node->right, temp->data);
    }
    return node;
}

// Free the entire BST recursively
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode* root = createNode(13);
    root->left = createNode(7);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(8);
    root->right->left = createNode(14);
    root->right->right = createNode(19);
    root->right->right->left = createNode(18);

    int choice;
    while (1) {
        printf("\nList of choices:\n");
        printf("1. Print the tree in-order.\n");
        printf("2. Search for a value.\n");
        printf("3. Insert a value and print.\n");
        printf("4. Delete a value and print.\n");
        printf("5. Exit\n");
        printf("Input your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-order traversal of the tree: ");
                printTree(root);
                printf("\n");
                break;

            case 2: {
                int num;
                printf("Input the number you want to find: ");
                scanf("%d", &num);
                TreeNode* result = search(root, num);
                if (result) {
                    printf("Found the node with value: %d\n", result->data);
                } else {
                    printf("Value not found in the BST.\n");
                }
                break;
            }

            case 3: {
                int inserted_num;
                printf("Input a number you want to insert: ");
                scanf("%d", &inserted_num);
                root = insert(root, inserted_num);
                printf("In-order traversal after inserting %d: ", inserted_num);
                printTree(root);
                printf("\n");
                break;
            }

            case 4: {
                int deleted_num;
                printf("Input number you want to delete: ");
                scanf("%d", &deleted_num);
                root = deleteFromBST(root, deleted_num);
                printf("In-order traversal after deleting %d: ", deleted_num);
                printTree(root);
                printf("\n");
                break;
            }

            case 5:
                freeTree(root);
                printf("Exiting program. Memory cleaned up.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
