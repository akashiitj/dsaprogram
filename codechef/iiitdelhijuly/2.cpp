#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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
    int n,q;
    le2(n,q);
    ll a[n];
    ll freq[n+1];
    loop(i,0,n)
    {
         lell(a[i]);
        freq[i]=0;
    }

    int l,r;
    loop(i,0,q)
    {
        le2(l,r);
        freq[--l]++;
        freq[r]--;
    }
    ll c=0;
    loop(i,0,n)
    {
        c=freq[i]+c;
        freq[i]=c;
    }
    sort(freq,freq+n);
    //reverse(freq,freq+n);
    sort(a,a+n);
    // reverse(a,a+n);
    ll ans=0;
    loop(i,0,n)
    ans=ans+a[i]*freq[i];

    cout<<ans<<"\n";
    return 0;
}


