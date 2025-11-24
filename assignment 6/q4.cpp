#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node *prev;
    Node *next;
    Node(char data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void insertAtEnd(Node * &head , Node * &tail , char data){
    Node * newnode = new Node(data);
    if(head==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void display(Node * &head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(Node *head , Node *tail){
    while(head!=NULL && tail!=NULL && head!=tail && tail->next!=head){
        if(head->data != tail->data){
            return false;
            head=head->next;
            tail=tail->prev;
        }
        return true;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    //Node *head = new Node('M');

    string str = "LEVEL";
    for(char ch : str){
        insertAtEnd(head , tail , ch);
    }

    cout << " Doubly linked list : " << endl;
    display(head);

    if(isPalindrome(head , tail))
    cout <<" the LL is  a palindrome " << endl;
    else
    cout << " the LL is NOT  a palindrome " << endl;

    return 0;
}