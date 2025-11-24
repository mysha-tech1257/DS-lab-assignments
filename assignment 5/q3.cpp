#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node *reverseLinkedlist(Node *head){
    // if list is empty or has only one element 
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void print(Node * &head){
    Node *temp = head;
    while(temp != NULL){
        cout <<  temp->data << " " ;
        temp = temp -> next ;
    }
    cout << endl;
}

int main(){
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << " original list : " << endl;
    print(head);
    cout << " reversed list : " << endl;
    head = reverseLinkedlist(head);
    print(head);
    return 0;
}