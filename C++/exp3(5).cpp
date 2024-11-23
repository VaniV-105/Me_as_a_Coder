#include <iostream>
#include <string>
using namespace std;

// Base class representing entities in the railway system
class Entity {
public:
    string EntityName;

    Entity(string entity) : EntityName(entity) {}

    void displayEntity() {
        cout << EntityName << " Entity";
    }
};

// Intermediate class 1 inheriting from Entity, representing a Train entity
class Trains : virtual public Entity {
public:
    Trains(string name) : Entity(name + " Train") {}

    void displayTrain() {
        cout << "Train: ";
        displayEntity();
    }
};

// Intermediate class 2 inheriting from Entity, representing a Station entity
class Stationss : virtual public Entity {
public:
    Stationss(string name) : Entity(name + " Station") {}

    void displayStation() {
        cout << "Station: ";
        displayEntity();
    }
};

// Derived class inheriting from both Train and Station
class Ticket : public Trains, public Stationss {
public:
    Ticket(string name)
        : Entity(name + " Ticket"),
          Trains(name),
          Stationss(name) {}

    void displayTicket() {
        cout << "Ticket: ";
        displayEntity();
    }
};

int main() {
    Ticket ticket("ABC123");

    ticket.displayTicket();
    cout << endl;
    ticket.displayTrain();
    cout << endl;
    ticket.displayStation();
    cout << endl;

    return 0;
}
