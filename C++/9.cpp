#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter n:";
    cin >> n;
    for(int a=1;a<=n;a++){
        for(int i=1;i<=n-a;i++){
            cout << "  " ;
        }
        for(int i=1;i<=2*a-1;i++){
            cout << "* ";
        }
        cout << endl;
    }
    for(int a=n;a>=1;a--){
        for(int i=1;i<=n-a;i++){
            cout << "  " ;
        }
        for(int i=1;i<=2*a-1;i++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}