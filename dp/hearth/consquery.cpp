
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

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

ll ht[2000002]= {};
ll f[1000000+2];
int main()
{
    int n,m,l,r;
    le2(n,m);


    loop(i,1,n+1)
    f[i]=0;

    loop(i,0,m)
    {
        le2(l,r);
        f[l]++;
        f[r+1]--;
    }
    ll c=0;
    loop(i,1,n+1)
    {
        c=c+f[i];
        f[i]=c;
    }

    loop(i,0,2000002)
    ht[i]=0;
    loop(i,1,n+1)
    {
        ht[f[i]]++;
    }
    for(int i=2000000; i>=0; i--)
        ht[i]+=ht[i+1];

    int q;
    le(q);
    loop(i,0,q)
    {
        le(l);
        printf("%lld\n",ht[l]);
    }
    return 0;
}



