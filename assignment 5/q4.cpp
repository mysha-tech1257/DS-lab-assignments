#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node *getMiddle(Node *head){
    if( head==NULL || head->next==NULL ){
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while( fast!=NULL ){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

void print(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout << temp->data << " " ;
        temp=temp->next;
    }
    cout << endl;
}

Node *printMiddle(Node *head){
    return getMiddle(head);
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << " original list: " << endl;
    print(head);

    cout<<"middle of the list : " << endl;
    Node *mid = printMiddle(head);
    cout << mid->data << endl;
    return 0;
}