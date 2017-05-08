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
{  ll f,b,t,d,time;
    frmlty
    {

       le2ll(f,b);
       le2ll(t,d);
        if(d<=f)
        {
            time = t*d;
        }
        else
        {
            ll point,quo,rem,fin,total;
            point = d-f;
            quo = point/(f-b);
            rem = point%(f-b);
            fin = (quo+1-(rem==0))*(f-b);
            total = (quo+1-(rem==0))*(f+b) + d-fin;
            time = total*t;
        }
        printf("%lld\n",time);
    }
    return 0;
}
