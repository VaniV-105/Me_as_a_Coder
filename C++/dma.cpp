#include <iostream>
#include <string>
using namespace std;

class Train {
public:
    int train_no;
    string train_name;
    string train_type;
    int no_of_comp;
    int seats_per_comp;
    int total_seats;

    void getdata() {
        cout << "Enter Train No:";
        cin >> train_no;
        cout << "Enter Train Name:";
        cin.ignore();
        getline(cin, train_name);
        cout << "Enter Train Type:";
        cin >> train_type;
        cout << "Enter Number of Compartments:";
        cin >> no_of_comp;
        cout << "Enter Seats per Compartment:";
        cin >> seats_per_comp;

        total_seats = no_of_comp * seats_per_comp;
    }

    void display() {
        cout << "Train No: " << train_no << endl
             << "Train Name: " << train_name << endl
             << "Train Type: " << train_type << endl
             << "Total Seats Available: " << total_seats << endl;
    }

    ~Train() {
        cout << "Destructor executed." << endl;
    }
};

int main() {
    int n;

    cout << "Enter the number of trains: ";
    cin >> n;

    Train *trainArray = new Train[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Train " << i + 1 << ":\n";
        trainArray[i].getdata();
    }

    cout << "\nDetails for all trains:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nTrain " << i + 1 << ":\n";
        trainArray[i].display();
    }

    delete[] trainArray;

    return 0;
}
