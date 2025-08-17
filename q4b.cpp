#include <iostream>
using namespace std;
int main()
{
    int m;
    int n;
    int p;
    cout << " Enter no. of rows and columns for matrix 1: " << m << n;
    cin >> m >> n;
    cout << " Enter no. of columns for matrix 2: " << p;
    cin >> p;
    int A[m][n], B[n][p], C[m][p];
    cout << " Enter elements of matrix A : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << " Enter elements of matrix  B: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
        }
    }
        // matrix multiplication 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << " Resultant Matrix : " ;
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}