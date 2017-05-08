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

int a[100001];

int ml[100001];
int mr[100001];

int main()
{
     int n;
     le(n);
     loop(i,0,n)
     {
         le(a[i]);
     }
     ml[0]=a[0];
     loop(i,1,n)
     {
         ml[i]=maX(ml[i-1],a[i]);
     }

     mr[n-1]=a[n-1];
     for(int i=n-2;i>=0;i--)
         mr[i]=maX(mr[i+1],a[i]);
     cout<<1<<" ";
     loop(i,1,n-1)
     {
         if(ml[i-1]<a[i]||mr[i+1]<a[i])
            cout<<i+1<<" ";
     }
     cout<<n<<"\n";

    return 0;
}

