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

#define F first;
#define S second;



int cnt[4004],g[4004][4004];
vector< pii > e;
int main()
{
    int n,m,a,b,c;
    le2(n,m);
    for(int i=0;i<m;i++)
    {   le2(a,b);
        e.push_back(mp(a,b));
        cnt[a]++;
        cnt[b]++;
        g[a][b]=1;
        g[b][a]=1;
    }
    int ans = INT_MAX;
    for(int i=0;i<e.size();i++)
    {
        a = e[i].first;
        b = e[i].second;
        for(int j=1;j<=n;j++)
        {
            if(j==a||j==b)continue;
            int c = j;
            if(g[a][b]&&g[b][c]&&g[a][c])
            {
            int temp = cnt[a]+cnt[b]+cnt[c]-6;
            ans = min(ans,temp);
            }
        }
    }
    if(ans==INT_MAX) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
