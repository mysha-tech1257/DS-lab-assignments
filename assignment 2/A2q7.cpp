#include <iostream>
using namespace std;

int countinversions(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)      // no need to check the last element so we can run the loop till i<n-1
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[4] = {3, 2, 1, 6};
    cout << "total number of inversions are: "  << countinversions(arr, 4);

    return 0;
}