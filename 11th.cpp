#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BinarySearchTree {
private:
    TreeNode* root;
    TreeNode* insertRecursively(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }
        if (value < root->data) {
            root->left = insertRecursively(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursively(root->right, value);
        }
        return root;
    }
    void inorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
public:
    BinarySearchTree() {
        root = nullptr;
    }
    void insert(int value) {
        root = insertRecursively(root, value);
    }
    void display() {
        inorderTraversal(root);
        cout << endl;
    }
    ~BinarySearchTree() {
        // Perform post-order traversal and delete nodes
        deleteTree(root);
    }
    void deleteTree(TreeNode* root) {
        if (root != nullptr) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }
};
int main() {
    BinarySearchTree bst;
    int choice, value;
    do {
        cout << "\n1. Insert\n2. Display\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Binary Search Tree elements (inorder): ";
                bst.display();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 3);
    return 0;
}