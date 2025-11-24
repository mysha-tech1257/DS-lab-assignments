#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

// Function to insert an element into BST 
Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d == root->data) {
        cout << "Duplicate value " << d << " not allowed!" << endl;
        return root;
    }

    if (d > root->data)
        root->right = insertIntoBST(root->right, d);
    else
        root->left = insertIntoBST(root->left, d);

    return root;
}

// Function to take input until -1 is entered
void takeInput(Node* &root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

//  Recursive Search Function
bool searchRecursive(Node* root, int key) {
    
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

//  Non-Recursive Search Function
bool searchIterative(Node* root, int key) {
    Node* temp = root;

    while (temp != NULL) {
        if (temp->data == key)
            return true;
        else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return false; 
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    cout << "Enter elements to insert into BST (no duplicates, -1 to stop):" << endl;
    takeInput(root);

    cout << "\nInorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "\nEnter element to search: ";
    cin >> key;

    if (searchRecursive(root, key))
        cout << key << " found (Recursive Search)\n";
    else
        cout << key << " not found (Recursive Search)\n";

    if (searchIterative(root, key))
        cout << key << " found (Iterative Search)\n";
    else
        cout << key << " not found (Iterative Search)\n";

    return 0;
}
