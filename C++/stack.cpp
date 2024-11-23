#include <iostream>
#include <stack>
using namespace std;
int main(){
	stack<int> stack;
	cout<<"Stack Operations:"<<endl;
	cout<<"1.Push an element.\n2.Pop an element.\n3.Find the top most element."<<endl;
	cout<<"4.Find size of stack.\n5.Check whether stack is empty.\n6.Exit."<<endl;
	int flag=1;
	while(flag){
	cout<<"Enter your choice:";
	int choice,n;
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"Enter element to be pushed:";
			cin>>n;
			stack.push(n);
			break;	
		case 2:
			stack.pop();
			cout<<"Element popped."<<endl;
			break;
		case 3:
			cout<<"Top element is "<<stack.top()<<endl;
			break;
		case 4:
			cout<<"Size of stack is "<<stack.size()<<endl;
			break;
		case 5:
			if(stack.empty())
				cout<<"Stack is empty."<<endl;
			else
				cout<<"Stack is not empty."<<endl;
			break;
		default:
			flag=0;
	}
	}
	return 0;
}
		
			
