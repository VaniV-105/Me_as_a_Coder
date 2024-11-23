#include <iostream>
#include <string>
using namespace std;
template<typename TrainType>
class TrainTemplate {
private:
    TrainType trainNumber;
    string destination;

public:
    TrainTemplate(TrainType number, string dest) : trainNumber(number) , destination(dest) {
	}
    TrainType getTrainNumber()  { 
		return trainNumber; 
	}
    string getDestination() {
		return destination; 
	}
    template<typename T>
    void displayTrainInfo(T info) {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Destination: " << destination << endl;
        cout << "Additional Info: " << info << endl;
    }
};

int main() {
    TrainTemplate<int> train1(12345, "New York");
    train1.displayTrainInfo("Express Train");
    TrainTemplate<string> train2("ABC123", "Los Angeles");
    train2.displayTrainInfo("Local Train");
    return 0;
}

