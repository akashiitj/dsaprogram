#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[100001]= {0};
ll mod1(ll x)
{
    return x%1000000007;
}
int main()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2; i<=100000; i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]=mod1(fact[i]);
    }
    int t;
    cin>>t;
    ll ans,x,y,z,n;
    while(t--){
    cin>>n;

    x=((n*n*n)+(n*n))/2;
    y=(n*(n+1)*((2*n)+1))/6;
    z=mod1(fact[n-1]*2);
    x=mod1(x-y);
    ans=x*z;
    cout<<mod1(ans)<<endl;
}
return 0;
}
