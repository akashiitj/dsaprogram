
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod=100000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

ll dp[1001][1050];
int a[1001];
int hb[1001];

int main()
{
    int n,m,x;
    int hvc=0;
    frmlty
    {
        hvc++;
        le2(n,m);

        loop(i,0,n+1)
        loop(j,0,1024)
        {

            hb[j]=0;
            dp[i][j]=0;
        }
        loop(i,1,n+1)
        le(a[i]);

        loop(i,1,m+1)
        {

            le(x);
            hb[x]=1;

        }
        dp[0][0]=1LL;
        //if(n==0)cout<<"Case "<<hvc<<": "<<"0\n";


            loop(i,1,n+1)
            {
                loop(j,0,1024)
                dp[i][j]=(dp[i-1][j]+dp[i-1][j^a[i]])%mod;
            }
            ll ans=0;
            loop(j,0,1024)
            {
                if(hb[j]==0)ans=(ans+dp[n][j])%mod;
            }

            cout<<"Case "<<hvc<<": "<<ans<<"\n";

    }
    return 0;
}

