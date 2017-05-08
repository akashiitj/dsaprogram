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

int p[200001];
int w[200001];
int n,q;

set<pii> s;

int fnd(int i)
{
    int id=i,x;
    while(i!=p[i])
        i=p[i];

    //path compress
    while(id!=i)
    {
        x=p[id];
        p[id]=i;
        id=x;
    }

    return i;
}

void unin(int i,int j)
{
    int pi=fnd(i);
    int pj=fnd(j);

    if(pi==pj)return;

    s.erase(s.find(mp(w[pi],pi)));
    s.erase(s.find(mp(w[pj],pj)));
    p[pi]=pj;
    w[pj]+=w[pi];
    s.insert(mp(w[pj],pj));
}

int main()
{
    le2(n,q);
    loop(i,1,n+1)
    {
        p[i]=i;
        le(w[i]);
        s.insert(mp(w[i],i));
    }
    int n1,n2;
    loop(i,0,q)
    {
        le2(n1,n2);
        unin(n1,n2);
        pii p=*s.begin();
        printf("%d\n",p.first);
    }

    return 0;
}

