
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

bool a[1000000001];

void seive()
{
    a[0]=1;
    a[1]=1;
    for(int i=2; i*i<=1000000000; i++)
    {
        if(a[i]==0)
            for(int j=i*i; j<=1000000000; j=j+i)
                a[j]=1;
    }
}

int main()
{   seive();
    int n,m;
    frmlty
    {
        le2(n,m);
        loop(i,n,m+1)
        if(a[i]==0) printf("%d\n",i);
        printf("\n");

    }
    return 0;
}

