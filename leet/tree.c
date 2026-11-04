/* Mon Oct 26 03:54:28 PM CDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
    struct Node *parent;
} Node;

Node *insert(Node *root, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data, node->left = node->right = node->parent = 0;
    Node *prev = 0, *next = root;
    while (next != 0) {
        prev = next;
        if (data < next->data) prev = next, next = next->left;
        else next = next->right;
    }
    if (prev == 0) return node;
    if (data < prev->data) prev->left = node;
    else prev->right = node;
    node->parent = prev;
    return root;
}

void inordertraversal(Node *root) {
    if (root != 0) {
        inordertraversal(root->left);
        printf("%d\n", root->data);
        inordertraversal(root->right);
    }
}

int main(int argc, char *argv[])
{
    Node *root = (Node*) malloc(sizeof(Node));
    root->parent = 0;
    root->data = 0;
    for (int i = -10; i < 0; i++) root = insert(root,i);
    for (int i = 1; i <= 10; i++) root = insert(root,i);
    inordertraversal(root);
}
