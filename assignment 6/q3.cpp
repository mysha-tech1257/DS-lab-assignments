// SIZE OF CIRCULAR LINKED LIST

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// int size(Node *&tail)
// {

//     if (tail == NULL)
//     {
//         return 0;
//     }

//     Node *temp = tail;
//     int count = 0;
//     do
//     {
//         count ++;
//         temp = temp->next;

//     } while (temp != tail);

//     return count;
// }
// int main()
// {
//     Node *tail = new Node(20);
//     tail->next = new Node(100);
//     tail->next->next = new Node(40);
//     tail->next->next->next = new Node(80);
//     tail->next->next->next->next = new Node(60);
//     tail->next->next->next->next->next = tail;
//     cout<<" size of circular linked list is : " << size(tail);

//     return 0;
// }


// SIZE OF DOUBLY LINKED LIST

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

int size(Node *head){
    int count = 0;
    Node *temp = head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count ;
}

void print(Node * &head){
    Node *temp = head;

    while(temp!=NULL){
        cout << temp->data<< " " ;
        temp=temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;

    print(head);
    cout << "size of doubly linked list : " << size(head)<< endl;

    return 0;
}

