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



int main()
{
    int n;
    le(n);
    int x;
    map<int,pii> m;
    map<int,pii> ::iterator it;

    loop(i,1,n+1)
    {
        le(x);
        if(m[x].second==0)
            m[x]=mp(1,i);
        else m[x].first++;
    }

    vector<pair<pii,int > > v;
    for(it=m.begin();it!=m.end();it++)
    {
        v.pb(mp(it->second,it->first));
    }
    sort(v.begin(),v.end());
    loop(i,0,n)
    {
        cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<"\n";
    }


    return 0;
}


