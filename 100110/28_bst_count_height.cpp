#include <iostream>
#include <algorithm>
#include <queue>

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

    int countNodesRecursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodesRecursive(node->left) + countNodesRecursive(node->right);
    }

    int computeHeightRecursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = computeHeightRecursive(node->left);
        int rightHeight = computeHeightRecursive(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertRecursive(root, data);
    }

    int countTotalNodes() const {
        return countNodesRecursive(root);
    }

    int computeHeight() const {
        return computeHeightRecursive(root);
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(90);

    std::cout << "Tree created: 50, 30, 70, 20, 40, 60, 80, 90" << std::endl;
    
    int totalNodes = tree.countTotalNodes();
    std::cout << "Total number of nodes: " << totalNodes << std::endl;
    
    int height = tree.computeHeight();
    std::cout << "Height of the BST: " << height << std::endl;
    
    std::cout << "\nInserting 10 (changes height)" << std::endl;
    tree.insert(10);
    
    totalNodes = tree.countTotalNodes();
    std::cout << "New total number of nodes: " << totalNodes << std::endl;
    
    height = tree.computeHeight();
    std::cout << "New height of the BST: " << height << std::endl;

    return 0;
}