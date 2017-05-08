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

int n,c;
vi v;

int f(int m)
{
    int i=0;
    int j=i;
    int c1=1;
    while(j<n)
    {
        if(v[j]-v[i] >=m)
        {
            c1++;
            i=j;
        }
        else j++;
        if(c1>=c)return 1;
    }
    return 0;
}

int main()
{
    int x,l,r,m;
    frmlty
    {
        v.clear();
        le2(n,c);
        loop(i,0,n)
        {
            le(x);
            v.pb(x);
        }
        sort(v.begin(),v.end());
        l=1;
        r=1000000000;
        int ans;
        while(l<=r)
        {
            m=(l+r)/2;
            if(f(m)==1)
            {
                l=m+1;
                ans=m;
            }
            else r=m-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

