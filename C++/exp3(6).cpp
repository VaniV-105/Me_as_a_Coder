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

// Base class representing vehicles in the railway system
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

// Base class representing employees in the railway system
class Employee : public Entity {
public:
    Employee(string employee) : Entity(employee) {}

    void displayEmployee() {
        cout << "Employee: ";
        displayEntity();
    }
};

// Derived class representing maintenance crew, inheriting from both Employee and Vehicle
class MaintenanceCrew : public Employee, public Vehicle {
public:
    MaintenanceCrew(string name, string vehicle)
        : Employee(name), Vehicle(vehicle) {}

    void displayMaintenanceCrew() {
        cout << "Maintenance Crew: ";
        displayEmployee();
        cout << " with ";
        displayVehicle();
    }
};

int main() {
    MaintenanceCrew maintenancePerson("John Doe", "Maintenance Vehicle");

    maintenancePerson.displayMaintenanceCrew();
    cout << endl;

    return 0;
}
