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

char a[55][55];
int dp[55][55]= {};
 int w,h;
int f(int i,int j)
{
    int l=1;
    if(dp[i][j]!=-1)return dp[i][j];
    loop(i1,-1,2)
    loop(j1,-1,2)
    if(i+i1>=0&&i+i1<h&&j+j1>=0&&j+j1<w&&a[i+i1][j+j1]-a[i][j]==1)l=maX(l,1+f(i+i1,j+j1));
    return dp[i][j]=l;
}

int main()
{

    // cout<<(int)a[6][6];
    int an;
    int c=0;
    while(true)
    {
        c++;
        an=0;
        le2(h,w);
        if(h==0&&w==0)break;
        loop(i,0,h)
        {
            loop(j,0,w)
            {

                cin>>a[i][j];
                dp[i][j]=-1;
            }
        }
        loop(i,0,h)
        loop(j,0,w)
        {

            if(a[i][j]=='A')an=maX(an,f(i,j));
        }
        printf("Case %d: %d\n",c,an);
    }
    return 0;
}
