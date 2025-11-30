/*WAP to perform addition of two polynomials using singly linked list.*/

#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

void insert(Node*& head, int c, int p) {
    Node* t = new Node(c, p);
    if (!head) {
        head = t;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = t;
}

void display(Node* head) {
    Node* t = head;
    while (t) {
        cout << t->coeff << "x^" << t->pow;
        if (t->next) cout << " + ";
        t = t->next;
    }
    cout << endl;
}

Node* addPoly(Node* p1, Node* p2) {
    Node* res = NULL;
    while (p1 && p2) {
        if (p1->pow == p2->pow) {
            insert(res, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow) {
            insert(res, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else {
            insert(res, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1) {
        insert(res, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        insert(res, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return res;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int n, c, p;

    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> p;
        insert(poly1, c, p);
    }

    cout << "Enter number of terms in Polynomial 2: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> p;
        insert(poly2, c, p);
    }

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* result = addPoly(poly1, poly2);

    cout << "Resultant Polynomial: ";
    display(result);

    return 0;
}
