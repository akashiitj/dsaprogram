
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
vi index;

int ans[100];//it store index of nxt grater element if greater element doesnt exist then 0

int main()
{
    int n;
    le(n);

    loop(i,1,n+1)
    le(a[i]);

    index.pb(-1);

    loop(i,1,n+1)
    {
        while(index.back()!=-1&&a[index.back()]<a[i])
        {
            ans[index.back()]=i;
            index.pop_back();
        }
        index.pb(i);

    }

    loop(i,1,n+1)
    cout<<ans[i]<<" ";


    return 0;
}

