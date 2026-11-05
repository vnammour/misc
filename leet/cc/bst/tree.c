/* Mon Oct 26 03:54:28 PM CDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

TreeNode *insert(TreeNode *root, int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data, node->left = node->right = node->parent = 0;
    TreeNode *prev = 0, *next = root;
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

void inordertraversal(TreeNode *root) {
    if (root != 0) {
        inordertraversal(root->left);
        printf("%d\n", root->data);
        inordertraversal(root->right);
    }
}
extern errcode err;
// Breadth-first traversal (BFS)
void levelordertraversal(TreeNode *root) {
    if (root == 0) return;
    Queue *q = (Queue*)malloc(sizeof(Queue));
    enqueue(q,root);
    while (!isempty(q)) {
        Type tnode = dequeue(q);
        if (err != none) break;
        if (tnode->left != 0) enqueue(q,tnode->left);
        if (tnode->right != 0) enqueue(q,tnode->right);
        printf("%d\n", tnode->data);
    }
}

// recursive search
TreeNode *search(TreeNode *root, int data) {
    if (root == 0 || root->data == data) return root;
    if (data < root->data) return search(root->left,data);
    else return search(root->right,data);
}

// iterative search
TreeNode *isearch(TreeNode *root, int data) {
    while (root != 0 && root->data != data) {
        if (data < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

int main(int argc, char *argv[])
{
    TreeNode *root = 0;//(TreeNode*) malloc(sizeof(TreeNode));
    root = insert(root,8);
    root = insert(root,3);
    root = insert(root,10);
    root = insert(root,1);
    root = insert(root,6);
    root = insert(root,14);
    root = insert(root,7);
    root = insert(root,4);
    root = insert(root,13);
    // inordertraversal(root);
    levelordertraversal(root);
    inordertraversal(root);
}
