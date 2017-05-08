
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

double a[10000];

int main()
{   int n,m;
   int l,r;
   double d,te;
   int c=0;
    frmlty
    {  c++;
        le2(n,m);
        loop(i,0,n)
        cin>>a[i];
        cout<<"Case #"<<c<<":\n";
        cout<<fixed<<setprecision(9);
        loop(i,0,m)
        {
           le2(l,r);
           d=1.0;
           loop(j,l,r+1)
           d=d*a[j];
           te=(r-l+1)*1.0;
          // cout<<log2(d)<<" "<<te<<" "<<d<<"\n";
           cout<<pow(2.0,log2(d)/te)<<"\n";
        }
    }
    return 0;
}

