#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
int top(Node* head){
    return head->next->data;
}
int isEmpty(Node* head){
    return head->next == NULL;
}
void push(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = head->next;
    newNode->next = temp;
    head->next = newNode;
}
void Display(Node* head){
    Node* temp = head->next;
    while(temp!=NULL){
        printf("%d-->",temp->data);
        temp = temp ->next;
        
    }    
    printf("NULL\n");
}
int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head ->next = NULL;
    printf("Enter the no of elements:");
    int n;
    scanf("%d",&n);
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        push(head,data);
    }
    //printf("The elements are:\n");
    //Display(head);
    //printf("\nTop element is %d",top(head));
    printf("%d",isEmpty(head));
}