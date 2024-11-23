#include <iostream>
#include <cmath>
using namespace std;
int main(){
    cout << "Enter a no:" ;
    int n;
    cin >> n;
    cout << "1.Square of no." << endl;
    cout << "2.Cube of no." << endl;
    cout << "3.No of digits" << endl;
    cout << "4.Sqrt" << endl;
    cout << "5.Exit" <<endl;
    cout << "Enter your choice:" ;
    int ch;
    cin >> ch;
    switch(ch){
        case 1:
            cout << pow(n,2) <<endl;
            break;
        case 2:
            cout << pow(n,3) << endl;
            break;
        case 3:
            cout << (int)log10(n)+1 << endl;
            break;
        case 4:
            cout << sqrt(n) <<endl;
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    return 0;
}