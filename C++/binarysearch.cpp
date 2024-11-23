#include <iostream>
using namespace std;
int main(){
    int key,size,mid,l,u,i,pos=0;
    cout<<"Enter key:";
    cin>>key;
    cout<<"Enter size:";
    cin>>size;
    int arr[100];
    l=0;u=size-1;
    for(i=0;i<size;i++){
        cout<<"Enter element:";
        cin>>arr[i];
    }
    while(l<=u){
        mid = l+(u-l)/2;
        if(arr[mid]==key){
            cout<<"Element found at pos:"<<mid+1;
            pos=1;
            break;
        }
        else if (arr[mid]>key)      
        {
            u=mid-1;
        }
        else    
            l=mid+1;
        
    }
    if(pos==0)
        cout<<"Element not found";
    return 0;
}