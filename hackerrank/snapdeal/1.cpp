
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

int a[1000000];

int main()
{
    int n,q;
    le2(n,q);
    loop(i,0,n)
    le(a[i]);


    vi v;
    int t;
    int x;
    int k;
    int c=0;
    int ans;
    loop(i1,0,q)
    {
        le2(x,k);
        le(t);
        c=0;
        ans=-1;
        if(t==0)
        {

            loop(i,0,n)
            {
                if(a[i]>x)
                {
                    if(i+k-1<n)ans=a[i+k-1];
                    break;
                }
            }


        }
        if(t==1)
        {

            loop(i,0,n)
            {
                if(a[i]<x)
                {
                    c++;
                    v.pb(a[i]);
                }
                else break;
            }
            reverse(v.begin(),v.end());
            if(v.size()<k)ans=-1;
            else ans=v[k-1];
        }
        cout<<ans<<"\n";
    }
    return 0;
}

