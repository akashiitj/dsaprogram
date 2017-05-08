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

void nswap(vi &a,int k)
{
    int n=a.size();
    loop(i,0,n)
    {
        int c=0;
        int j=i+1;
        int lsp=i;
        int lbn=a[i];
        while(c<k&&j<n)
        {
            if(a[j]>lbn&&j-i<=k)
            {
                lsp=j;
                lbn=a[j];
                c=j-i;
            }

            j++;
        }

        if(lsp!=i)
        {
            for(int i1=lsp;i1>i;i1--)
                a[i1]=a[i1-1];
            a[i]=lbn;
        }
        k=k-c;
        if(k<=0)break;
    }

}

int main()
{
    vector<int> v;
    v.pb(1);
    v.pb(2);
    v.pb(4);
    v.pb(3);
    nswap(v,1);
    loop(i,0,v.size())
    cout<<v[i]<<" ";
    return 0;
}

