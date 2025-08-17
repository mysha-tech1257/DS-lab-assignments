#include <iostream>
using namespace std;

const int SIZE = 100;
int arr[SIZE];
int n = 0;

int option() {
    cout << "\nChoose an operation:" << endl;
    cout << "1. CREATE" << endl;
    cout << "2. DISPLAY" << endl;
    cout << "3. INSERT" << endl;
    cout << "4. DELETE" << endl;
    cout << "5. LINEAR SEARCH" << endl;
    cout << "6. EXIT" << endl;
    cout << "Choose a number: ";
    int op;
    cin >> op;
    return op;
}

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully!\n";
}

void display() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    if (n >= SIZE) {
        cout << "Array is full, cannot insert more elements.\n";
        return;
    }
    int pos, val;
    cout << "Enter position to insert (0 to " << n << "): ";
    cin >> pos;
    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> val;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    cout << "Element inserted successfully.\n";
}

void del() {
    if (n == 0) {
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (0 to " << n - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted successfully.\n";
}

void lsearch() {
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Value found at index " << i << endl;
            return;
        }
    }
    cout << "Value not found in array.\n";
}

int main() {
    while (true) {
        int opt = option();

        switch (opt) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                del();
                break;
            case 5:
                lsearch();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    }
}