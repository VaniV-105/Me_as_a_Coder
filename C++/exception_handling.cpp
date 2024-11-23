#include <iostream>
#include <stdexcept>
using namespace std;
class TicketBookingSystem {
public:
    void bookTicket(int numSeats) {
        try {
            if (numSeats <= 0) {
                throw invalid_argument("Invalid number of seats. Please provide a positive integer.");
            }
            int availableSeats = 100; 
            if (numSeats > availableSeats) {
                throw runtime_error("Insufficient seats available. Please choose fewer seats.");
            }
            cout << numSeats << " tickets booked successfully!" << endl;
        } 
        catch (const invalid_argument& e) {
            cout << "Invalid Argument Error: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Runtime Error: " << e.what() << endl;
        }
    }
};
int main() {
    TicketBookingSystem bookingSystem;
    bookingSystem.bookTicket(-5); 
    bookingSystem.bookTicket(150); 

    return 0;
}

