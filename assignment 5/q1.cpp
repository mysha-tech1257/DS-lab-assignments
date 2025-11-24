#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;
void InsertAtHead(int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    if (tail == NULL) tail = head; 
}

void InsertAtEnd(int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertAfter(int key, int d) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Key not found.\n";
        return;
    }
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail) tail = newNode;
}

void insertBefore(int key, int d) {
    if (head == NULL) return;

    if (head->data == key) {
        InsertAtHead(d);
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Key not found.\n";
        return;
    }

    Node* newNode = new Node(d);
    prev->next = newNode;
    newNode->next = curr;
}

void deleteBeginning() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) return;

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != tail) temp = temp->next;

    delete tail;
    tail = temp;
    tail->next = NULL;
}

void deleteNode(int key) {
    if (head == NULL) return;

    if (head->data == key) {
        deleteBeginning();
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Node not found.\n";
        return;
    }

    prev->next = curr->next;
    if (curr == tail) tail = prev;
    delete curr;
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found.\n";
}

void display() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, key;
    do {
        cout << "\nSingly Linked List Menu\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                InsertAtHead(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                InsertAtEnd(value);
                break;

            case 3:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                insertAfter(key, value);
                break;

            case 4:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                insertBefore(key, value);
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteNode(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 9:
                display();
                break;

            case 0:
                cout << "Exiting.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
