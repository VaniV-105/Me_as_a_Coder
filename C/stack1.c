#include <string.h>
#define N 1000
typedef int element;
typedef struct stack{
    element data[N];
    int top;
}stack;
stack CreateStack(){
    stack s;
    s.top=-1;
    return s;
}
int isEmptyStack(stack s){
    return s.top==-1;
}
int isFullStack(stack s){
    return s.top==N-1;
}
int Push(stack *s,element e){
    if(isFullStack(*s)) return 0;
    s->data[++s->top]=e;
    return 1;
}
int Pop(stack* s){
    if(isEmptyStack(*s)) return 0;
    s->top--;
    return 1;
}
int Top(stack s,element* e){
    if(isEmptyStack(s)) return 0;
    *e=s.data[s.top];
    return 1;
}
int main() {
	//code
	int tests;
	int Q,x;
	char place[]="place";
	stack s=CreateStack();
	char str[30];
	scanf("%d",&tests);
	while(tests--){
	    scanf("%d",&Q);
	    while(Q--){
	        scanf("%s",str);
	        if(strcmp(str,place)==0) {
	            scanf("%d ",&x);
	            Push(&s,x);
	        }
	        else {
	            if(Top(s,&x)){
	                printf("%d ",x);
	                Pop(&s);
	            }else{
	                printf("-1 ");
	            }
	        }        
	            
	    } 
	s=CreateStack();
	printf("\n");
	    } 
	return 0;
}
