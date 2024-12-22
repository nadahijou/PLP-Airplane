// Gate.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//most of theses are copies of passeneger, flight, and plane
class Gate {
public:
    Gate(const std::string& id, const std::string& assignedFlight)
        : id(id), assignedFlight(assignedFlight) {}

    void display() const {
        std::cout << "Gate ID: " << id << ", Assigned Flight: " << assignedFlight << std::endl;
    }

    std::string getAssignedPlane() const { return assignedFlight; }
    std::string getTerminal() const { return "Terminal 1"; } // Example terminal
    std::string getGateNumber() const { return id; }
    std::string getDepartureTime() const { return "12:00 PM"; } // Example time

    std::string toString() const {
        return id + "," + assignedFlight;
    }

    static Gate fromString(const std::string& str) {
        size_t pos = str.find(',');
        return Gate(str.substr(0, pos), str.substr(pos + 1));
    }

private:
    std::string id;
    std::string assignedFlight;
};

void showGates(const std::vector<Gate>& gates) {
    std::cout << "Gates List:\n";
    for (const auto& gate : gates) {
        gate.display();
    }
}

void addGate(std::vector<Gate>& gates) {
    std::string id, assignedFlight;

    std::cout << "Enter Gate ID: ";
    std::cin >> id;
    std::cout << "Enter Assigned Flight ID: ";
    std::cin >> assignedFlight;

    gates.emplace_back(id, assignedFlight);
    std::cout << "Gate added successfully!\n";
}

void saveGates(const std::vector<Gate>& gates, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& gate : gates) {
        file << gate.toString() << std::endl;
    }
}

void loadGates(std::vector<Gate>& gates, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        gates.push_back(Gate::fromString(line));
    }
}
