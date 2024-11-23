#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
class ticket{
    public:
        void bookticket(int PID,string pname,string type){
            cout<<"Ticket Booked.\nPassenger Name: "<<pname<<"\nPassenger ID: "<<PID<<"\nCompartment:"<<type<<rand()%10<<endl;
        }
        void bookticket(int PID,string pname){
            cout<<"Ticket Booked.\nPassenger Name: "<<pname<<"\nPassenger ID: "<<PID<<endl;
        }
        void berth(){
            cout<<"A berth has been allotted to you."<<endl;
        }
        void berth(int age){
            if(age>50){
                cout<<"Senior Citizen\nLower Berth has been allotted"<<endl;
            }
            else if(age>30){
                cout<<"Middle Berth"<<endl;
            }
            else{
                cout<<"Upper Berth"<<endl;
            }
        }
};
int main(){
    ticket t1;
    int age,ch;
    string name,type;
    int PID=128;
    cout<<"Enter Passenger Name:";
    getline(cin,name);
    cout<<"Enter Passenger Age:";
    cin>>age;
    cout<<"Select your seat type:\n 1.First Class AC\n 2.Second Class AC\n 3.Third Class AC\n 4.Sleeper\n 5.Chair Car \n 6.Unreserved\nEnter your choice:";
    cin>>ch;
    switch (ch)
    {
    case 1:
        type = "HA";
        break;
    case 2:
        type = "A";
        break;
    case 3:
        type = "B";
        break;
    case 4:
        type = "SL";
        break;
    case 5:
        type = "D";
        break;

    default:
        break;
    }
    if(type.empty())
        t1.bookticket(PID,name);
    else
        t1.bookticket(PID,name,type);
    if(ch<=4){
        t1.berth(age);
        t1.berth();
    }
    return 0;
}