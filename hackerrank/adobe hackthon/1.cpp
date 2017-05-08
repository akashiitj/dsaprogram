
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



int main()
{
    int n;
    le(n);
    int a[n/2];
    int b[n/2];
    int x;
    int i1=0;
    int j1=0;
    int ia[n];
    map<int,int> m;
    loop(i,0,n)
    {
        le(x);
        if(x%2==0)a[i1++]=x;
        else b[j1++]=x;
        ia[i]=x;
        m[x]=i;

    }
    sort(a,a+n/2);
    sort(b,b+n/2);
    int fa[n];
    i1=0;
    j1=0;
    int ans=0;
    loop(i,0,n)
    {
        if(i%2==0)fa[i]=b[j1++];
        else fa[i]=a[i1++];
        if(fa[i]!=ia[i])ans++;
        ia[m[fa[i]]]=ia[i];
        m[ia[i]]=m[fa[i]];
        ia[i]=fa[i];
    }
    cout<<ans<<"\n";
    return 0;
}

