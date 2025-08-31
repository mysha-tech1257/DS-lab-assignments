#include <iostream>
using namespace std;
int bsearch(int arr[] , int n , int key){
    //int n;
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    //int key = 82;
     while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int arr[6] = {2, 3, 8, 65, 82, 95};
    cout<<"index of key is: " << bsearch(arr,6,8);
    return 0;
}