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

set<pair<ll,ll> > s;
set<ll> pos;
map<ll,ll> m;
int hp[200001];

int main()
{
    ll n;
    int q;
    lell(n);
    le(q);
    int x;
    int pn=0;
    set<pair<ll,ll> >::reverse_iterator p;
    pos.insert(0);
    pos.insert(n+1);
    loop(i,0,q)
    {
        le(x);
        ll ml;
        if(x==1)
        {
            pn++;
            if(s.size()==0)
            {
                s.insert(mp(n-1,1));
                hp[pn]=1;
                m[1]=n-1;
                printf("1\n");
            }
            else
            {
                p=s.rbegin();
                s.erase(p);
                ll np=p.first+p.second;
                if(np==n)
                {
                    hp[pn]=n;
                    s.insert(mp((*p).first,(*p).second-1);
                    printf("%lld\n",n);

                }
                else
                {
                    ml=p.second/(2*1LL);
                    hp[pn]=p.first+ml;
                    s.insert(mp(p.first,ml-1));
                    s.insert(mp(ht[pn],ml));
                    m[p.first]=ml-1;
                    m[ht[pn]]=ml;
                    printf("%lld\n",hp[pn]);
                }
            }
        }

    }
    return 0;
}


