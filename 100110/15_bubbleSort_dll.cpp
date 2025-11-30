/*Implement Bubble sort using Doubly Linked List*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) { data = d; prev = next = NULL; }
};

Node* head = NULL;

void append(int d) {
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

void display() {
    Node* t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int length() {
    int c = 0;
    Node* t = head;
    while (t) {
        c++;
        t = t->next;
    }
    return c;
}

void bubbleSort() {
    if (!head) return;
    int n = length();
    for (int i = 0; i < n - 1; i++) {
        Node* t = head;
        for (int j = 0; j < n - 1 - i; j++) {
            if (t->data > t->next->data) {
                int temp = t->data;
                t->data = t->next->data;
                t->next->data = temp;
            }
            t = t->next;
        }
    }
}

int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        append(x);
    }

    cout << "Original List: ";
    display();

    bubbleSort();

    cout << "Sorted List: ";
    display();

    return 0;
}
