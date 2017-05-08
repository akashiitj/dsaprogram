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

vi g1[21];
vi g2[101];
int a[21];
int c[101];
int p[101];
int vis[21];
int mark[101];

int main()
{
    int n,m,k,x;
    frmlty
    {
        loop(i,0,21)
        g1[i].clear();

        loop(i,0,101)
        g2[i].clear();

        le2(n,m);
        le(k);

        loop(i,0,n)
        {
            le(a[i]);

        }

        loop(i,0,m)
        {
            le(c[i]);

        }

        loop(i,0,m)
        {
            le(p[i]);

        }

        loop(i,0,n)
        {
            x=a[i];
            loop(j,0,m)
            {
                if(__gcd(x,c[j])!=1)
                {
                    g1[i].pb(j);
                    g2[j].pb(i);
                }
            }
        }



        int hv=0;


        int fa=0;
        int ansi;
        loop(i,0,1<<n)
        {
            int sb=0;
            loop(j,0,n)
            {
                if(i & 1<<j)
                {
                    sb++;
                }
            }
            if(sb>k||sb<=k-1)continue;
            memset(mark,0,sizeof(mark));
            int pa=0;

            loop(j,0,n)
            {
                if(i & 1<<j)
                {
                    loop(j1,0,g1[j].size())
                    {
                        if(mark[g1[j][j1]]==0)
                        {
                            pa=pa+p[g1[j][j1]];
                            mark[g1[j][j1]]=1;
                        }
                    }
                }
            }
            fa=maX(fa,pa);
        }
        cout<<fa<<"\n";
    }
    return 0;
}

