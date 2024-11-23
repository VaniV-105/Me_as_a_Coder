#include <iostream>
using namespace std;
int main(){
    cout << "Enter a no:" ;
    int n;
    cin >> n;
    if(n>0)
        cout << n << " is a positive number." << endl;
    else    
        cout << n << " is a negative number." << endl;
    return 0;
}