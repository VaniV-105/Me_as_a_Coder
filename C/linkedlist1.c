#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node Node;
void insertNode(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    Node* temp=head->next;
    if(temp==NULL){
        head->next=newNode;
    }else{
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
    }
}
void PrintList(Node* head){
    Node* temp = head->next;
    while(temp!=NULL){

        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
}
int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->next=NULL;
    insertNode(head,8);
    insertNode(head,9);
    insertNode(head,11);
    insertNode(head,12);
    insertNode(head,14);
    PrintList(head);

    
}