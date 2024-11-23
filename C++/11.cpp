#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter n:";
    cin >> n;
    int start = 1;
    for(int i=1;i<=n;i++){
        start = (i%2==0)? 0:1;
        for(int j=1;j<=i;j++){
            cout << start ;
            start = 1- start;
        }
        cout << endl;
    }
    return 0;
}