#include <iostream>
#include <vector>
//#include "Passenger.cpp"  // Include the Passenger implementation
#include "Plane.cpp"      // Include the Plane implementation
#include "Gate.cpp"       // Include the Gate implementation
#include "DisplayMenu.cpp" 
#include "LinkedList.cpp"
#include "Terminal.cpp"
#include "Flight.cpp"     // Include the Flight implementation



int main() {
    



    LinkedList passengers;
    std::vector<Plane> planes;
    std::vector<Gate> gates;
    std::vector<Flight> flights;

    // Load data from files
    passengers.loadFromFile("passengers.txt");
    loadPlanes(planes, "planes.txt");
    loadGates(gates, "gates.txt");

    // Load flights from file
    loadFlightsFromFile(flights, "flights.txt");


    int choice;
    std::string takeoffChoice;  // Declare the variable here
    do {
        displayMenu(); // Show the menu to the user
        std::cin >> choice;

        switch (choice) {
            case 1:
                passengers.showPassengers(); // Display all passengers
                break;
            case 2: {
                Passenger newPassenger = addPassenger();// Add a new passenger
                passengers.addPassenger(newPassenger);
                break;
            }
            case 3:
                showPlanes(planes); // Display all planes
                break;
            case 4:
                addPlane(planes);//honeslty all of the cases kind of speak for thmeslesves 
                break;
            case 5:
                showGates(gates);
                break;
            case 6:
                addGate(gates);
                break;
            case 7:
                showFlightTerminalInfo(planes, gates);
                break;
            case 8:
                displayFlights(flights);  // Display flights
                std::cout << "Do you want to take off any flight? (yes/No): ";
                std::cin >> takeoffChoice;
                if (takeoffChoice == "yes") {
                    attemptTakeoff(flights);  // Call the takeoff function
                }
                break;
            case 9:
                std::cout << "Exiting...\n";
                // Save data to files
                passengers.saveToFile("passengers.txt");
                savePlanes(planes, "planes.txt");
                saveGates(gates, "gates.txt");
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}