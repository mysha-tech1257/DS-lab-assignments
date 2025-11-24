#include <iostream>
using namespace std;
int n = 100;

class stack
{

    int element[5];
    int top = -1;

public:
    int isFull()
    {
        if (top == 4)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "stack Overflow" << endl;
        }
        else
        {
            top++;
            element[top] = x;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << " Stack is empty " << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << element[i] << endl;
            }
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            cout << " The top element is : " << element[top] << endl;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            cout << " The poped element is : " << element[top] << endl;
            top--;
        }
    }
};

int main()
{
    stack S;
    int choice, value;
    do
    {
        cout << "\n --- Stack Menu ---" << endl;
        cout << " 1. Push " << endl;
        cout << " 2. Pop " << endl;
        cout << " 3. Peek " << endl;
        cout << " 4. Display" << endl;
        cout << " 5. Exit" << endl;
        cout << " Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int count;
            cout << " How many numbers do you want to push ? " << endl;
            cin >> count;
            for(int i=0; i<count; i++){
                cout << " Enter value " << i+1 <<" : " << endl;
                cin>> value ;
                 S.push(value);
            }
            break;

        case 2:
            S.pop();
            break;

        case 3:
            S.peek();
            break;

        case 4:
            cout << " stack is : ";
            S.display();
            break;

        case 5:
            cout << " --- Exiting Program --- " << endl;
            break;

        default:
            cout << " Invalid choice ! Try Again " << endl;
        }
    } while (choice != 5);

    return 0;
}