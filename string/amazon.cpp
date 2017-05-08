#include <bits/stdc++.h>
using namespace std;
struct check
    {
        int r;
        int c;
    };

int main()
{
    int n;
    check q[8]
    check *top=q;
    cin>>n;
    int a[n][n];
    int i,j;
    for(i=0;i<(n);i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }

    }
    int b[n][n];
    for(i=0;i<(n);i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=0;
        }

    }
   for(i=0;i<(n);i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1&&b[i][j]==0)
            {

            }
        }

    }
}
