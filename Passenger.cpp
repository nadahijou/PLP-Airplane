// Passenger.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


//most of theses are copies of passeneger, flight, and plane

class Passenger {
public:
    Passenger(const std::string& name, const std::string& flight, const std::string& seat)
        : name(name), flight(flight), seat(seat) {}

    void display() const {
        std::cout << "Name: " << name << ", Flight: " << flight << ", Seat: " << seat << std::endl;
    }

    std::string toString() const {
        return name + "," + flight + "," + seat;
    }

    static Passenger fromString(const std::string& str) {
        size_t pos1 = str.find(',');
        size_t pos2 = str.find(',', pos1 + 1);
        return Passenger(str.substr(0, pos1), str.substr(pos1 + 1, pos2 - pos1 - 1), str.substr(pos2 + 1));
    }

private:
    std::string name;
    std::string flight;
    std::string seat;
};

void showPassengers(const std::vector<Passenger>& passengers) {
    std::cout << "Passengers List:\n";
    for (const auto& passenger : passengers) {
        passenger.display();
    }
}


Passenger addPassenger() {
    std::string name, flight, seat;

    std::cout << "Enter Passenger Name: ";
    std::cin.ignore(); // Clear newline from previous input
    std::getline(std::cin, name);
    std::cout << "Enter Flight ID: ";
    std::cin >> flight;
    std::cout << "Enter Seat Number: ";
    std::cin >> seat;

    std::cout << "Passenger added successfully!\n";
    return Passenger(name, flight, seat);
}


void savePassengers(const std::vector<Passenger>& passengers, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& passenger : passengers) {
        file << passenger.toString() << std::endl;
    }
}

void loadPassengers(std::vector<Passenger>& passengers, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        passengers.push_back(Passenger::fromString(line));
    }
}
