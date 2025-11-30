#include <iostream>
#include <string>
#include <queue>
#include <utility>

struct Patient {
    std::string name;
    int id;
};

class ClinicSystem {
private:
    std::queue<Patient> waitingQueue;
    int nextPatientId;

public:
    ClinicSystem() : nextPatientId(101) {}

    void checkInPatient(std::string name) {
        Patient newPatient = {name, nextPatientId++};
        waitingQueue.push(newPatient);
        std::cout << newPatient.name << " (ID: " << newPatient.id << ") has checked in and is waiting." << std::endl;
    }

    void assignToDoctor() {
        if (waitingQueue.empty()) {
            std::cout << "No patients currently waiting to be assigned." << std::endl;
            return;
        }

        Patient assignedPatient = waitingQueue.front();
        waitingQueue.pop();

        std::cout << "Assigned to Doctor: " << assignedPatient.name << " (ID: " << assignedPatient.id << ")" << std::endl;
    }

    void displayQueue() {
        if (waitingQueue.empty()) {
            std::cout << "The waiting queue is empty." << std::endl;
            return;
        }

        std::cout << "\n--- Waiting Queue (FCFS) ---" << std::endl;
        std::queue<Patient> tempQueue = waitingQueue;
        int position = 1;
        while (!tempQueue.empty()) {
            Patient p = tempQueue.front();
            tempQueue.pop();
            std::cout << position++ << ". " << p.name << " (ID: " << p.id << ")" << std::endl;
        }
        std::cout << "--------------------------" << std::endl;
    }
};

int main() {
    ClinicSystem clinic;

    clinic.checkInPatient("Alice Smith");
    clinic.checkInPatient("Bob Johnson");
    clinic.checkInPatient("Charlie Brown");
    clinic.displayQueue();

    std::cout << "\n--- Doctor becomes available ---\n";
    clinic.assignToDoctor();

    clinic.checkInPatient("Diana Prince");
    clinic.displayQueue();

    std::cout << "\n--- Two more doctors become available ---\n";
    clinic.assignToDoctor();
    clinic.assignToDoctor();
    
    clinic.displayQueue();

    std::cout << "\n--- Final assignment attempt ---\n";
    clinic.assignToDoctor();
    clinic.assignToDoctor();

    return 0;
}