#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000001];
ll mod1(ll a,ll b)
{
    return a%b;
}

main()
{   int a,b;
    cin>>a>>b;
    dp[1]=mod1(4,b);
    for(int i=2;i<=1000000;i++)
        {dp[i]=dp[i-1]*dp[i-1];
         dp[i]=mod1(dp[i],b);

        }
        cout<<dp[a]<<endl;
}
