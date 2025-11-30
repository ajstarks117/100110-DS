/*The ticket reservation system for Galaxy Multiplex is to be implemented using a C++ program. The multiplex has 8 rows, with 8 seats in each row. A doubly circular linked list will be 
used to track the availability of seats in each row. Initially, assume that some seats are randomly booked. An array will store head pointers for each row’s linked list. 
The system should support the following operations:
a) Display the current list of available seats.
b) Book one or more seats as per customer request.
c) Cancel an existing booking when requested.
*/

#include <iostream>
using namespace std;

struct Node {
    int seat;
    bool booked;     
    Node *prev, *next;
};

Node* rows[8];   


void createRow(int row) {
    Node* head = nullptr;
    Node* last = nullptr;

    for(int i = 1; i <= 8; i++) {
        Node* temp = new Node;
        temp->seat = i;
        temp->booked = false; 
        temp->next = temp->prev = nullptr;

        if(head == nullptr) {
            head = last = temp;
        } else {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }


    head->prev = last;
    last->next = head;

    rows[row] = head;
}


void displaySeats() {
    cout << "\n======= CURRENT SEAT AVAILABILITY =======\n";
    for(int r = 0; r < 8; r++) {
        cout << "Row " << r+1 << ": ";
        Node* head = rows[r];
        Node* temp = head;

        do {
            if(temp->booked == 0)
                cout << temp->seat << " ";
            temp = temp->next;
        } while(temp != head);

        cout << endl;
    }
}


void bookSeat(int row, int seat) {
    Node* head = rows[row];
    Node* temp = head;

    do {
        if(temp->seat == seat) {
            if(temp->booked == 1) {
                cout << "Seat already booked!\n";
                return;
            }
            temp->booked = 1;
            cout << "Seat booked successfully.\n";
            return;
        }
        temp = temp->next;
    } while(temp != head);
}


void cancelSeat(int row, int seat) {
    Node* head = rows[row];
    Node* temp = head;

    do {
        if(temp->seat == seat) {
            if(temp->booked == 0) {
                cout << "Seat is not booked.\n";
                return;
            }
            temp->booked = 0;
            cout << "Booking cancelled.\n";
            return;
        }
        temp = temp->next;
    } while(temp != head);
}


void randomBookings() {
    rows[0]->booked = true;       
    rows[2]->next->booked = true;
    rows[5]->next->next->booked = true;
}


int main() {

    // Create rows 1 to 8
    for(int i = 0; i < 8; i++)
        createRow(i);

    randomBookings();

    int choice, row, seat, count;

    while(true) {
        cout << "\n===== GALAXY MULTIPLEX TICKET SYSTEM =====";
        cout << "\n1. Display Available Seats";
        cout << "\n2. Book Seats";
        cout << "\n3. Cancel Booking";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            displaySeats();
            break;

        case 2:
            cout << "Enter row number (1-8): ";
            cin >> row;
            row--;
            cout << "How many seats to book? ";
            cin >> count;
            while(count--) {
                cout << "Enter seat number (1-8): ";
                cin >> seat;
                bookSeat(row, seat);
            }
            break;

        case 3:
            cout << "Enter row number (1-8): ";
            cin >> row;
            row--;
            cout << "Enter seat number to cancel (1-8): ";
            cin >> seat;
            cancelSeat(row, seat);
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
