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

int ht[1000001]={};

int main()
{   int n;
   le(n);
   int sl,q;
   loop(i,0,n)
   {
       le2(sl,q);
       ht[sl]=q;
   }
   for(int i=1000000-1;i>=1;i--)
   {
       ht[i]=maX(ht[i+1],ht[i]);
   }
   int gf;
   int m;
   le(gf);
   ll ans=0;
   loop(i,0,gf)
   {
       le(m);
       //printf("%d\n",(ht[m]/m)*100);
       ans+=(ht[m]/m);
   }
   cout<<ans*100<<"\n";
    return 0;
}

