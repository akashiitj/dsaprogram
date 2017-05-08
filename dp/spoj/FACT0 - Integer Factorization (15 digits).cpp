
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
    while(true)
    {
        ll n;
        lell(n);
        if(n==0)
            break;
        map<ll,int> m;
        map<ll,int>::iterator it;
        while(n%2==0)
        {
            m[2]++;
            n=n/2;
        }
        for(ll i=3; i*i<=n; i=i+2)
        {
            while(n%i==0)
            {
                m[i]++;
                n=n/i;
            }
        }
        if(n>2)
            m[n]=1;
        for(it=m.begin();it!=m.end();it++)
        {
            printf("%lld^%d ",it->first,it->second);
        }
        cout<<endl;
    }
    return 0;
}

