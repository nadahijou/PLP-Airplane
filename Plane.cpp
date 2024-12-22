// Plane.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>



//most of theses are copies of passeneger, flight, and plane
class Plane {
public:
    Plane(const std::string& id, const std::string& model, int capacity)
        : id(id), model(model), capacity(capacity) {}

    void display() const {
        std::cout << "Plane ID: " << id << ", Model: " << model << ", Capacity: " << capacity << std::endl;
    }

    std::string getFlightNumber() const { return id; }
    std::string getDestination() const { return model; } // Assuming model is used as destination for simplicity

    std::string toString() const {
        return id + "," + model + "," + std::to_string(capacity);
    }

    static Plane fromString(const std::string& str) {
        size_t pos1 = str.find(',');
        size_t pos2 = str.find(',', pos1 + 1);
        return Plane(str.substr(0, pos1), str.substr(pos1 + 1, pos2 - pos1 - 1), std::stoi(str.substr(pos2 + 1)));
    }

private:
    std::string id;
    std::string model;
    int capacity;
};

void showPlanes(const std::vector<Plane>& planes) {
    std::cout << "Planes List:\n";
    for (const auto& plane : planes) {
        plane.display();
    }
}

void addPlane(std::vector<Plane>& planes) {
    std::string id, model;
    int capacity;

    std::cout << "Enter Plane ID: ";
    std::cin >> id;
    std::cout << "Enter Plane Model: ";
    std::cin >> model;
    std::cout << "Enter Plane Capacity: ";
    std::cin >> capacity;

    planes.emplace_back(id, model, capacity);
    std::cout << "Plane added successfully!\n";
}

void savePlanes(const std::vector<Plane>& planes, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& plane : planes) {
        file << plane.toString() << std::endl;
    }
}

void loadPlanes(std::vector<Plane>& planes, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        planes.push_back(Plane::fromString(line));
    }
}
