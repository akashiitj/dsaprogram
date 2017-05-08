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
int count1(int n)
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

    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n-1;i++)
            cin>>k>>k;
        cout<<"Eli"<<endl;
    }


    return 0;
}



