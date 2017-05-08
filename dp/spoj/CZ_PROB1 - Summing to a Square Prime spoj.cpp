#include<bits/stdc++.h>
using namespace std;
int isprime[8000];
int issqr[8000];
int dp[4][8000];

int f(int n,int k)
{
    if(n==0||k==1)return 1;
    if(dp[k][n]!=0)return dp[k][n];
    int ans1=f(n,k-1);
    int ans2=0;
    if(n-k>=0)ans2=f(n-k,k);
    dp[k][n]=ans1+ans2;
    return ans1+ans2;
}

vector<int > v;

main()
{
    for(int i=0; i<8000; i++)
    {
        isprime[i]=1;
        issqr[i]=0;
        dp[1][i]=1;
        dp[2][i]=0;
        dp[3][i]=0;
    }
    dp[2][0]=1;
    dp[3][0]=1;
    for(int i=2; i<8000; i++)
    {
        if(isprime[i])
        {
            for(int j=i*i; j<8000; j=j+i)
                isprime[j]=0;
        }
    }

    for(int i=1; i*i<8000; i++)
        issqr[i*i]=1;

    for(int i=2; i<8000; i++)
    {
        if(isprime[i])
        {
            for(int j=1; j*j<i; j++)
            {
                if( issqr[i-(j*j)])
                {

                    v.push_back(i);
                    break;
                }
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<8000; i++)
        {

            dp[1][i]=1;
            dp[2][i]=0;
            dp[3][i]=0;
        }
        dp[2][0]=1;
        dp[3][0]=1;
        int n,k;
        cin>>n>>k;
       // cout<<v[n]<<endl;
        cout<<f(v[n-1],k)<<endl;
    }
}
