#include <iostream>
using namespace std;
#include <string>
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
class station{
    private:
        string code;
        string zone;
        string name;
    public:
        station(){
            zone="Southern Railway";
        }
        station(string z){
            zone=z;
        }
        station(string c,string z){
            zone=z;
            code=c;
        }
        void getstation(){
            cout<<"Enter Station Code:";
            cin>>code;
            cout<<"Enter Station Name:";
            cin.ignore();
            getline(cin,name);
        }
        string display(){
            return code+" "+name;
        }
        ~station(){
            cout<<"The Station has been destroyed."<<endl;
        }
};
int main(){
        train t1;
        t1.getdata();
        t1.display();
        cout<<"Starting Station:"<<endl;
        station s1;
        s1.getstation();
        string station1 = s1.display();
        cout<<"Ending Station:"<<endl;
        station s2;
        s2.getstation();
        string station2 = s2.display();
        cout<<"Your train starts from "<<station1<<" and ends at "<<station2<<endl;
        train t2(18,72,"Antyodaya");
        t2.getdata();
        t2.display();
        train t3(t1);
        t3.display();
        return 0;
}