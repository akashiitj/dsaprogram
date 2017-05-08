

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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

vector<int> g[100005];
int vis[100005]= {};
int colr[100005];//note down color of each node

int c1=0,c0=0;
int soc=0;//number of node in component
queue<int> q;
int isbarpitite(int sv)
{
    int hv;

    vis[sv]=1;

    while(!q.empty())q.pop();
    q.push(sv);
    colr[sv]=1;
    c1++;
    soc++;
    while(!q.empty())
    {
        hv=q.front();
        q.pop();

        loop(i,0,g[hv].size())
        {
            if(vis[g[hv][i]]==0)
            {
                vis[g[hv][i]]=1;
                soc++;
                colr[g[hv][i]]=1-colr[hv];
                if(colr[g[hv][i]]==1)c1++;
                else c0++;
                q.push(g[hv][i]);
                // cout<<hv<<" "<<g[hv][i]<<" "<<c0<<" "<<c1<<" "<<soc<<"\n";
            }
            else if(colr[g[hv][i]]==colr[hv])//means not bipartite
            {
                return 0;
            }
        }
    }
    return 1;

}

int main()
{
    int n,m,v1,v2;
    le2(n,m);
    loop(i,0,m)
    {
        le2(v1,v2);
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    int check;
    ll ans1=0;
    int ismax2=1;
    int ismax1=1;
    int cnt2=0;
    loop(i,1,n+1)
    {
        if(vis[i]==0)
        {
            soc=0;
            c0=0;
            c1=0;
            // cout<<"c1\n";
            check=isbarpitite(i);
            // cout<<"c1\n";
            //cout<<check<<" "<<c0<<" "<<c1<<" "<<soc<<"\n";
            if(soc>2)
            {
                ismax1=0;
                ismax2=0;
            }
            if(soc>1)ismax1=0;
            if(soc==2)cnt2++;
            if(check==0)
            {
                cout<<"0 1\n";
                return 0;
            }
            else if(check==1&&soc>2)
            {
                ans1=ans1+((c0*1LL*(c0-1))/2)+((c1*1LL*(c1-1))/2);//if component is barpitite for each color set(2) u can choose any 2 and add edge it form odd cycle
            }

        }
    }
    //cout<<"c1\n";
    if(ismax1==1)
    {
        printf("3 ");
        ll res = 1LL * n * 1LL * (n - 1);
        res = res * 1LL * (n - 2);
        res /= 6;
        cout<<res<<"\n";
        return 0;
    }
    if(ismax2==1)
    {
        printf("2 ");
        ll res = 2 * 1LL * cnt2 * 1LL * (cnt2 - 1);//4* cnt2 C 2
        res = res + cnt2 * 1LL * (n - 2 * cnt2);//cnt2*cnt1
        cout<<res<<"\n";
        return 0;
    }
    cout<<"1 "<<ans1<<"\n";
    return 0;
}


