// using nested loops O(n^2)

// #include <iostream>
// using namespace std;

// int countdistinct(int arr[], int n)
// {
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         bool isDuplicate = false;
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 isDuplicate = true;
//                 break;
//             }
//         }
//            if(!isDuplicate)
//         {
//             count++;
//         }
//     }
//      return count;
    
// }

// int main()
// {
//     int arr[7] = {1, 3, 4, 1, 4, 4, 3};
//     int res = countdistinct(arr, 7);
//     cout << res << endl;
//     return 0;
// }


// using  sorting  O(n log n)

#include <iostream>
#include <algorithm>  // for sort
using namespace std;

int countDistinct(int arr[], int n) {
    // Step 1: Sort the array
    sort(arr, arr + n);

    int count = 1; // first element is always distinct

    // Step 2: Traverse sorted array
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[7] = {1, 3, 4, 1, 4, 4, 3};
    int res = countDistinct(arr, 7);
    cout << "Number of distinct elements: " << res << endl;
    return 0;
}
