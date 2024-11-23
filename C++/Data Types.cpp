#include <iostream>
#include <string>
using namespace std;
int main(){
    int a;
    float b;
    long c;
    double d;
    char e;
    bool f;
    string str;
    cout << "Enter Integer value:" ;
    cin >> a;
    cout << "Enter Float value:";
    cin >> b;
    cout << "Enter Long Value:";
    cin >> c;
    cout << "Enter Double value:";
    cin >> d;
    cout << "Enter character:";
    cin >> e;
    f = true;
    cout << "Enter String value:";
    cin.ignore();
    getline(cin,str);
    cout << endl;
    cout << "The entered values are:" <<endl;
    cout << "Integer:" << a <<"\nFloat:" << b << "\nLong:" << c <<endl;
    cout << "Double:" << d << "\nChar:" << e << "\nBool:" << f <<"\nString:" << str<<endl;
    return 0;
}
