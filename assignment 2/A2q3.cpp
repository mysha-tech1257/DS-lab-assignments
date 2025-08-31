// #include<iostream>
// using namespace std;

// int missing(int arr[] , int n){
//         for(int i=0; i<n ; i++){
//             if(arr[i]!=i+1){
//                 return i+1;
//             }
//         }
//         return n;
// }

// int main()
// {
//     int arr[5]={1,2,3,4,5};
//     cout<< "missing number is: " << missing(arr , 5);
//     return 0;
// }


#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2; // since size = n-1
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (arr[mid] == mid + 1) {
            // left part is perfect, missing is on right
            low = mid + 1;
        } else {
            // mismatch, missing on left (or at mid)
            high = mid - 1;
        }
    }
    return low+1; 
}

int main() {
    int arr[] = {1, 2, 4, 5, 6}; // 2 is missing
    int n = 6; 
    
    cout << "Missing number (Binary Search) = " << findMissingBinary(arr, n) << endl;
    return 0;
}
 