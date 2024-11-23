#include <iostream>
using namespace std;
#include <string>
int main(){
    string name;
    cout<<"Enter your name:";
    getline(cin,name);
    cout<<"Welcome to C++ Programming, @"<<name<<endl;
    return 0;
}