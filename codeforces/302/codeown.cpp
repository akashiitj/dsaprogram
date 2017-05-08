#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)


ll a[501];
ll dp[501][501];//m lines code exactly b bugs


int main()
{
    fast;
    ll n, m, b, mod;
    cin>>n>>m>>b>>mod;
    loop(i,1,n+1)
    cin>>a[i];

    dp[0][0]=1;

    loop(i,1,n+1)
    {
        loop(j,1,m+1)

        {
            loop(k,0,b+1)
            {
                if(a[i]<=k)dp[j][k]=dp[j][k]+dp[j-1][k-a[i]];//already done by n-1 programmers+ this line is wrtten bt nth programmer for total k bugs
                if( dp[j][k]>=mod)dp[j][k]=dp[j][k]%mod;
            }
        }
    }

    ll ans=0;
    loop(k,0,b+1)
    ans=(ans+dp[m][k])%mod;

    cout<<ans<<endl;


}
