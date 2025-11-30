#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root;

    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void buildTree() {
        root = createNode(1);
        root->left = createNode(2);
        root->right = createNode(3);
        root->left->left = createNode(4);
        root->left->right = createNode(5);
        root->right->left = createNode(6);
        root->right->right = createNode(7);
    }

    void inorderNonRecursive() const {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        std::stack<Node*> s;
        Node* current = root;

        std::cout << "Inorder Traversal (Non-recursive): ";
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            
            current = s.top();
            s.pop();
            
            std::cout << current->data << " ";
            
            current = current->right;
        }
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.buildTree();
    
    tree.inorderNonRecursive(); 
    
    return 0;
}