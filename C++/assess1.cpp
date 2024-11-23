#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
template <typename T,typename U>
void TicketDetails(T a,U b){
    cout<<"Your train details:"<<endl;
    cout<<"Train Name/No:"<<a<<endl;
    cout<<"Passenger Details:"<<endl;
    cout<<"Passenger Name/ID:"<<b<<endl;
}
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
class Entity {
public:
    string EntityName;

    Entity(string entity) : EntityName(entity) {}

    void displayEntity() {
        cout << EntityName << " Entity";
    }
};
class Trains : virtual public Entity {
public:
    Trains(string name) : Entity(name + " Train") {}

    void displayTrain() {
        cout << "Train: ";
        displayEntity();
    }
};
class Stationss : virtual public Entity {
public:
    Stationss(string name) : Entity(name + " Station") {}

    void displayStation() {
        cout << "Station: ";
        displayEntity();
    }
};
class Ticket : public Trains, public Stationss {
public:
    Ticket(string name)
        : Entity(name + " Ticket"),
          Trains(name),
          Stationss(name) {}

    void displayTicket() {
        cout << "Ticket: ";
        displayEntity();
    }
};
class Vehicle : public Entity {
public:
    Vehicle(string vehicle) : Entity(vehicle) {}

    void displayVehicle() {
        cout << "Vehicle: ";
        displayEntity();
    }
};
class Stations : public Entity {
public:
    Stations(string station) : Entity(station) {}

    void displayStation() {
        cout << "Station: ";
        displayEntity();
    }
};
class Employee : public Entity {
public:
    Employee(string employee) : Entity(employee) {}

    void displayEmployee() {
        cout << "Employee: ";
        displayEntity();
    }
};
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
class STATION{
    public:
        string StationName;
        STATION(string station){
            StationName=station;
        }
        void displayStation(){
            cout<< StationName <<endl;
            
        }
};
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
class train{
    private:
        int train_no,no_of_comp,seats_per_comp,total_seats;
        string train_name,train_type;
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
class Station:public Zone{
    public:
        string StationName;
        Station(string zone, string station) : Zone(zone), StationName(station) {}
        void displayStation(){
            cout<< StationName << " is in ";
            displayZone();
        }
};
class Platform:public Station{
    public:
        int platform;
        Platform(string zone,string station,int pno):Station(zone,station),platform(pno){}
        void display(){
            cout<<"Platform "<<platform<<" at ";
            displayStation();
        }
};
class ZonalRegion : public Zone, public STATION {
public:
    ZonalRegion(string zone, string station)
        : Zone(zone), STATION(station) {}

    void displaySystem() {
        cout << "Railway Zone at ";
        displayZone(); // Specify the scope for Zone's member function
        cout << " with headquarters at ";
        displayStation(); // Specify the scope for Station's member function
    }
};
class booking{
	public:
		int seats;
		double rate;
		double tax;
		string PNR;
		int ch;
		booking(){}
		booking(string PID){
			this->PNR = PID;
			this->seats = 700;
		}
		void getch(){
			cout<<"Select your seat type:\n 1.First Class AC\n 2.Second Class AC\n 3.Third Class AC\n 4.Sleeper\n 5.Chair Car \n 6.Unreserved\nEnter your choice:";
			cin>>ch;
		}
		void setcost(){
			switch(ch){
				case 1:
					rate = 1500.00;
					break;
				case 2:
					rate = 1250;
					break;
				case 3:
					rate = 1000;
					break;
				case 4:
					rate = 800;
					break;
				case 5:
					rate = 600;
					break;
				default:
					rate = 400;
			}
			tax = 0.18*rate;
		}
		void operator --()
		{
			seats = --seats;
		}
		void displayremseats(){
			cout<<"Seats Available: "<<seats<<endl;
		}
		booking operator +(booking&b)
		{
			booking b1;
			b1.PNR = PNR + b.PNR;
			b1.rate = rate + b.rate;
			b1.tax = tax + b.tax;
			return b1;
		}
		void display(){
			cout<<"Rate: "<<rate<<"\tTax: "<<tax<<"\nTotal Amount:"<<rate+tax<<endl;
		}
		void displayop(){
			cout<<"Since you are paying for both the tickets."<<endl;
	cout<<"PNR: "<<PNR<<"\nRate altogether: "<<rate<<"\nTax altogether: "<<tax<<"\nTotal Amount: "<<rate+tax<<endl;
}
};
int main(){
        train t;
        t.getdata();
        t.display();
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
    booking aashin("6072"),ap("6128");
	aashin.getch();
	aashin.setcost();
	--aashin;
	aashin.display();
	aashin.displayremseats();
	ap.getch();
	ap.setcost();
	ap.display();
	--ap;
	ap.displayremseats();
	booking b= aashin+ap;
	b.displayop();
	string station,zone;
    cin.ignore();
    cout<<endl;
    cout<<"Enter Station Name:";
    getline(cin,station);
    cout<<"Enter Zone:";
    cin>>zone;
    Station ap1(zone,station);
    ap1.displayStation();
    int pf;
    cin.ignore();
    cout<<endl;
    cout<<"Enter Station Name:";
    getline(cin,station);
    cout<<"Enter Platform No:";
    cin>>pf;
    cout<<"Enter Zone:";
    cin>>zone;
    Platform pf1(zone,station,pf);
    pf1.display();
    cout<<endl;
    ZonalRegion myRailway("Southern", "MGR Chennai Central");
    myRailway.displaySystem();
    Vehicle myVehicle("Express Train");
    Stations myStation("Grand Central Station");
    Employee myEmployee("John Doe");
    myVehicle.displayVehicle();
    cout << endl;
    myStation.displayStation();
    cout << endl;
    myEmployee.displayEmployee();
    cout << endl;
    Ticket ticket("ABC123");
    ticket.displayTicket();
    cout << endl;
    ticket.displayTrain();
    cout << endl;
    ticket.displayStation();
    cout << endl;
    MaintenanceCrew maintenancePerson("John Doe", "Maintenance Vehicle");
    maintenancePerson.displayMaintenanceCrew();
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
    cin>>choice;
    if(choice==1){
        TicketDetails(tno,pid);
    }
    else{
        TicketDetails(t_name,p_name);
    }
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