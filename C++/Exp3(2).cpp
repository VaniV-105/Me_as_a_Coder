#include <iostream>
using namespace std;
#include <string>
class Zone{
    public:
        string ZoneName;
        Zone(string zone){
            ZoneName=zone;
        }
        void displayzone(){
            cout<<ZoneName<<" Zone.";
        }
};
class Station:public Zone{
    public:
        string StationName;
        Station(string zone,string station):Zone(zone),StationName(station){}
        void displaystation(){
            cout<<StationName<<" is in ";
            displayzone();
        }
};
class Platform:public Station{
    public:
        int platform;
        Platform(string zone,string station,int pno):Station(zone,station),platform(pno){}
        void display(){
            cout<<"Platform "<<platform<<" at ";
            displaystation();
        }
};
int main(){
    string station,zone;
    int pf;
    cout<<"Enter Station Name:";
    getline(cin,station);
    cout<<"Enter Platform No:";
    cin>>pf;
    cout<<"Enter Zone:";
    cin>>zone;
    Platform pf1(zone,station,pf);
    pf1.display();
    return 0;
}