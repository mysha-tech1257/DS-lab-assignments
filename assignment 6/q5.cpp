#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *prev;
    Node *next;
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isCircular(Node* head){
    if(head == NULL)
    return false;

    Node *temp = head->next;

    while(temp!=NULL && temp != head){
        temp = temp->next;
    }

    return (temp == head);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;


    if(isCircular(head)){ 
        cout << " is circular "<< endl;
    }
    else{
        cout << "not circular " << endl;
    }
    return 0;
}