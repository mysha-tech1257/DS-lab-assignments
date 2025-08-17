#include <iostream>
using namespace std;
int main()
{
    int m;
    int n;
    int p;
    cout << " Enter no. of rows and columns for matrix 1: ";
    cin >> m >> n;
    int A[m][n], B[n][m]  ;
    cout << " Enter elements of matrix A : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    // matrix transpose
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[j][i] = A[i][j];
        }
    }
    cout << " transpose of matrix A is : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<< B[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
