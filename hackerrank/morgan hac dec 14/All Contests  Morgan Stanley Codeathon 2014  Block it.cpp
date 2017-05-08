#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char a[35][35];
ull c[35][35]= {0};
void intia(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            c[i][j]=0;
        }
    }
    c[0][0]=1;

}
ull count1(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]!='#')
            {
                if(i>=0&&j-1>=0)c[i][j]=c[i][j]+c[i][j-1];
                if(i-1>=0&&j>=0)c[i][j]=c[i][j]+c[i-1][j];
            }
        }
    }
    return c[n-1][n-1];
}
int main()
{

    int t,n;
    cin>>t;
    while(t--)
    {   ull max1=18446744073709551615;
      // cout<<max1<<endl;
        cin>>n;
        c[0][0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        }
        ull rc;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0&&j==0) {}
                else if(i==n-1&&j==n-1) {}
                else if(a[i][j]=='.')
                {
                    a[i][j]='#';
                    rc=count1(n);
                    if(rc<max1&&rc>=0)
                    {
                        max1=rc;
                    }
                    a[i][j]='.';
                    intia(n);
                }
            }
        }
        cout<<max1<<endl;

    }


    return 0;
}


