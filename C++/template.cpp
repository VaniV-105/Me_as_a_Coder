#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

template <typename T>
class TrainInfo {
public:
    T trainNumber;
    std::string trainName;
    T capacity;

    TrainInfo(T number, const std::string& name, T cap) : trainNumber(number), trainName(name), capacity(cap) {}

    void displayInfo() const {
        std::cout << "Train Number: " << trainNumber << "\n";
        std::cout << "Train Name: " << trainName << "\n";
        std::cout << "Capacity: " << capacity << " passengers\n";
    }
};

template <typename T>
class PassengerInfo {
public:
    std::string passengerName;
    T seatNumber;

    PassengerInfo(const std::string& name, T seat) : passengerName(name), seatNumber(seat) {}

    void displayInfo() const {
        std::cout << "Passenger Name: " << passengerName << "\n";
        std::cout << "Seat Number: " << seatNumber << "\n";
    }
};

template <typename T>
class RailwaySystem {
private:
    std::vector<TrainInfo<T>> trains;
    std::vector<PassengerInfo<T>> passengers;

public:
    void addTrain(T number, const std::string& name, T capacity) {
        trains.emplace_back(number, name, capacity);
        std::cout << "Train added successfully.\n";
    }

    void displayAllTrains() const {
        if (trains.empty()) {
            std::cout << "No trains available.\n";
            return;
        }

        std::cout << "List of all trains:\n";
        for (const auto& train : trains) {
            train.displayInfo();
            std::cout << "---------------------\n";
        }
    }

    void bookTicket(const std::string& passengerName, T trainNumber, T seatNumber) {
        // Check if the train exists
        auto it = std::find_if(trains.begin(), trains.end(), [trainNumber](const TrainInfo<T>& train) {
            return train.trainNumber == trainNumber;
        });

        if (it != trains.end()) {
            // Check if the seat is available
            auto seatOccupied = std::find_if(passengers.begin(), passengers.end(), [seatNumber](const PassengerInfo<T>& passenger) {
                return passenger.seatNumber == seatNumber;
            });

            if (seatOccupied == passengers.end()) {
                passengers.emplace_back(passengerName, seatNumber);
                std::cout << "Ticket booked successfully.\n";
            } else {
                std::cout << "Seat " << seatNumber << " is already occupied.\n";
            }
        } else {
            std::cout << "Train with number " << trainNumber << " not found.\n";
        }
    }

    void displayAllPassengers() const {
        if (passengers.empty()) {
            std::cout << "No passengers booked.\n";
            return;
        }

        std::cout << "List of all passengers:\n";
        for (const auto& passenger : passengers) {
            passenger.displayInfo();
            std::cout << "---------------------\n";
        }
    }

    void saveDataToFile(const std::string& filename) const {
        std::ofstream outFile(filename);

        for (const auto& train : trains) {
            outFile << "Train Number: " << train.trainNumber << "\n";
            outFile << "Train Name: " << train.trainName << "\n";
            outFile << "Capacity: " << train.capacity << " passengers\n";
            outFile << "---------------------\n";
        }

        for (const auto& passenger : passengers) {
            outFile << "Passenger Name: " << passenger.passengerName << "\n";
            outFile << "Seat Number: " << passenger.seatNumber << "\n";
            outFile << "---------------------\n";
        }

        std::cout << "Data saved to " << filename << ".\n";
    }

    void loadDataFromFile(const std::string& filename) {
        std::ifstream inFile(filename);

        T trainNumber, capacity, seatNumber;
        std::string trainName, passengerName;

        while (inFile >> trainNumber >> trainName >> capacity) {
            trains.emplace_back(trainNumber, trainName, capacity);
        }

        while (inFile >> passengerName >> seatNumber) {
            passengers.emplace_back(passengerName, seatNumber);
        }

        std::cout << "Data loaded from " << filename << ".\n";
    }
};

int main() {
    RailwaySystem<int> railway;

    railway.addTrain(101, "Express One", 200);
    railway.addTrain(202, "Fast Track", 150);

    railway.displayAllTrains();

    railway.bookTicket("Alice", 101, 1);
    railway.bookTicket("Bob", 101, 2);
    railway.bookTicket("Charlie", 202, 1);

    railway.displayAllPassengers();

    railway.saveDataToFile("railway_data.txt");
    railway.loadDataFromFile("railway_data.txt");

    return 0;
}
