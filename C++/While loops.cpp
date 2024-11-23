#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cout << "Enter a no :" ;
    cin >> n;
    int num = n;
    while (num>0)
    {
        int d = num%10;
        sum = sum*10+d;
        num = num/10;
    }
    if(sum==n){
        cout << "Palindrome No" << endl;
    }
    else    
        cout <<"Not Palindrome" <<endl;
    return 0;   
}