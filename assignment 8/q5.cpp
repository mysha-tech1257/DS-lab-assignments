#include <iostream>
using namespace std;

void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right <= n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapifyMin(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapifyMax(arr, n, i);
    }
}

void buildMinHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapifyMin(arr, n, i);
    }
}

void heapsortIncreasing(int arr[], int n)
{
    buildMaxHeap(arr , n);

    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapifyMax(arr, size, 1);
    }
}

void heapsortDecreasing(int arr[], int n)
{
    buildMinHeap(arr , n);
    
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapifyMin(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    int choice;
    cout << " 1=increasing order and 2=decreasing order: ";
    cin >> choice;

    if (choice == 1)
        heapsortIncreasing(arr, n);
    else
        heapsortDecreasing(arr, n);

    cout << "printing the sorted array: " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;

    return 0;
}