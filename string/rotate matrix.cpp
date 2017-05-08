#include<iostream>
using namespace std;
void rotate(int **a,int m,int n)
{  //int a[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int ra[n][m];
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            ra[j][i]=a[m-i-1][j];
        }
    }
     for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            cout<<ra[j][i]<<" ";
        }
        cout<<endl;
    }
}
main()
{   int m,n;
    cin>>m;
    cin>>n;
    int **a;
    a=new int *[m];
    for(int i=0;i<m;i++)
    {
        a[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    rotate(a,m,n);
}
