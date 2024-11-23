#include <iostream>
#include <string>
using namespace std;

class train {
private:
    int train_no;
    string train_name;
    string train_type;
    int no_of_comp;
    int seats_per_comp;
    int total_seats;

public:
    // Default constructor
    train() {
        no_of_comp = 12;
        seats_per_comp = 80;
        train_type = "SuperFast";
    }

    // Parameterized constructor
    train(int n, int s, string t) {
        no_of_comp = n;
        seats_per_comp = s;
        train_type = t;
    }

    // Copy constructor
    train(const train &other) {
        train_no = other.train_no;
        train_name = other.train_name;
        train_type = other.train_type;
        no_of_comp = other.no_of_comp;
        seats_per_comp = other.seats_per_comp;
        total_seats = other.total_seats;
    }

    // Member function to get data
    void getdata() {
        cout << "Enter Train No:";
        cin >> train_no;
        cout << "Enter Train Name:";
        cin.ignore();
        getline(cin, train_name);
        total_seats = no_of_comp * seats_per_comp;
    }

    // Member function to display data
    void display() {
        cout << "Train No:" << train_no << endl
             << "Train Name:" << train_name << endl
             << "Train_type:" << train_type << endl
             << "Seats Available:" << total_seats << endl;
    }

    // Destructor
    ~train() {
        cout << "Destructor executed." << endl;
    }
};

int main() {
    // Using the default constructor
    train t1;
    t1.getdata();
    t1.display();

    // Using the copy constructor
    train t3 = t1;
    cout << "Copied Train Data:" << endl;
    t3.display();

    // Using the parameterized constructor
    train t2(18, 72, "Antyodaya");
    t2.getdata();
    t2.display();

    return 0;
}
