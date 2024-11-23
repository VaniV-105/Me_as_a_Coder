#include <iostream>
#include <string>
using namespace std;
template <typename T,typename U>
class tickets{
    private:
        T train;
        U passenger;
    public:
        void setdata(T x,U y){
            train = x;
            passenger = y;
        }
        T gettraindata(){
            return train;
        }
        U getpassengerdata(){
            return passenger;
        }
};
int main(){
    tickets <int,int> obj1;
    tickets <string,string> obj2;
    obj1.setdata(12634,128);
    obj2.setdata("KK Express","Aashin A P");
    cout<<"Train Name/No:"<<obj1.gettraindata()<<endl;
    cout<<"Passenger Name/ID:"<<obj1.getpassengerdata()<<endl;
    cout<<"Train Name/No:"<<obj2.gettraindata()<<endl;
    cout<<"Passenger Name/ID:"<<obj2.getpassengerdata()<<endl;
    return 0;
}