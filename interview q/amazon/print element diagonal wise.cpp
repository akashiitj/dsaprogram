#include<bits/stdc++.h>
using namespace std;
void p(int **a,int m,int n,int i,int j)
{
    while(i<=m-1&&j<=n-1)
    {
        cout<<a[i][j]<<" ";
        i++;
        j++;
    }
    cout<<endl;

}
void f(int **a,int m,int n)
{
    int i=0,j=n-1;
    while(j>=0)
    {
        p(a,m,n,i,j);
        j--;
    }
    i=1,j=0;
    while(i<m)
    {
        p(a,m,n,i,j);
        i++;
    }
}
main()
{
    int **a,m,n;
    cin>>m;
    cin>>n;
    a=new int *[m];
    for(int i=0;i<m;i++)
        {
        a[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>a[i][j];

        }
        f(a,m,n);
}
