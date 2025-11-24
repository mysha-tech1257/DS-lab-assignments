#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(Node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin>>data;

    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter left child of "<<data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right child of "<<data << endl;
    root->right = buildTree(root->right);
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
};
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
};
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout << "pre-order traversal : " << endl;
    preorder(root);

    cout << "\nin-order traversal : " << endl;
    inorder(root);

    cout << "\npost-order traversal : " << endl;
    postorder(root);

    return 0;
}
