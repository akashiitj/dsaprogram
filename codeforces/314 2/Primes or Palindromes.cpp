
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 5000000007;

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

int isprime[5000001];
ll csp[5000001];
ll cs[5000001];

int ispal(int n)
{
   // string s1="",s2;
    vi v;
    while(n>0)
    {
        v.pb(n%10);
        n=n/10;
    }
    int n1=v.size();
    loop(i,0,v.size())
    {
        if(v[i]!=v[n1-1-i])
                return 0;
    }
    return 1;
}

int main()
{


    isprime[0]=1;
    isprime[1]=1;
    isprime[2]=0;
    ll p,q;
    le2ll(p,q);
    for(int i=2; i*i<=5000000; i++)
    {
        if(isprime[i]==0)
        {
            for(int j=i*i; j<=5000000; j=j+i)
                isprime[j]=1;
        }
    }
    csp[0]=0;
    for(int i=1; i<=5000000; i++)
    {
        csp[i]=csp[i-1]+(1-isprime[i])*1LL;
    }

    cs[1]=1;
    for(int i=2; i<=5000000; i++)
    {
        cs[i]=cs[i-1]+ispal(i)*1LL;
    }
// cout<<1<<"\n";
    for(int i=5000000; i>=1; i--)
    {
        if(p*1LL*cs[i]>=q*1LL*csp[i])
        {

            cout<<i<<"\n";
            return 0;
        }
    }

    cout<<-1<<"\n";
    return 0;
}


