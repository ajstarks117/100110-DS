/*In the Second Year Computer Engineering class, there are two groups of students based on their favorite sports:
●	Set A includes students who like Cricket.
●	Set B includes students who like Football.
Write a C++ program to represent these two sets using linked lists and perform the following operations:
a) Find and display the set of students who like both Cricket and Football.
 b) Find and display the set of students who like either Cricket or Football, but not both.
 c) Display the number of students who like neither Cricket nor Football.
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node(string n) { name = n; next = NULL; }
};

void insert(Node*& head, string name) {
    Node* p = new Node(name);
    p->next = head;
    head = p;
}

bool search(Node* head, string name) {
    Node* t = head;
    while(t) {
        if(t->name == name) return true;
        t = t->next;
    }
    return false;
}

void display(Node* head) {
    Node* t = head;
    while(t) {
        cout << t->name << " ";
        t = t->next;
    }
    cout << endl;
}

void intersection(Node* A, Node* B) {
    cout << "\nStudents who like BOTH Cricket & Football:\n";
    Node* t = A;
    bool found = false;
    while(t) {
        if(search(B, t->name)) {
            cout << t->name << " ";
            found = true;
        }
        t = t->next;
    }
    if(!found) cout << "None";
    cout << endl;
}

void symmetricDiff(Node* A, Node* B) {
    cout << "\nStudents who like EITHER Cricket or Football BUT NOT both:\n";
    Node* t = A;
    bool found = false;

    while(t) {
        if(!search(B, t->name)) {
            cout << t->name << " ";
            found = true;
        }
        t = t->next;
    }

    t = B;
    while(t) {
        if(!search(A, t->name)) {
            cout << t->name << " ";
            found = true;
        }
        t = t->next;
    }

    if(!found) cout << "None";
    cout << endl;
}

int countList(Node* head) {
    int c = 0;
    while(head) {
        c++;
        head = head->next;
    }
    return c;
}

int main() {
    Node* A = NULL;
    Node* B = NULL;

    int nA, nB, total;
    cout << "Enter total number of students in class: ";
    cin >> total;

    cout << "Enter number of students who like Cricket: ";
    cin >> nA;

    cout << "Enter names:\n";
    for(int i = 0; i < nA; i++) {
        string name;
        cin >> name;
        insert(A, name);
    }

    cout << "Enter number of students who like Football: ";
    cin >> nB;

    cout << "Enter names:\n";
    for(int i = 0; i < nB; i++) {
        string name;
        cin >> name;
        insert(B, name);
    }

    cout << "\nSet A (Cricket): ";
    display(A);

    cout << "Set B (Football): ";
    display(B);

    intersection(A, B);
    symmetricDiff(A, B);

    int countA = countList(A);
    int countB = countList(B);

    int both = 0;
    Node* t = A;
    while(t) {
        if(search(B, t->name)) both++;
        t = t->next;
    }

    int either = countA + countB - both;
    int neither = total - either;

    cout << "\nNumber of students who like NEITHER Cricket nor Football: " << neither << endl;

    return 0;
}
