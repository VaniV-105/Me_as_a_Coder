#include <iostream>
using namespace std;
#include <string>
#include<vector>
class train{
    private:
        int train_no;
        string train_name;
        string train_type;
        int no_of_comp;
        int seats_per_comp;
        int total_seats;
    public:
        train(){
            no_of_comp=12;
            seats_per_comp=80;
            train_type="SuperFast";
        }
        train(int n,int s,string t){
            no_of_comp=n;
            seats_per_comp=s;
            train_type=t;
        }
        void getdata(){
            cout<<"Enter Train No:";
            cin>>train_no;
            cout<<"Enter Train Name:";
            cin.ignore();
            getline(cin,train_name);
            total_seats=no_of_comp*seats_per_comp;
        }
        void display(){
            cout<<"Train No:"<<train_no<<endl<<"Train Name:"<<train_name<<endl<<"Train_type:"<<train_type<<endl<<"Seats Available:"<<total_seats<<endl;
        }
        ~train(){
            cout<<"Destructor executed."<<endl;
        }
};
int main(){
    vector<train> tr(5);
    train t[10];
    for(int i=0;i<10;i++){
        t[i].getdata();
        t[i].display();
    }
    return 0;
}