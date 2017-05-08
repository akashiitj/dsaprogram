
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

double fsqrt(double x){double xhalf=0.5f*x;int32_t i=*(int32_t*)&x;i=0x5f375a86-(i>>1);x=*(double*)&i;x=x*(1.5f-xhalf*x*x);return 1/x;}


int main()
{   double a,b,c,d;
    double s;
    frmlty
    {
        cin>>a>>b>>c>>d;
        s=(a+b+c+d)/2.0;

        s=(s-a)*(s-b)*(s-c)*(s-d);
        cout<<fixed<<setprecision(2);
        cout<<sqrtf(s)<<"\n";
    }
    return 0;
}

