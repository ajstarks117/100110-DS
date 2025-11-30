#include <iostream>
#include <vector>
#include <stdexcept>

class KStacks {
private:
    int* arr;
    int* top;
    int* next;
    int n;
    int k;
    int free;

public:
    KStacks(int k_stacks, int array_size) {
        k = k_stacks;
        n = array_size;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        free = 0;

        for (int i = 0; i < k; i++) {
            top[i] = -1;
        }

        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    ~KStacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }

    bool isFull() const {
        return free == -1;
    }

    bool isEmpty(int sn) const {
        return top[sn] == -1;
    }

    void push(int item, int sn) {
        if (isFull()) {
            std::cout << "Stack Overflow (Array is full)" << std::endl;
            return;
        }

        int i = free;
        free = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = item;
    }

    int pop(int sn) {
        if (isEmpty(sn)) {
            throw std::runtime_error("Stack Underflow (Stack is empty)");
        }

        int i = top[sn];
        top[sn] = next[i];
        next[i] = free;
        free = i;

        return arr[i];
    }

    void display(int sn) {
        if (isEmpty(sn)) {
            std::cout << "Stack " << sn << " (Top to Bottom): [Empty]" << std::endl;
            return;
        }

        std::vector<int> stackElements;
        int current = top[sn];
        while (current != -1) {
            stackElements.push_back(arr[current]);
            current = next[current];
        }

        std::cout << "Stack " << sn << " (Top to Bottom): [";
        for (size_t i = 0; i < stackElements.size(); ++i) {
            std::cout << stackElements[i];
            if (i < stackElements.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    int k = 3;
    int n = 10;
    KStacks ks(k, n);

    ks.push(10, 0);
    ks.push(20, 0);
    ks.push(30, 1);
    ks.push(40, 2);
    ks.push(50, 2);
    ks.push(60, 0);
    ks.push(70, 1);

    ks.display(0);
    ks.display(1);
    ks.display(2);
    
    try {
        std::cout << "Popped from Stack 0: " << ks.pop(0) << std::endl;
        std::cout << "Popped from Stack 2: " << ks.pop(2) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    ks.display(0);
    ks.display(2);

    return 0;
}