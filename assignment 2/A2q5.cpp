// diagonal matrix

// #include <iostream>
// using namespace std;
// int MAX= 4;
// int main()
// {
//     int i, j, a[MAX];
//    cout << " Enter elements (row major): " ;
//     for (i = 0; i < MAX; i++){
//     cin>>a[i];
//     }
//     cout << " The matrix is... " << endl;

//     for (i = 0; i < MAX; i++)
//     {
//         for (j = 0; j < MAX; j++)
//         {
//             if (i == j)
//                 cout << a[i] << " ";
//             else
//                 cout << "0" << " " ;
//         }
//          cout << endl ;
//     }
//     return 0;
// }

// tri-diagonal matrix

// #include <stdio.h>
// #define MAX 4
// int main()
// {
//     int i, j, k = 0, size = 3 * MAX - 2, a[size];
//     printf("\nEnter elements (row major):\n");
//     for (i = 0; i < size; i++)
//         scanf("%d", &a[i]);
//     printf("\nThe matrix is...\n");
//     for (i = 0; i < MAX; i++)
//     {
//         for (j = 0; j < MAX; j++)
//         {
//             if (i - j == -1 || i - j == 0 || i - j == 1)
//             {
//                 printf("%d ", a[k]);
//                 k++;
//             }
//             else
//                 printf("0 ");
//         }
//         printf("\n");
//     }
//     return 0;
// }

// triangular matrix

#include <stdio.h>
#define MAX 4
int main()
{
    int i, j, k = 0, size = (MAX * (MAX + 1)) / 2, a[size];
    printf("\nEnter elements (row major):\n");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
    printf("\nThe upper triangular matrix is...\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (i <= j)
            {
                printf("%d ", a[k]);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
    k = 0;
    printf("\nThe lower triangular matrix is...\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (i >= j)
            {
                printf("%d ", a[k]);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}

// symmetric matrix 



