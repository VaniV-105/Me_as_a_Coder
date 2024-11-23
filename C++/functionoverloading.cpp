#include <iostream>
using namespace std;
#include <string>
void add(int a,int b){
    cout<<"Sum="<<a+b<<endl;
}
void add(double a,double b){
    cout<<"Sum="<<a+b<<endl;
}
void add(string a,string b){
    cout<<"Concatenated string="<<a+b<<endl;
}
int main(){
    add(4,5);
    add(5.4,6.3);
    add("Aashin"," A P");
    return 0;
}