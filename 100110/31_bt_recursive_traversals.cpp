#include <iostream>
#include <algorithm>

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

    void inorder(Node* node) const {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) const {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    int countLeafNodes(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void buildTree() {
        root = createNode(10);
        root->left = createNode(20);
        root->right = createNode(30);
        root->left->left = createNode(40);
        root->left->right = createNode(50);
        root->right->left = createNode(60);
        root->right->right = createNode(70);
        root->left->left->left = createNode(80);
    }

    void displayInorder() const {
        std::cout << "Inorder Traversal: ";
        inorder(root);
        std::cout << std::endl;
    }

    void displayPreorder() const {
        std::cout << "Preorder Traversal: ";
        preorder(root);
        std::cout << std::endl;
    }

    int getNumberOfLeafNodes() const {
        return countLeafNodes(root);
    }
};

int main() {
    BinaryTree tree;
    tree.buildTree();

    std::cout << "Tree Structure: 10 (Root) -> L: 20 (L: 40 [L: 80], R: 50), R: 30 (L: 60, R: 70)" << std::endl;
    
    tree.displayInorder(); 
    tree.displayPreorder(); 
    
    int leafCount = tree.getNumberOfLeafNodes();
    std::cout << "Number of Leaf Nodes: " << leafCount << std::endl;
    
    return 0;
}