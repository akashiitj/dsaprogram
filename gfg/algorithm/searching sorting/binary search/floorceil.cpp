
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

int a[100];



int main()
{
    int n;
    le(n);

    loop(i,1,n+1)
    le(a[i]);

    int l=1;
    int r=n;

    int x;
    le(x);

    while(l<=r)
    {
        int m=(l+r)/2;

        if(a[m]==x)
        {
            cout<<m<<"\n";
            return 0;
        }
        else if (x>a[m])
            l=m+1;
        else r=m-1;
    }

    cout<<l<<" "<<r;// l gives you ceil r gives you floor

    return 0;
}

