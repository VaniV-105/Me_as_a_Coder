#include <stdio.h>
#include <stdlib.h>
struct node{
    char data;
    struct node* l;
    struct node* r;
    struct node* next;
};
struct node* head= NULL;
typedef struct node Node;
Node* newNode(char data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->l=NULL;
    node->r=NULL;
    return node;
}
void inorder(Node* node){
    if (node==NULL)
        return;
    inorder(node->l);
    printf("%c ",node->data);
    inorder(node->r);
}
void push()