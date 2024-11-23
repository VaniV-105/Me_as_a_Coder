#include <iostream>
#include <string>
using namespace std;
class Zone {
public:
    string ZoneName;

    Zone(string zone) : ZoneName(zone) {}

    void displayZone() {
        cout << ZoneName << " Zone";
    }
};
class Station {
public:
    string StationName;

    Station(string station) : StationName(station) {}

    void displayStation() {
        cout << StationName << " Station";
    }
};
class ZonalRegion : public Zone, public Station {
public:
    ZonalRegion(string zone, string station)
        : Zone(zone), Station(station) {}

    void displaySystem() {
        cout << "Railway Zone at ";
        displayZone();
        cout << " with headquarters at ";
        displayStation();
    }
};

int main() {
    ZonalRegion myRailway("Southern", "MGR Chennai Central");
    myRailway.displaySystem();

    return 0;
}