#include <iostream>
#include <string>

using namespace std;

struct Train {
    string trainNumber;
    string departureStation;
    string arrivalStation;
    string departureTime;
    string arrivalTime;
};

void displayTrainDetails(const Train& train) {
    cout << "Train Number: " << train.trainNumber << endl;
    cout << "Departure Station: " << train.departureStation << endl;
    cout << "Arrival Station: " << train.arrivalStation << endl;
    cout << "Departure Time: " << train.departureTime << endl;
    cout << "Arrival Time: " << train.arrivalTime << endl;
    cout << endl;
}

void swapStations(Train& train) {
    train.departureStation.swap(train.arrivalStation);
}

void replaceSubstringInTrainNumber(Train& train, const string& oldSubstring, const string& newSubstring) {
    size_t pos = train.trainNumber.find(oldSubstring);
    if (pos != string::npos) {
        train.trainNumber.replace(pos, oldSubstring.length(), newSubstring);
    }
}

int main() {
    Train train1 = {"12345", "New Delhi", "Mumbai Central", "10:00", "22:00"};

    cout << "Original Train Details:" << endl;
    displayTrainDetails(train1);

    cout << "After Swapping Stations:" << endl;
    swapStations(train1);
    displayTrainDetails(train1);

    cout << "After Replacing Substring in Train Number:" << endl;
    replaceSubstringInTrainNumber(train1, "12345", "54321");
    displayTrainDetails(train1);

    return 0;
}
