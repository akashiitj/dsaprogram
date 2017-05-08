
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

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

int a[1001];
int pos[1001];

int b[1001][1001];//i jaha par bhi hai usse phle including usko bhi how many elent are smaller or = to j
int dp[1001][1001];//min cost to sort element from i to j

int main()
{
    int n;
    frmlty
    {
        le(n);
        loop(i,1,n+1)
        {
            le(a[i]);
            pos[a[i]]=i;
        }
        loop(i,1,n+1)
        loop(j,1,n+1)
        {
            b[i][j]=b[i][j-1]+(pos[j]<=pos[i]);
        }
        loop(i,1,n+1)
        {
            dp[i][i]=pos[i];
        }
        loop(l,2,n+1)
        {
            loop(i,1,n-l+1+1)
            {
                int j=i+l-1;
                dp[i][j]=miN(dp[i][j-1]+l*(pos[j]-(b[j][j-1]-b[j][i-1])),dp[i+1][j]+l*(pos[i]-(b[i][j]-b[i][i])));
            }
        }
        cout<<dp[1][n]<<"\n";
    }
    return 0;
}

