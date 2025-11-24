#include <iostream>
#include<queue>
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

void levelOrderTraversal(Node *root)
{
    queue< Node * > q ;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp==NULL){
            cout << endl;

            if(!q.empty()){
              q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node *minVal(Node *root){
    Node *temp = root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node *deletefromBST(Node * root,int val)
{
    //base case
    if(root==NULL){
        return root;
    }
    // 0 child
    if(root->data == val){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right!=NULL){
            int mini = minVal(root->right)->data;
            root->data=mini;
            root->right=deletefromBST(root->right,mini);
            return root;
        }

    }
}
int main(){
    Node* root = NULL;
    cout << " enter data to create BST: " << endl;
    takeInput(root);

    levelOrderTraversal(root);

    //root = deletefromBST(root,30);

    // cout<<"printing BST after deletion: " << endl;
    // levelOrderTraversal(root);

    return 0;
}