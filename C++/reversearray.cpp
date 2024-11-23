#include <iostream>
#include <algorithm>
using namespace std;
void reverse(int arr[],int start,int end){
    if(start<end){
        swap(arr[start],arr[end]);
        reverse(arr,start+1,end-1);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
}
int main(){
    int arr[] = {1,2,3,4,5};
    cout << "Array before reversing:";
    printArray(arr,5);
    cout<< "Array after reversing: ";
    reverse(arr,0,4);
    printArray(arr,5);
    return 0;

}