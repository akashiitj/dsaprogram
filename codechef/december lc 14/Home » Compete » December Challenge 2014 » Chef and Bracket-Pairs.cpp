#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101][101]= {0};
ll a[101]= {0};
ll mod1(ll x)
{
    x= x%1000000007;
    while(x<0)x+=1000000007;
    return x;
}

int main()
{
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(ll i=1; i<=n-1; i++)
    {
        if(a[i]==(-1*a[i+2-1])&&a[i]<0)
            dp[i][2]=1;
    }

    for(ll l=3; l<=n; l++)
    {
        for(ll i=1; i<=n-l+1; i++)
        {
            dp[i][l]+=dp[i][l-1];
            if(a[i]==(-1*a[i+l-1])&&a[i]<0)
                dp[i][l]+=(dp[i+1][l-2]+1);
            dp[i][l]=mod1(dp[i][l]);
            int x=a[i+l-1];
            if(x>0)
            {
                for(int k=i+1; k<i+l-1; k++)
                    if(a[k]+x ==0)    dp[i][l]+=mod1((1+dp[i][k-i])*(1+dp[k+1][i+l-1-k-1]));
                dp[i][l]=mod1(dp[i][l]);
            }
        }
    }
    cout<<mod1(dp[1][n]+1)<<endl;
    return 0;
}
