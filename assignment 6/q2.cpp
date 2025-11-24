#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void display(Node *&tail)
{

    if (tail == NULL)
    {
        cout << " list is empty " << endl;
    }

    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << tail->data;
    cout << endl;
}

int main()
{
    Node *tail = new Node(20);
    tail->next = new Node(100);
    tail->next->next = new Node(40);
    tail->next->next->next = new Node(80);
    tail->next->next->next->next = new Node(60);
    tail->next->next->next->next->next = tail;
    display(tail);

    return 0;
}