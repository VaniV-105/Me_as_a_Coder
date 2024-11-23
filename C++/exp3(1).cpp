#include <iostream>
#include <string>
using namespace std;
class Zone{
    public:
        string ZoneName;
        Zone(string zone){
            ZoneName = zone;
        }
        void displayZone(){
            cout << ZoneName << " Zone";
        }
};
class Station:public Zone{
    public:
        string StationName;
        Station(string zone, string station) : Zone(zone), StationName(station) {}
        void displayStation(){
            cout<< StationName << " is in ";
            displayZone();
        }
};
int main(){
    string station,zone;
    cout<<"Enter Station Name:";
    getline(cin,station);
    cout<<"Enter Zone:";
    cin>>zone;
    Station ap(zone,station);
    ap.displayStation();
    return 0;
}