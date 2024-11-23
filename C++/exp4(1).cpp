#include <iostream>
#include <string>
using namespace std;
template <typename T,typename U>
void TicketDetails(T a,U b){
    cout<<"Your train details:"<<endl;
    cout<<"Train Name/No:"<<a<<endl;
    cout<<"Passenger Details:"<<endl;
    cout<<"Passenger Name/ID:"<<b<<endl;
}
int main(){
    int tno,pid;
    string t_name,p_name;
    cout<<"Enter Train No:";
    cin>>tno;
    cin.ignore();
    cout<<"Enter Train Name:";
    getline(cin,t_name);
    cout<<"Enter Passenger ID:";
    cin>>pid;
    cin.ignore();
    cout<<"Enter Passenger Name:";
    getline(cin,p_name);
    cout<<"What do you want to display?"<<endl;
    cout<<"1.Train No and Passenger ID"<<endl;
    cout<<"2.Train Name and Passenger Name"<<endl;
    cout<<"Enter your choice:";
    int choice;
    cin>>choice;
    if(choice==1){
        TicketDetails(tno,pid);
    }
    else{
        TicketDetails(t_name,p_name);
    }
    return 0;
}