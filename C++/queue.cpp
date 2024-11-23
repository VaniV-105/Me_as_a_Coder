#include <iostream>
#include <queue>
using namespace std;
void print(queue<int> q){
	queue<int> temp=q;
	while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    	}
    	cout << '\n';
}
int main(){
	queue<int> queue;
	cout<<"Queue Operations:"<<endl;
	cout<<"1.Push an element.\n2.Pop an element.\n3.Find the front element."<<endl;
	cout<<"4.Find size of queue.\n5.Check whether queue is empty.\n6.Find the last element.\n7.Print the Queue.\n8.Exit"<<endl;
	int flag=1;
	while(flag){
	cout<<"Enter your choice:";
	int choice,n;
	cin>>choice;
	switch(choice){	
		case 1:
			cout<<"Enter element to be pushed:";
			cin>>n;
			queue.push(n);
			break;
		case 2:
			queue.pop();
			cout<<"Element popped."<<endl;
			break;
		case 3:
			cout<<"Front element is "<<queue.front()<<endl;
			break;
		case 4:
			cout<<"Size of queue is "<<queue.size()<<endl;
			break;
		case 5:
			if(queue.empty())
				cout<<"Queue is empty."<<endl;
			else
				cout<<"Queue is not empty."<<endl;
			break;
		case 6:
			cout<<"Last element is "<<queue.back()<<endl;
			break;
		case 7:
			print(queue);
			break;
		default:
			flag=0;
	}
	}
	return 0;
}
			
