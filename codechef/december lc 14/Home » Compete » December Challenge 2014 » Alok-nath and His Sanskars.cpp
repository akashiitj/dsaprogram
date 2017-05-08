
#include <bits/stdc++.h>
using namespace std;
// Returns true if arr[] can be partitioned in two subsets of
// equal sum, otherwise false
bool findPartiion (int arr[], int n,int k)
{
    int sum = 0;
    int i, j;
    int a[n];
    // Caculcate sun of all elements
    for (i = 0; i < n; i++)
      {sum += arr[i];
      a[i]=0;}
    //sum=sum/k;
    if (sum%k != 0)
       return false;

    bool part[sum/k+1][n+1];

    // initialize top row as true
    for (i = 0; i <= n; i++)
      part[0][i] = true;

    // initialize leftmost column, except part[0][0], as 0
    for (i = 1; i <= sum/2; i++)
      part[i][0] = false;

     // Fill the partition table in botton up manner
     for (i = 1; i <= sum/k; i++)
     {
       for (j = 1; j <= n; j++)
       {
         part[i][j] = part[i][j-1];
         if (i >= arr[j-1])
           {part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];

           }
       }
     }

     // uncomment this part to print table
     cout<<"      ";
     for (j = 0; j <= n; j++)
        cout<<j<<"     ";
     cout<<endl;
     for (i = 0; i <= sum/k; i++)
     {  cout<<i<<"     ";
       for (j = 0; j <= n; j++)
          printf ("%d     ", part[i][j]);
       printf("\n");
     }

     return part[sum/2][n];
}

// Driver program to test above funtion
int main()
{
  int arr[] = {1,1,2,2,2,2,2,2,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartiion(arr, n,3) == true)
     printf("Can be divided into two subsets of equal sum");
  else
     printf("Can not be divided into two subsets of equal sum");
  getchar();
  return 0;
}
