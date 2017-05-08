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

int d[10001];
int visit[10001];

vi v[10001];

void dfs(int cv)
{
    int n=v[cv].size();
    visit[cv]=1;
    loop(i,0,n)
    {
        if(visit[v[cv][i]]==0)
        {
            d[v[cv][i]]=d[cv]+1;
            dfs(v[cv][i]);
        }
    }
}

int main()
{
    int n,x,y;
    frmlty
    {
        le(n);
        loop(i,0,n)
        {
            d[i]=0;
            visit[i]=0;
            v[i].clear();
        }

        loop(i,0,n-1)
        {
            le2(x,y);
            x--;
            y--;
            v[x].pb(y);
            v[y].pb(x);
        }
        d[0]=0;
        dfs(0);
        // cout<<"s"<<endl;
//       loop(i,0,n)
//       cout<<d[i]<<" ";
//       cout<<endl;
        int dm=-1,ai;
        loop(i,0,n)
        {
            if(dm<d[i])
            {
                dm=d[i];
                ai=i;
            }
        }
        //cout<<ai<<endl;

        loop(i,0,n)
        {
            d[i]=0;
            visit[i]=0;

        }

        dfs(ai);
//        loop(i,0,n)
//       cout<<d[i]<<" ";
//       cout<<endl;
        dm=-1;
        int ai2;
        loop(i,0,n)
        {
            if(dm<d[i])
            {
                dm=d[i];
                ai2=i;
            }
        }

         vector<int> vc;
        vc.clear();
        loop(i,0,n)
        if(d[i]==d[ai])vc.pb(i);
        if(vc.size()==1&&d[ai2]>1)
        {
            printf("YES\n");
            continue;
        }

        if(dm>2)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

