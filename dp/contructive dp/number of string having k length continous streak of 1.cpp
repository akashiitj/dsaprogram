#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[100][100];
int k,n;
ll f(int ind,int x)
{
    if(dp[ind][x]!=-1)return dp[ind][x];

    if(ind>n)
        return 0;
    if(x==k)
    {
        return  1LL<<(n-ind);
    }
    ll a=f(ind+1,0)+f(ind+1,x+1);
    return dp[ind][x]=a;

}

int main()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    ll ways = f(0,0);
    ll total = (1LL<<n);
    ll g = __gcd(ways,total);
    ways/=g;
    total/=g;
    cout<<ways<<"/"<<total<<endl;
    return 0;
}
