#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b)      for(long long i=a;i<b;i++)

long long  dp[100][100];

long long ftd(long long n,long long k)
{
    if(k==0)
    {
        dp[n][k]=1;
        return 1;
    }
    if(n==0)
    {
        dp[n][k]=0;
        return 0;
    }

    if(dp[n][k]!=-1)return dp[n][k];
    long long ans=0;
    for(long long i=0; i<n&&i<=k; i++)
    {
        ans=ans+ftd(n-1,k-i);
    }
    dp[n][k]=ans;
    return dp[n][k];
}

void fbp(long long n,long long k)
{
    dp[1][0]=1;
    loop(i,2,n+1)
    {
        dp[i][0]=1;
        loop(j,1,k+1)
        {
            int ans=0;
            for(int k=0; k<=j&&k<i; k++)
                ans=ans+dp[i-1][j-k];
            dp[i][j]=ans;
        }
    }
}

main()
{

    long long t;



    cin>>t;
    /* while(t--)
     {
         loop(i,0,100)
         loop(j,0,100)
         dp[i][j]=-1;
         long long n,k;
         cin>>n>>k;

         cout<<ftd(n,k)<<endl;
     }*/
    loop(i,0,100)
    loop(j,0,100)
    dp[i][j]=0;

    fbp(12,99);



    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<dp[n][k]<<endl;
    }
}
