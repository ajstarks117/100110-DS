#include <iostream>
#include <string>
#include <stdexcept>

const int MAX_ORDERS = 5;

class PizzaParlour {
private:
    std::string orders[MAX_ORDERS];
    int front;
    int rear;

public:
    PizzaParlour() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (rear + 1) % MAX_ORDERS == front;
    }

    void placeOrder(std::string orderDetails) {
        if (isFull()) {
            std::cout << "Stack Overflow: Maximum orders reached. Please wait." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_ORDERS;
        }
        
        orders[rear] = orderDetails;
        std::cout << "Order placed: " << orderDetails << std::endl;
    }

    void serveOrder() {
        if (isEmpty()) {
            std::cout << "Stack Underflow: No orders to serve." << std::endl;
            return;
        }

        std::string servedOrder = orders[front];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_ORDERS;
        }

        std::cout << "Order served (FCFS): " << servedOrder << std::endl;
    }

    void displayOrders() const {
        if (isEmpty()) {
            std::cout << "Current queue: [Empty]" << std::endl;
            return;
        }

        std::cout << "Current queue (Front to Rear): [";
        int i = front;
        
        do {
            std::cout << orders[i];
            if (i != rear) {
                std::cout << ", ";
            }
            i = (i + 1) % MAX_ORDERS;
        } while (i != (rear + 1) % MAX_ORDERS);
        
        std::cout << "]" << std::endl;
    }
};

int main() {
    PizzaParlour parlour;

    parlour.placeOrder("Large Pepperoni");
    parlour.placeOrder("Medium Veggie");
    parlour.placeOrder("Small Cheese");
    parlour.displayOrders();

    parlour.serveOrder();
    parlour.displayOrders();

    parlour.placeOrder("Two Cokes and Salad");
    parlour.placeOrder("Family Deal");
    parlour.placeOrder("Extra Large Supreme");
    parlour.displayOrders();
    
    parlour.placeOrder("This order should overflow");

    parlour.serveOrder();
    parlour.placeOrder("New Order after serving");
    parlour.displayOrders();

    parlour.serveOrder();
    parlour.serveOrder();
    parlour.serveOrder();
    parlour.serveOrder();
    
    parlour.serveOrder();

    return 0;
}