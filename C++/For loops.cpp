#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cout << "Enter no of rows to print: " << endl;
    cin >> n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            cout << "*" ;
        }
        cout << endl;
    }
    return 0;
}