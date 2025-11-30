#include <iostream>
#include <stdexcept>

struct Node {
    int price;
    Node* next;
};

class StockTracker {
private:
    Node* top;

public:
    StockTracker() {
        top = nullptr;
    }

    ~StockTracker() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void record(int price) {
        Node* newNode = new Node{price, top};
        top = newNode;
        std::cout << "Recorded: $" << price << std::endl;
    }

    int remove() {
        if (isEmpty()) {
            throw std::out_of_range("Stack Underflow: History is empty.");
        }
        
        Node* temp = top;
        int removedPrice = temp->price;
        top = temp->next;
        delete temp;
        
        std::cout << "Removed (Pop): $" << removedPrice << std::endl;
        return removedPrice;
    }

    int latest() const {
        if (isEmpty()) {
            throw std::out_of_range("History is empty.");
        }
        return top->price;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "History: [Empty]" << std::endl;
            return;
        }
        
        std::cout << "History (Recent to Oldest): ";
        Node* current = top;
        while (current != nullptr) {
            std::cout << "$" << current->price << (current->next ? " -> " : "");
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    StockTracker tracker;

    tracker.record(100);
    tracker.record(105);
    tracker.record(98);
    tracker.display();

    try {
        std::cout << "Latest price (Peek): $" << tracker.latest() << std::endl;

        tracker.remove();
        tracker.display();

        std::cout << "Is empty? " << (tracker.isEmpty() ? "Yes" : "No") << std::endl;
        
        tracker.remove();
        tracker.remove();
        
        std::cout << "Is empty? " << (tracker.isEmpty() ? "Yes" : "No") << std::endl;
        
        tracker.remove();
        
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}