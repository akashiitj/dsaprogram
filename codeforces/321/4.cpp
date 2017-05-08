// kefa and dishes
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

#define fi first;
#define se second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

ll a[25];
ll dp[1<<20][25];
ll g[25][25];

int main()
{
    int n,m,k;
    le2(n,m);
    le(k);
    int x,y;
    ll c;
    loop(i,0,n)
    {
        lell(a[i]);

    }

    loop(i,0,k)
    {
        le2(x,y);
        lell(c);
        x--;
        y--;
        g[x][y]=c;

    }

    loop(i,0,n)
    dp[1<<i][i]=a[i];

    int premask;
    ll ans=0;
    loop(i,1,1<<n)
    {

        loop(j,0,n)
        {

            if((1<<j)&i)
            {
                premask=i-(1<<j);
                loop(j1,0,n)
                {
                    if(j1==j)continue;
                    if((1<<j1)& premask)
                        dp[i][j]=maX(dp[i][j],dp[premask][j1]+a[j]+g[j1][j]);
                }
                if(__builtin_popcount(i)==m)
                {

                    ans=maX(ans,dp[i][j]);
                  //  cout<<ans<<" "<<i<<" "<<j<<"\n";
                }
            }

        }
    }
    cout<<ans<<"\n";

    return 0;
}



