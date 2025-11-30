/*Develop a C++ program to store and manage an appointment schedule for a single day. Appointments should be scheduled randomly using a linked list. The system must define the start time, 
end time, and specify the minimum and maximum duration allowed for each appointment slot.
The program should include the following operations:
a) Display the list of currently available time slots.
 b) Book a new appointment within the defined time limits.
 c) Cancel an existing appointment after validating its time, availability, and correctness.
 d) Sort the appointment list in order of appointment times.
*/


#include <iostream>
using namespace std;

struct Node {
    int start;
    int end;
    Node* next;

    Node(int s, int e) {
        start = s;
        end = e;
        next = nullptr;
    }
};

Node* booked = nullptr;      // list of booked appointments
Node* available = nullptr;   // list of available free slots

// Insert a slot in sorted order in available list
void insertAvailable(int s, int e) {
    Node* p = new Node(s, e);
    if (!available || s < available->start) {
        p->next = available;
        available = p;
        return;
    }
    Node* cur = available;
    while (cur->next && cur->next->start < s)
        cur = cur->next;
    p->next = cur->next;
    cur->next = p;
}

// Insert booking in sorted order
void insertBooked(int s, int e) {
    Node* p = new Node(s, e);
    if (!booked || s < booked->start) {
        p->next = booked;
        booked = p;
        return;
    }
    Node* cur = booked;
    while (cur->next && cur->next->start < s)
        cur = cur->next;
    p->next = cur->next;
    cur->next = p;
}

// Display available slots
void displayAvailable() {
    cout << "\nAvailable Slots:\n";
    Node* cur = available;
    while (cur) {
        cout << cur->start << " - " << cur->end << endl;
        cur = cur->next;
    }
}

// Display booked appointments
void displayBooked() {
    cout << "\nBooked Appointments:\n";
    Node* cur = booked;
    while (cur) {
        cout << cur->start << " - " << cur->end << endl;
        cur = cur->next;
    }
}

// Book a new appointment
void bookAppointment(int s, int e) {
    Node* cur = available;
    Node* prev = nullptr;

    while (cur) {
        if (s >= cur->start && e <= cur->end) {
            cout << "Appointment booked.\n";

            insertBooked(s, e);

            // Case 1: exact match (slot fully used)
            if (s == cur->start && e == cur->end) {
                if (prev) prev->next = cur->next;
                else available = cur->next;
                delete cur;
                return;
            }

            // Case 2: split available slot
            if (s > cur->start) 
                insertAvailable(cur->start, s);

            if (e < cur->end)
                insertAvailable(e, cur->end);

            // remove current
            if (prev) prev->next = cur->next;
            else available = cur->next;
            delete cur;

            return;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << "Error: Slot not available.\n";
}

// Cancel appointment
void cancelAppointment(int s, int e) {
    Node* cur = booked;
    Node* prev = nullptr;

    while (cur) {
        if (cur->start == s && cur->end == e) {
            cout << "Appointment cancelled.\n";

            // remove from booked list
            if (prev) prev->next = cur->next;
            else booked = cur->next;

            // add back into available list
            insertAvailable(s, e);
            delete cur;

            return;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << "Error: Appointment not found.\n";
}

// Sort booked list by start time (bubble sort)
void sortBooked() {
    if (!booked || !booked->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* cur = booked;

        while (cur->next) {
            if (cur->start > cur->next->start) {
                swap(cur->start, cur->next->start);
                swap(cur->end, cur->next->end);
                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);

    cout << "Booked appointments sorted.\n";
}

int main() {

    int start_time = 900;     // 9:00 AM
    int end_time = 1700;      // 5:00 PM

    int minDur = 30;          // min 30 minutes
    int maxDur = 120;         // max 2 hours

    // Initially whole day is free
    insertAvailable(start_time, end_time);

    int ch, s, e;

    while (true) {
        cout << "\n--- Appointment Scheduling System ---\n";
        cout << "1. Display Available Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Display Booked Appointments\n";
        cout << "5. Sort Booked Appointments\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch(ch) {

        case 1:
            displayAvailable();
            break;

        case 2:
            cout << "Enter start time (e.g., 930 for 9:30): ";
            cin >> s;
            cout << "Enter end time: ";
            cin >> e;
            if (e - s < minDur || e - s > maxDur)
                cout << "Invalid duration! Must be between "
                     << minDur << " and " << maxDur << " minutes.\n";
            else
                bookAppointment(s, e);
            break;

        case 3:
            cout << "Enter start time to cancel: ";
            cin >> s;
            cout << "Enter end time: ";
            cin >> e;
            cancelAppointment(s, e);
            break;

        case 4:
            displayBooked();
            break;

        case 5:
            sortBooked();
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid option!\n";
        }
    }
}
