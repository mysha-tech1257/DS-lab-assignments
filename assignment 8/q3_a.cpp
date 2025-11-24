#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d == root->data) {
        cout << "Duplicate value " << d << " not allowed!" << endl;
        return root;
    }
    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    }
    else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Inorder traversal (to check tree structure)
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

    cout << "\nInorder Traversal of BST (sorted order):" << endl;
    inorder(root);

    return 0;
}
