#include <iostream>
#include <string>
using namespace std;
int main(){
    int a=5,b=12;
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }
    if(a==0){
        cout << b <<endl;
    }
    else{
        cout << a << endl;
    }
    return 0;
}
