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
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int main()
{
    int n;
    frmlty
    {
        le(n);

        int a[n+1];
        vi v;
        loop(i,0,n)
        {
            v.pb(i+1);
            le(a[i+1]);
        }

        vi::iterator it,it1;
        int c=0;
        for(it=v.begin(); it<v.end(); it++)
        {
            c++;
            v.insert(it-a[c],*it);
            v.erase(it+1);
        }
        c=0;
        for(it=v.begin(); it<v.end(); it++)
        {
            c++;
            a[*it]=c;
        }
        loop(i,1,n+1)
        printf("%d ",a[i]);
        printf("\n");

    }
    return 0;
}

