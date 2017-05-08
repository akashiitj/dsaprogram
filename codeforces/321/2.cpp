#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<ll,ll>

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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define fi first;
#define se second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

pii a[100001];
ll cs[100001];

int main()
{

    int n,d;
    le2(n,d);

    loop(i,1,n+1)
    {
        le2ll(a[i].first,a[i].second);

    }
    sort(a+1,a+1+n);

   loop(i,1,n+1)
    {

        cs[i]=cs[i-1]+a[i].second;
    }
    int i=1;
    int j=1;
    ll pa,fa=0;
    while(j<=n)
    {
        j=maX(j,i+1);
        pa=a[i].second;
        while(j<=n&&a[j].first-a[i].first<d)
        {
            pa=cs[j]-cs[i-1];
            j++;
        }
        i++;
        fa=maX(fa,pa);
    }
    cout<<fa<<"\n";

    return 0;
}
