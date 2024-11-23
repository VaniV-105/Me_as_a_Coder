#include <iostream>
using namespace std;

int main(){
    int key,size,i;
    cout<<"Enter key:";
    cin>>key;
    cout<<"Enter size of array:";
    cin>>size;
    int arr[100];
    for(i=0;i<size;i++){
        cout<<"Enter element:";
        cin>>arr[i];
        if(arr[i]==key){
            cout<<"Key found at position:"<<i+1<<endl;
            break;
        }
    }
    if(i==size)
        cout<<"Element not found.";


}