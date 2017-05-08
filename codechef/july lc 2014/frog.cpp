
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       10000009

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);



int main()
{
     fast;
    int n,k,p,x;

    le2(n,k);
    le(p);

    int a[n+1];

    vector<pii> v;
    loop(i,1,n+1)
    {
        le(x);
        v.pb(mp(x,i));

    }
    sort(v.begin(),v.end());
    int c=0;
    a[v[0].second]=c;
    loop(i,0,n-1)
    {
        if(v[i+1].first-v[i].first<=k)
        {
            a[v[i+1].second]=c;
        }
        else a[v[i+1].second]=++c;
    }
    int y;
    loop(i,0,p)
    {
        le2(x,y);
        if(a[x]==a[y])
            printf("Yes\n");
        else printf("No\n");
    }
}
