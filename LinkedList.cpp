// LinkedList.cpp
#include <fstream>
#include <string>
#include "Node.cpp"

class LinkedList {
public:
    LinkedList() : head(nullptr) {} //  initializes an empty list

    ~LinkedList() {
        clear(); // clears the list to free memory
    }

    void addPassenger(const Passenger& passenger) {
        Node* newNode = new Node(passenger);  // Create a new node with passenger data
        if (!head) {
            head = newNode; // If list is empty, new node becomes the head
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next; // Traverse to the end of the list
            }
            current->next = newNode; // Add new node at the end
        }
    }

    void showPassengers() const {
        Node* current = head;
        while (current) {
            current->data.display(); // Ensure Passenger has a display method
            current = current->next;
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open " << filename << " for reading.\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            Passenger passenger = Passenger::fromString(line);
            addPassenger(passenger);
        }
        file.close();
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open " << filename << " for writing.\n";
            return;
        }

        Node* current = head;
        while (current) {
            file << current->data.toString() << std::endl;
            current = current->next;
        }
        file.close();
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;// Reset head to indicate the list is empty
    }

private:
    Node* head;// Pointer to the first node in the list
};
