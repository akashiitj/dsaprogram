#include<bits/stdc++.h>
using namespace std;

int dp[100001];

int f(int n)
{
    if(n==1)return 0;
    if(dp[n]!=-1)return dp[n];
    int ans=f(n-1)+1;
    if(n%2==0)ans=min(ans,f(n/2)+1);
    if(n%3==0)ans=min(ans,f(n/3)+1);

    dp[n]=ans;
    return ans;
}


main()
{
    int t;
    cin>>t;
    while(t--)
    {   for(int i=0;i<=100000;i++)
         dp[i]=-1;
        int n;
        cin>>n;
        cout<<f(n)<<endl;

    }
}
