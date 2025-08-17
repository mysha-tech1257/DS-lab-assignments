#include <iostream>
using namespace std;
int main()
{
    int m;
    int n;
    int i = 0;
    cout << " Enter no. of rows and columns for matrix 1: ";
    cin >> m >> n;
    int A[m][n], B[m][n];
    cout << " Enter elements of matrix A : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    while (i < 2)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += A[i][j];
        }
        cout << "sum of " <<i<< "th row is : " << sum << endl;
        i++;
    }

    return 0;
}