#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

int w[10000];
int c[10000];

int dp[1000][1000];//items, weigth

int mw;

int td(int n,int mw)
{
    if(n==0||mw==0)
        return 0;
    else if(w[n]>mw)
        return td(n-1,mw);
    else return max(td(n-1,mw),td(n-1,mw-w[n])+c[n]);
}

int tddp(int n,int mw)
{ if(dp[n][mw]!=-1)return dp[n][mw];

    if(n==0||mw==0)
       {
         dp[n][mw]=0;
         return 0;
       }

    else if(w[n]>mw)
    {
        dp[n][mw]=td(n-1,mw);
        return dp[n-1][mw];
    }
    else
    {   dp[n][mw]=max(td(n-1,mw),td(n-1,mw-w[n])+c[n]);
        return dp[n][mw];
    }
}
main()
{   loop(i,0,1000)
    loop(j,0,1000)
    dp[i][j]=-1;

    cout<<"enter no of item their weigth and then their cost"<<endl;
    int n;
    cin>>n;

    loop(i,1,n+1)
    cin>>w[i];

    loop(j,1,n+1)
    cin>>c[j];

    cout<<"\nenter max weight"<<endl;

    cin>>mw;


    cout<<td(n,mw)<<endl;
}
