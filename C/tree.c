#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node Node;
Node* create(){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    int data,opt;
    printf("Press 0 to exit or 1 to insert new node:");
    scanf("%d",&opt);
    if(opt==0)
        return 0;
    else{
        printf("Enter new node:");
        scanf("%d",&data);
        temp->data=data;
        printf("Enter left child of %d\n",data);
        temp->left = create();
        printf("Enter right child of %d\n",data);
        temp->right = create();
        return temp;
    }
}
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inorder(Node* root){
    if (root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postOrder(Node* root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
void main(){
    struct node *root;
    root = create();
    preOrder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postOrder(root);
}