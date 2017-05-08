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

int a[1001];
vi v;


int main()
{  int n;
   frmlty
   {
       le(n);
       loop(i,1,n+1)
       le(a[i]);

       sort(a+1,a+n+1);
       ll sum=0;
       loop(i,1,n+1)
       sum=sum+2*1LL*(((i-1)*1LL*a[i])-((n-i)*1LL*a[i]));


       v.clear();
       v.pb(0);
       loop(i,1,n+1)
       loop(j,i+1,n+1)
       v.pb(a[i]+a[j]);

       sort(v.begin(),v.end());
       ll sum1=0;
       int n1=v.size();
       loop(i,1,v.size())
       sum1=sum1+2*1LL*(((i-1)*1LL*v[i])-((n1-1-i)*1LL*v[i]));

       cout<<sum1-(n-2)*1LL*sum<<"\n";;


   }
    return 0;
}

