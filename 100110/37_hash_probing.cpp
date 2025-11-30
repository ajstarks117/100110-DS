#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
    int arr[SIZE];
    bool used[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = -1;
            used[i] = false;
        }
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        int start = index;
        while (used[index]) {
            index = (index + 1) % SIZE;
            if (index == start) return;
        }
        arr[index] = key;
        used[index] = true;
    }

    void searchKey(int key) {
        int index = hashFunction(key);
        int start = index;
        while (used[index]) {
            if (arr[index] == key) {
                cout << "Key found at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        cout << "Key not found" << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            if (used[i]) cout << i << " : " << arr[i] << endl;
            else cout << i << " : empty" << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;
    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter key: ";
            cin >> key;
            ht.insertKey(key);
        } else if (choice == 2) {
            cout << "Enter key to search: ";
            cin >> key;
            ht.searchKey(key);
        } else if (choice == 3) {
            ht.display();
        }
    } while (choice != 4);
}
