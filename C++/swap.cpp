#include <iostream>
using namespace std;
int main(){
    int a=5,b=6;
    cout<<a<<" "<<b<<endl;
    int temp = a;
    a=b;
    b=temp;
    cout<<a<<" "<<b<<endl;
    return 0;
}