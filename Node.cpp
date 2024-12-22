// Node.cpp
#include "Passenger.cpp"


// Node structure to hold passenger data and link to the next node
struct Node {
    Passenger data;
    Node* next;

// this is used to initialize a node with passenger data and set next to nullptr which is a pointer
    Node(const Passenger& passenger) : data(passenger), next(nullptr) {}
};
