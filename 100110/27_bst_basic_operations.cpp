#include <iostream>
#include <queue>
#include <stdexcept>
#include <algorithm>

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

    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteRecursive(Node* node, int data) {
        if (node == nullptr) {
            return node;
        }
        
        if (data < node->data) {
            node->left = deleteRecursive(node->left, data);
        } else if (data > node->data) {
            node->right = deleteRecursive(node->right, data);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data);
        }
        return node;
    }

    void inorderDisplay(Node* node) const {
        if (node != nullptr) {
            inorderDisplay(node->left);
            std::cout << node->data << " ";
            inorderDisplay(node->right);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        std::queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
            delete current;
        }
    }

    void create(int data) {
        root = insertRecursive(root, data);
    }

    void insert(int data) {
        root = insertRecursive(root, data);
    }

    void deleteNode(int data) {
        root = deleteRecursive(root, data);
    }

    void displayInorder() const {
        std::cout << "Inorder Display (Sorted): ";
        inorderDisplay(root);
        std::cout << std::endl;
    }

    void displayLevelwise() const {
        if (root == nullptr) {
            std::cout << "Levelwise Display: Tree is empty." << std::endl;
            return;
        }

        std::cout << "Levelwise Display: ";
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            std::cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    BST tree;

    tree.create(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.displayLevelwise();
    tree.displayInorder();

    std::cout << "\nDeleting 20 (Leaf)" << std::endl;
    tree.deleteNode(20);
    tree.displayLevelwise();

    std::cout << "\nDeleting 70 (One Child)" << std::endl;
    tree.deleteNode(70);
    tree.displayLevelwise();

    tree.insert(90);
    tree.insert(65);
    tree.insert(75);
    tree.insert(72);
    tree.insert(78);
    
    std::cout << "\nTree after re-insertions:" << std::endl;
    tree.displayLevelwise();
    tree.displayInorder();
    
    std::cout << "\nDeleting 30 (Two Children)" << std::endl;
    tree.deleteNode(30);
    tree.displayLevelwise();

    return 0;
}