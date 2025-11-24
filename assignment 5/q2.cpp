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

int no_of_occurances(Node *head, int key)
{
    if (head == NULL)
    {
        return 0;
    }
    /* if(head->next==NULL){      (no need to handle this case separately)
            return 1;
     } */
    Node *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);
    print(head);
    int key = 1;
    // cout << "Occurances of "<< key << " = "  << no_of_occurances(head,1) << endl;
    cout << no_of_occurances(head, key);
    return 0;
}