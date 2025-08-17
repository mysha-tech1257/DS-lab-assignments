#include <iostream>
using namespace std;
void reverse(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int arr[5] = {2, 4, 6, 8, 0};
    reverse(arr,5);
    cout << " reversed array: ";
    for(int i=0;i<5;i++){
        cout <<  arr[i] << " " ;
    }
    return 0;
}