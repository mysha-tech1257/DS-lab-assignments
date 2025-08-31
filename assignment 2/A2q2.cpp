// bubble sort 

#include<iostream>
using namespace std;

int bsort(int arr[] , int n ){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
            
        }
    }
}

int main()
{
    int arr[7]={64,43,25,12,22,11,90};
    bsort(arr , 7);
    cout << " sorted array is : " << endl;
    for(int i=0; i<7; i++){
        cout << arr[i] << " " ;
    }

    return 0;
}