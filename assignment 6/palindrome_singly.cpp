#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node *next ;
    Node(char data){
        this->data=data;
        this->next=NULL;
    }
};



Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    // Step 1: Find middle using slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //return slow;

    // Step 2: Reverse the second half
    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;

    // Step 3: Compare both halves
    Node* temp2 = secondHalf;
    bool palindrome = true;
    while (temp2 != NULL) {
        if (firstHalf->data != temp2->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp2 = temp2->next;
    }

     // Step 4 (optional): Restore the list
    slow->next = reverseList(secondHalf);

    return palindrome;
}
int main()
{
    Node* head = new Node('R');
    head->next = new Node('A');
    head->next->next = new Node('D');
    head->next->next->next = new Node('A');
    head->next->next->next->next = new Node('R');


    if (isPalindrome(head))
        cout << "The singly linked list is a palindrome." << endl;
    else
        cout << "The singly linked list is NOT a palindrome." << endl;

    return 0;
}