
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

void f(int n)
{
    vi cv,pv;
    int x;
    cv.pb(1);

    int carry;
    loop(i,2,n+1)
    {
        carry=0;
        pv=cv;
        cv.clear();

        loop(j,0,pv.size())
        {
            x=pv[j]*i+carry;
            cv.pb(x%10);
            carry=x/10;
        }
        while(carry>0)
        {
            cv.pb(carry%10);
            carry=carry/10;
        }
    }
    while(cv.size()!=0)
    {
        cout<<cv.back();
        cv.pop_back();
    }
}


int main()
{
    int n;
    frmlty
    {
        le(n);
        f(n);
        cout<<"\n";
    }
    return 0;
}

