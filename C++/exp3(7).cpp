#include <iostream>
#include <string>
using namespace std;
class VTrain{
public:
	virtual void displayInfo() = 0; //Pure Virtual Function
};
class ExpressTrain:public VTrain{
private:
	string t_name,source,destination,pname;
	int t_no,pnr;
public:
	ExpressTrain(string a,int b,string start,string end,string name,int pid) :
 		t_name(a),t_no(b),source(start),destination(end),pname(name),pnr(pid) {}
	void displayInfo(){
		cout<<"Train No:"<<t_no<<endl;
		cout<<"Train Name:"<<t_name<<endl;
		cout<<"Your journey starts from "<<source<<" and commences at "<<destination<<endl;
		cout<<"PNR:"<<pnr<<endl;
		cout<<"Passenger Name:"<<pname<<endl;
	}
};
class PassengerTrain:public VTrain{
private:
	int distance;
	float fare;
	string source,destination;
public:
	PassengerTrain(string start,string end,int dist):
		source(start),destination(end),distance(dist) {}
	void setfare(){
		if(distance<=10){
			fare=5.0;}
		else if(distance<=30){
			fare=10.0;}
		else{
			fare=0.66*distance;
}
	}
	void displayInfo(){
		cout<<"You are travelling from "<<source<<" to "<<destination<<endl;
		cout<<"Distance travelled: "<<distance<<endl;
		cout<<"Ticket Fare(in Rupees):"<<fare<<endl;
	}
};
class CargoTrain:public VTrain{
private:
	string product,source,destination,info;
	int capacity,load;
public:
	CargoTrain(string start,string end,int cap,int rn,string prod):
		product(prod),source(start),destination(end),capacity(cap),load(rn) {
if(load>capacity)
		info="Overload. Exceeded Maximum Capacity.";
	else
		info="No Overload. Train is carrying load not exceeding maximum capacity.";}
	
	void displayInfo(){
		cout<<"Goods Train:"<<endl;
		cout<<"Starting from "<<source<<" and reaching "<<destination<<endl;
		cout<<"Product Transported:"<<product<<endl;
		cout<<info<<endl;
	}
};
int main(){
	int choice;
	cout<<"Select Train Type:\n1.Express Train\n2.Passenger Train\n3.Goods Train\nEnter your choice:";
	cin>>choice;
	if(choice==1){
		int a,b;
		string c,d,e,f;
		cout<<"Enter Train No:";
		cin>>a;
		cout<<"Enter Train Name:";
		cin.ignore();
		getline(cin,c);
		cout<<"Enter PNR:";
		cin>>b;
		cout<<"Enter Passenger Name:";
		cin.ignore();
		getline(cin,d);
		cout<<"Enter Source:";
		getline(cin,e);		
		cout<<"Enter Destination:";
		getline(cin,f);		
		ExpressTrain ap(c,a,e,f,d,b);
		VTrain *p;
		p = &ap;
		p->displayInfo();
	}
	else if(choice==2){
		string start,end;
		int dist;
		cin.ignore();
		cout<<"Enter Source:";
		getline(cin,start);
		cout<<"Enter Destination:";
		getline(cin,end);
		cout<<"Enter Distance:";
		cin>>dist;
		PassengerTrain ap(start,end,dist);
		ap.setfare();
		VTrain *p;
		p = &ap;
		p->displayInfo();
	}
	else{
		string a,b,c;
		int d,e;
		cin.ignore();
		cout<<"Enter Source:";
		getline(cin,a);
		cout<<"Enter Destination:";
		getline(cin,b);
		cout<<"Enter Product:";
		getline(cin,c);
		cout<<"Enter Max Capacity:";
		cin>>d;
		cout<<"Enter Load:";
		cin>>e;
		CargoTrain ap(a,b,d,e,c);
		VTrain *p;
		p = &ap;
		p->displayInfo();
	}
	
	return 0;
}