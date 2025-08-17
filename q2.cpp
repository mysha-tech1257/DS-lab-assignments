// #include<iostream>
// using namespace std;
// int main(){
//     int n=10;
//     int arr[10]={1,6,0,1,0,3,6,6,0,3};
//     for(int i=0; i<n;i++){
//         for(int j=i+1;j<n;){
//             if(arr[i]==arr[j]){
//                 for(int k=j;k<10;k++){
//                     arr[k]=arr[k+1];
//                 }
//                 n--;
//             }
//             else{
//                 j++;
//             }
//         }
//     }
//     cout << " final array after removing duplicates is : " ;
//     for(int i=0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int arr[10] = {1, 6, 0, 1, 0, 3, 6, 6, 0, 3};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
                arr[j] = arr[n - 1];
                n--;
            }
            else
            {
                j++;
            }
        }
    }
    cout << " final array after removing duplicates is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}