#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>

void displayMenu() {
    std::cout << "\n--- Passenger Queue System ---" << std::endl;
    std::cout << "1. Insert new passenger (Rear)" << std::endl;
    std::cout << "2. Display passenger at front" << std::endl;
    std::cout << "3. Remove passenger (Front)" << std::endl;
    std::cout << "4. Exit program" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    std::queue<std::string> passengerQueue;
    int choice;

    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            choice = 4;
        }

        switch (choice) {
            case 1: {
                std::string name;
                std::cout << "Enter passenger name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                passengerQueue.push(name);
                std::cout << name << " added to the queue." << std::endl;
                break;
            }
            case 2: {
                if (passengerQueue.empty()) {
                    std::cout << "The queue is empty. No passenger at the front." << std::endl;
                } else {
                    std::cout << "Passenger at the front: " << passengerQueue.front() << std::endl;
                }
                break;
            }
            case 3: {
                if (passengerQueue.empty()) {
                    std::cout << "The queue is empty. No one to remove." << std::endl;
                } else {
                    std::cout << "Passenger " << passengerQueue.front() << " removed from the queue." << std::endl;
                    passengerQueue.pop();
                }
                break;
            }
            case 4: {
                break;
            }
            default: {
                std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
            }
        }
    } while (choice != 4);

    std::cout << "\n--- Program Terminating ---" << std::endl;
    std::cout << "Number of passengers left in the queue: " << passengerQueue.size() << std::endl;
    std::cout << "---------------------------" << std::endl;

    return 0;
}