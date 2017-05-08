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

//cout<<fixed<<setprecision(6)<<ans<<"\n";

int main()
{
    int n;
    le(n);
    int tn=n*n;
    int a[tn];
    vi fa;

    map<int,int> m;
    map<int,int> ::iterator it;
    loop(i,0,tn)
    {
        le(a[i]);
        m[a[i]]++;
    }
    if(n==1)
    {
        cout<<a[0]<<"\n";
        return 0;
    }
    if(n==2)
    {
        sort(a,a+tn);
        cout<<a[2]<<" "<<a[3]<<"\n";
        return 0;
    }

    it=m.end();
    it--;
    fa.pb(it->first);
    m[it->first]--;

    if(it->second==0)
    {
        m.erase(it);
    }
    it=m.end();
    it--;
    fa.pb(it->first);
    m[it->first]--;

    int fgcd=__gcd(fa[0],fa[1]);
    m[fgcd]=m[fgcd]-2;

    while(fa.size()!=n)
    {
        it=m.end();
        it--;
        if(it->second==0)
        {
            m.erase(it);
            continue;
        }
        int pv=it->first;
        m[pv]--;
        loop(i,0,fa.size())//remove its gcd with present number
        {
            fgcd=__gcd(pv,fa[i]);
            m[fgcd]=m[fgcd]-2;
        }
        fa.pb(pv);
    }

    for(int i=0; i<n; i++)
        cout<<fa[i]<<" ";

    return 0;
}
