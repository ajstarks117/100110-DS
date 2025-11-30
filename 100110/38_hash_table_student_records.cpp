#include <iostream>
using namespace std;

const int SIZE = 10;

struct Student {
    int roll;
    string name;
    bool occupied;
};

class HashTable {
    Student table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) table[i].occupied = false;
    }

    int hashFunction(int roll) {
        return roll % SIZE;
    }

    void insertRecord(int roll, string name) {
        int index = hashFunction(roll);
        int start = index;
        while (table[index].occupied) {
            index = (index + 1) % SIZE;
            if (index == start) return;
        }
        table[index].roll = roll;
        table[index].name = name;
        table[index].occupied = true;
    }

    void searchRecord(int roll) {
        int index = hashFunction(roll);
        int start = index;
        while (table[index].occupied) {
            if (table[index].roll == roll) {
                cout << "Record found: Roll = " << table[index].roll << ", Name = " << table[index].name << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        cout << "Record not found" << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << i << " : " << table[i].roll << " " << table[i].name << endl;
            else
                cout << i << " : empty" << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, roll;
    string name;
    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter roll and name: ";
            cin >> roll >> name;
            ht.insertRecord(roll, name);
        } else if (choice == 2) {
            cout << "Enter roll to search: ";
            cin >> roll;
            ht.searchRecord(roll);
        } else if (choice == 3) {
            ht.display();
        }
    } while (choice != 4);
}
