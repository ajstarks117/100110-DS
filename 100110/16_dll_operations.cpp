/*WAP to create a doubly linked list and perform following operations on it. A) Insert (all cases) 2. Delete (all cases).*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) { data = d; prev = next = NULL; }
};

Node* head = NULL;

void insertBegin(int d) {
    Node* p = new Node(d);
    if (!head) {
        head = p;
        return;
    }
    p->next = head;
    head->prev = p;
    head = p;
}

void insertEnd(int d) {
    Node* p = new Node(d);
    if (!head) {
        head = p;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = p;
    p->prev = t;
}

void insertPos(int d, int pos) {
    if (pos == 1) {
        insertBegin(d);
        return;
    }
    Node* t = head;
    for (int i = 1; i < pos - 1 && t; i++)
        t = t->next;
    if (!t) return;
    Node* p = new Node(d);
    p->next = t->next;
    p->prev = t;
    if (t->next) t->next->prev = p;
    t->next = p;
}

void deleteBegin() {
    if (!head) return;
    Node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete t;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->prev->next = NULL;
    delete t;
}

void deletePos(int pos) {
    if (!head) return;
    if (pos == 1) {
        deleteBegin();
        return;
    }
    Node* t = head;
    for (int i = 1; i < pos && t; i++)
        t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

void display() {
    Node* t = head;
    while(t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int ch, val, pos;

    while (true) {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n";
        cout << "4.Delete from Beginning\n5.Delete from End\n6.Delete from Position\n";
        cout << "7.Display\n8.Exit\nEnter choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cin >> val;
                insertBegin(val);
                break;
            case 2:
                cin >> val;
                insertEnd(val);
                break;
            case 3:
                cin >> val >> pos;
                insertPos(val, pos);
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                cin >> pos;
                deletePos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
        }
    }
}

