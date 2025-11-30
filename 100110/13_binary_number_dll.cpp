/*Write a C++ program to store a binary number using a doubly linked list. Implement the following functions:
a) Calculate and display the 1’s complement and 2’s complement of the stored binary number. */

#include <iostream>
using namespace std;


/* Node of a doubly linked list representing one binary digit (bit). */
struct Node {
        int bit;     // 0 or 1
        Node* prev;  // pointer to previous node
        Node* next;  // pointer to next node
        Node(int b) { bit = b; prev = next = NULL; }
};

/* Head and tail pointers for the list that stores the original binary number. */
Node* head = NULL;
Node* tail = NULL;

/* Insert a bit at the end of the list (least significant end is the tail). */
void insertBit(int b) {
        Node* p = new Node(b);
        if (!head) {
                head = tail = p; // first element
                return;
        }
        tail->next = p;
        p->prev = tail;
        tail = p;
}

/* Display bits from a given head pointer (left to right). */
void display(Node* h) {
        Node* t = h;
        while(t) {
                cout << t->bit;
                t = t->next;
        }
        cout << endl;
}

/* Create and return a new linked list representing the 1's complement.
     1's complement is obtained by flipping each bit (0->1, 1->0). */
Node* onesComplement() {
        Node* t = head;
        Node* h2 = NULL;    // head of new list
        Node* tail2 = NULL; // tail of new list

        while(t) {
                // flip the current bit and create a new node
                Node* p = new Node( t->bit == 0 ? 1 : 0 );
                if(!h2) h2 = tail2 = p;
                else { tail2->next = p; p->prev = tail2; tail2 = p; }
                t = t->next;
        }
        return h2;
}

/* Create and return the 2's complement.
     2's complement = (1's complement) + 1. This function works on a copy
     produced by onesComplement so the original list is unchanged. */
Node* twosComplement() {
        Node* one = onesComplement(); // start from 1's complement
        Node* t = one;
        // move to the least significant bit (tail of the new list)
        while(t->next) t = t->next;

        int carry = 1; // we add 1 to the 1's complement
        while(t) {
                int sum = t->bit + carry;
                t->bit = sum % 2; // result bit
                carry = sum / 2;  // new carry (0 or 1)
                t = t->prev;      // move toward more significant bits
        }
        // If carry remains after the most significant bit, it is ignored here
        // because typical fixed-width binary representation discards overflow.
        return one;
}

int main() {
        string bin;
        cout << "Enter binary number: ";
        cin >> bin;

        // Build the doubly linked list from the input string (left-to-right).
        for(char c : bin)
                insertBit(c - '0');

        cout << "Original: ";
        display(head);

        // Compute and display 1's complement.
        Node* one = onesComplement();
        cout << "1's Complement: ";
        display(one);

        // Compute and display 2's complement.
        Node* two = twosComplement();
        cout << "2's Complement: ";
        display(two);

        return 0;
}

