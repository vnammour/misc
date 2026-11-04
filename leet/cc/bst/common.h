/* Wed Nov  4 01:46:33 PM IST 2026 */
/* By: vnammour */
#ifndef _common_h
#define _common_h
typedef enum {none = 0, underflow = 1, overflow = 2} errcode;
// errcode err = none;
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    struct TreeNode *parent;
} TreeNode;
typedef TreeNode* Type;
typedef struct Node {
    Type data;
    struct Node *next;
} Node;
typedef struct Queue {
    Node *head;
} Queue;

void enqueue(Queue *q, Type data);
Type dequeue(Queue *q);
bool isempty(Queue *q);
#endif
