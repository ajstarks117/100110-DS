#include <iostream>
#include <string>
#include <stdexcept>

const int MAX_SIZE = 10;

class TwoQueues {
private:
    int arr[MAX_SIZE];
    int q1_front;
    int q1_rear;
    int q2_front;
    int q2_rear;

public:
    TwoQueues() {
        q1_front = -1;
        q1_rear = -1;
        q2_front = MAX_SIZE;
        q2_rear = MAX_SIZE;
    }

    bool isFull() const {
        return q1_rear + 1 == q2_rear;
    }

    bool isEmpty(int queueNum) const {
        if (queueNum == 1) {
            return q1_front == -1;
        } else if (queueNum == 2) {
            return q2_front == MAX_SIZE;
        }
        return true;
    }

    void addQueue(int element, int queueNum) {
        if (isFull()) {
            std::cout << "Queue Overflow: The shared array is full." << std::endl;
            return;
        }

        if (queueNum == 1) {
            if (q1_front == -1) {
                q1_front = 0;
            }
            q1_rear++;
            arr[q1_rear] = element;
            std::cout << "Added " << element << " to Queue 1." << std::endl;
        } else if (queueNum == 2) {
            if (q2_front == MAX_SIZE) {
                q2_front = MAX_SIZE - 1;
            }
            q2_rear--;
            arr[q2_rear] = element;
            std::cout << "Added " << element << " to Queue 2." << std::endl;
        } else {
            std::cout << "Invalid queue number." << std::endl;
        }
    }

    int deleteFromQueue(int queueNum) {
        if (isEmpty(queueNum)) {
            std::cout << "Queue Underflow: Queue " << queueNum << " is empty." << std::endl;
            return -1;
        }

        int deletedElement = -1;

        if (queueNum == 1) {
            deletedElement = arr[q1_front];
            if (q1_front == q1_rear) {
                q1_front = -1;
                q1_rear = -1;
            } else {
                q1_front++;
            }
        } else if (queueNum == 2) {
            deletedElement = arr[q2_front];
            if (q2_front == q2_rear) {
                q2_front = MAX_SIZE;
                q2_rear = MAX_SIZE;
            } else {
                q2_front--;
            }
        }
        
        std::cout << "Deleted " << deletedElement << " from Queue " << queueNum << "." << std::endl;
        return deletedElement;
    }

    void displayQueue(int queueNum) const {
        if (isEmpty(queueNum)) {
            std::cout << "Queue " << queueNum << ": [Empty]" << std::endl;
            return;
        }

        std::cout << "Queue " << queueNum << " (Front to Rear): [";
        if (queueNum == 1) {
            for (int i = q1_front; i <= q1_rear; i++) {
                std::cout << arr[i] << (i == q1_rear ? "" : ", ");
            }
        } else if (queueNum == 2) {
            for (int i = q2_front; i >= q2_rear; i--) {
                std::cout << arr[i] << (i == q2_rear ? "" : ", ");
            }
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    TwoQueues tq;
    
    std::cout << "--- Initial State ---" << std::endl;
    tq.displayQueue(1);
    tq.displayQueue(2);

    tq.addQueue(10, 1);
    tq.addQueue(20, 1);
    tq.addQueue(90, 2);
    tq.addQueue(80, 2);
    tq.addQueue(30, 1);
    tq.addQueue(70, 2);

    std::cout << "\n--- Current Queues ---" << std::endl;
    tq.displayQueue(1);
    tq.displayQueue(2);

    std::cout << "\n--- Deleting ---" << std::endl;
    tq.deleteFromQueue(1);
    tq.deleteFromQueue(2);
    
    std::cout << "\n--- After Deleting ---" << std::endl;
    tq.displayQueue(1);
    tq.displayQueue(2);
    
    tq.addQueue(40, 1);
    tq.addQueue(60, 2);
    
    tq.addQueue(50, 1);
    tq.addQueue(55, 2);
    
    std::cout << "\n--- Max Capacity Test ---" << std::endl;
    tq.addQueue(99, 1);
    
    return 0;
}