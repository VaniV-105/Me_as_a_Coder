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

// Derived class representing a vehicle in the railway system
class Vehicle : public Entity {
public:
    Vehicle(string vehicle) : Entity(vehicle) {}

    void displayVehicle() {
        cout << "Vehicle: ";
        displayEntity();
    }
};

// Derived class representing a railway station
class Stations : public Entity {
public:
    Stations(string station) : Entity(station) {}

    void displayStation() {
        cout << "Station: ";
        displayEntity();
    }
};

// Derived class representing an employee in the railway system
class Employee : public Entity {
public:
    Employee(string employee) : Entity(employee) {}

    void displayEmployee() {
        cout << "Employee: ";
        displayEntity();
    }
};

int main() {
    Vehicle myVehicle("Express Train");
    Stations myStation("Grand Central Station");
    Employee myEmployee("John Doe");

    myVehicle.displayVehicle();
    cout << endl;
    myStation.displayStation();
    cout << endl;
    myEmployee.displayEmployee();
    cout << endl;

    return 0;
}
