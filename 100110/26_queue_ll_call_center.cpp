#include <iostream>
#include <string>

struct CallNode {
    std::string customerName;
    CallNode* next;
};

class CallQueue {
private:
    CallNode* front;
    CallNode* rear;

public:
    CallQueue() {
        front = nullptr;
        rear = nullptr;
    }

    ~CallQueue() {
        while (!isEmpty()) {
            dequeueCall();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueueCall(std::string name) {
        CallNode* newNode = new CallNode();
        newNode->customerName = name;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Call Enqueued: " << name << " is now waiting." << std::endl;
    }

    void dequeueCall() {
        if (isEmpty()) {
            std::cout << "No calls currently waiting. Agent is available." << std::endl;
            return;
        }

        CallNode* temp = front;
        std::string customerName = temp->customerName;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        std::cout << "Call Dequeued: Agent assisting " << customerName << "." << std::endl;
    }

    void displayQueue() const {
        if (isEmpty()) {
            std::cout << "Current Queue: [Empty]" << std::endl;
            return;
        }

        std::cout << "Current Queue (Front to Rear): [";
        CallNode* current = front;
        while (current != nullptr) {
            std::cout << current->customerName;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    CallQueue centerQueue;

    std::cout << "--- Customer Calls Arrive ---" << std::endl;
    centerQueue.enqueueCall("Mark");
    centerQueue.enqueueCall("Sarah");
    centerQueue.enqueueCall("David");

    centerQueue.displayQueue();

    std::cout << "\n--- Agent Becomes Available (Dequeue) ---" << std::endl;
    centerQueue.dequeueCall();
    
    centerQueue.enqueueCall("Emily");

    centerQueue.displayQueue();

    std::cout << "\n--- Clearing the Queue ---" << std::endl;
    centerQueue.dequeueCall();
    centerQueue.dequeueCall();
    
    centerQueue.displayQueue();

    std::cout << "\n--- Last Call ---" << std::endl;
    centerQueue.dequeueCall();
    
    centerQueue.dequeueCall();

    return 0;
}