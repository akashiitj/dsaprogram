
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);


int main()
{
    ll n,k;
    le2ll(n,k);
    //cin>>n>>k;
    ll dp[k+1][n+1];
    loop(i,1,n+1)
    {

        dp[k][i]=1;
        //cout<<dp[k][i]<<" ";
    }
    //cout<<"\n11111\n";
    for(int i=k-1; i>=1; i--)
    {
        loop(j,1,n+1)//finding number of aray upto place i from last such that it ends with j
        {   dp[i][j]=0;
            for(int k1=j; k1<=n; k1=k1+j) //previusly j ke multiple vale array me j ko i place pe rakh do
            {
                dp[i][j]+=(dp[i+1][k1]);
                if(dp[i][j]>=mod)dp[i][j]%=mod;
            }
          //  cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    ll ans=0;
    loop(j,1,n+1)
    ans=(ans+dp[1][j])%mod;

    cout<<ans%mod<<"\n";
    return 0;
}



