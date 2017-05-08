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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll dp[100001][2][2];
ll f(ll n,ll ending,ll no00)//ending with 0 or 1 ,number of consecutive 00 it can be 0 or 1;
{
    if(n==1&&no00==0)return 1;
    if(n==1&&no00==1)return 0;
    if(dp[n][ending][no00]!=-1)return dp[n][ending][no00];
    if(ending==0)
    {
        if(no00==0) dp[n][ending][no00]=f(n-1,1,0);
        if(no00==1)  dp[n][ending][no00]=(f(n-1,0,0)+f(n-1,1,1))%mod;
        return dp[n][ending][no00];
    }
    if(ending==1)
    {
        if(no00==0) dp[n][ending][no00]=(f(n-1,0,0)+f(n-1,1,0))%mod;
        if(no00==1) dp[n][ending][no00]=(f(n-1,0,1)+f(n-1,1,1))%mod;
        return dp[n][ending][no00];
    }
}

int main()
{
    ll n,ans;
    frmlty
    {
        cin>>n;
        loop(i,0,n+1)
        loop(j,0,2)
        loop(k,0,2)
        dp[i][j][k]=-1;
        ans=(f(n,1,1)+f(n,0,1))%mod;
        cout<<ans<<"\n";
    }
    return 0;
}
/*


Practice Challenges Companies ug201210003
June Easy Challenge '15

#include <cstdio>
#include <iostream>
#include <cassert>
using namespace std;
#define MOD 1000000007
#define MAXN 100000
long long ar[MAXN+1][2][3];
void init(){
    ar[1][0][0] = 1;
    ar[1][1][0] = 1;
    ar[1][0][1] = 0;
    ar[1][1][1] = 0;
    for(int i=2;i<=MAXN;i++){
        ar[i][0][0] = ar[i-1][1][0];
        ar[i][0][1] = (ar[i-1][1][1] + ar[i-1][0][0]) % MOD;

        ar[i][1][0] = (ar[i-1][0][0] + ar[i-1][1][0])%MOD;
        ar[i][1][1] = (ar[i-1][0][1] + ar[i-1][1][1])%MOD;

    }
}
int main(){
    int T, N;
    init();
    cin >> T;
    assert(T>0 and T<=10);
    while(T--){
        cin >> N;
        assert(N>0 and N<=MAXN);
        cout << (ar[N][0][1] + ar[N][1][1])%MOD << endl;
    }
    return 0;
}
*/
