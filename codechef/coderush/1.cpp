
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


ll s(int x)
{
    return x*1LL*(x+1)*1LL*(2*x+1)/6;
}


int main()
{
    ll n;
    int l;
    int r;
    int ans;
    int m;
    frmlty
    {

        lell(n);



        l=1;
        r=1000000;


        ans=-1;
        while(l<=r)
        {
            m=(l+r)/2;

            if(s(m)==n)
            {
                ans=m;
                break;
            }
            else if (n>s(m))
                l=m+1;
            else r=m-1;
        }
       // cout<<ans<<" "<<l<<" "<<r<<"\n";
        if(ans==-1)ans=r;

        printf("%d\n",ans);
    }

    return 0;
}

