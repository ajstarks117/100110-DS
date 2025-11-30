#include <iostream>
#include <stdexcept>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insertRecursive(Node* node, int data) {
        if (node == nullptr) {
            return createNode(data);
        }
        if (data < node->data) {
            node->left = insertRecursive(node->left, data);
        } else if (data > node->data) {
            node->right = insertRecursive(node->right, data);
        }
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertRecursive(root, data);
    }

    int findMinimum() const {
        if (root == nullptr) {
            throw std::runtime_error("BST is empty");
        }
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }

    int findMaximum() const {
        if (root == nullptr) {
            throw std::runtime_error("BST is empty");
        }
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }
};

int main() {
    BST tree;

    tree.insert(60);
    tree.insert(40);
    tree.insert(80);
    tree.insert(20);
    tree.insert(50);
    tree.insert(70);
    tree.insert(90);
    
    try {
        std::cout << "Tree elements inserted: 60, 40, 80, 20, 50, 70, 90" << std::endl;
        
        int minVal = tree.findMinimum();
        std::cout << "Minimum value in BST: " << minVal << std::endl; 

        int maxVal = tree.findMaximum();
        std::cout << "Maximum value in BST: " << maxVal << std::endl; 
        
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}