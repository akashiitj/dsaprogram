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

int a[1000001];

int main()
{   int n,k;
    int ma,mi;
    frmlty
    {   ma=0;
       mi=INT_MAX;
        le2(n,k);
        loop(i,0,n)
        le(a[i]);

        sort(a,a+n);

        loop(i,0,(n/2)+1)
        {
            ma=maX(ma,a[i]+a[n-i-1]);
            mi=miN(mi,a[i]+a[n-i-1]);
        }
        cout<<ma-mi<<"\n";
        if((ma-mi)==k)
            cout<<"Lucky chap!\n";
        else if((ma-mi)>k)
            cout<<"No more girlfriends!\n";
        else cout<<"Chick magnet Jhool!\n";

    }
    return 0;
}


