
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

vll v[65];

int main()
{
    int n;
    ll x,xd;
    int c1;
    frmlty
    {
        le(n);
        loop(i,0,65)
        v[i].clear();
        loop(i,0,n)
        {
            lell(x);
            xd=x;
            c1=0;
            while(x!=0)
            {
                if((x%2)==1)c1++;
                x=x/2;
            }
            v[c1].pb(xd);
        }
        loop(i,0,65)
        {
            loop(j,0,v[i].size())
            printf("%d ",v[i][j]);
        }
        cout<<"\n";
    }
    return 0;
}

