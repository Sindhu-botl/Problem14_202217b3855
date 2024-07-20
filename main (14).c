#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    // Constructing the tree
    struct TreeNode* root = createNode('D');
    root->left = createNode('A');
    root->right = createNode('E');
    root->left->left = createNode('G');
    root->left->right = createNode('Q');
    root->right->left = createNode('B');
    root->right->right = createNode('F');
    root->right->left->left = createNode('V');
    root->right->right->left = createNode('T');
    root->right->right->right = createNode('J');
    root->right->right->right->left = createNode('L');
    root->right->right->right->right = createNode('R');

    // Performing different traversals
    printf("Preorder:\n");
    preOrderTraversal(root);
    printf("\n\n");

    printf("Postorder:\n");
    postOrderTraversal(root);
    printf("\n\n");

    printf("Inorder:\n");
    inOrderTraversal(root);
    printf("\n");

    // Free dynamically allocated memory
    // This step is optional in this program but necessary in larger programs
    // to prevent memory leaks
    return 0;
}