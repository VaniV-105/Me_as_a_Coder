#include <iostream>
using namespace std;
#include <string>
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
	
	return 0;
}

		
	
