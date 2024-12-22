#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>


//most of theses are copies of passeneger, flight, and plane
class Flight {
public:
    Flight(std::string id, std::string departure, std::string destination)
        : id(id), departure(departure), destination(destination) {}

    void display() const {
        std::cout << "Flight ID: " << id
                  << ", Departure: " << departure
                  << ", Destination: " << destination << std::endl;
    }

    std::string getId() const { return id; }
    std::string getDeparture() const { return departure; }
    std::string getDestination() const { return destination; }

private:
    std::string id;
    std::string departure;
    std::string destination;
};

void loadFlightsFromFile(std::vector<Flight>& flights, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string id, departure, destination;
    while (std::getline(file, id) && std::getline(file, departure) && std::getline(file, destination)) {
        flights.push_back(Flight(id, departure, destination));
    }
    file.close();
}

void displayFlights(const std::vector<Flight>& flights) {
    std::cout << "\nFlights:\n";
    for (const auto& flight : flights) {
        flight.display();
    }
}

void attemptTakeoff(std::vector<Flight>& flights) {
    if (flights.empty()) {
        std::cout << "No flights available.\n";
        return;
    }

    // Randomly select a flight
    srand(time(0));  // Seed the random number generator
    int randomIndex = rand() % flights.size();  // Get a random index
    Flight selectedFlight = flights[randomIndex];

    // Ask the user if the flight can take off
    std::string input;
    bool confirmed = false;
    while (!confirmed) {
        selectedFlight.display();  // Display flight information
        std::cout << "Do you want this flight to take off? (yes/no): ";
        std::cin >> input;
        if (input == "yes") {
            std::cout << "Flight " << selectedFlight.getId() << " is taking off.\n";
            confirmed = true;  // Exit the loop, flight has taken off
        } else if (input == "No") {
            std::cout << "Flight " << selectedFlight.getId() << " will wait for another 10 seconds before trying again...\n";
            std::this_thread::sleep_for(std::chrono::seconds(10));  // Wait for 10 seconds before asking again
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";
        }
    }
}