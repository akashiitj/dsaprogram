
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
    ll t,n,a[20],cnt;
    ll mn,mx;
    frmlty
    {
        cin>>n;
        cnt=0;
        for(int i=0;i<n;i++){lell(a[i]);if(a[i]!=0)cnt++;}
        if(cnt==0||cnt==1)
        {
            mn=a[0];mx=a[0];
            for(int i=1;i<n;i++)
            {
                mn = miN(mn,a[i]);
                mx = maX(mx,a[i]);
            }
            cout<<mx<<' '<<mn<<endl;
            continue;
        }
        sort(a,a+n);
        mx=1;
        ll negmax=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]!=0)mx=mx*a[i];
            if(a[i]<0)negmax = maX(negmax,a[i]);
        }
        mn=INT_MAX;
        if(a[0]>=0)
        {
            for(int i=0;i<n;i++)
            {mn=miN(mn,a[i]);

            }
        }
        else
        {
            if(mx<0){mn=mx;mx=mx/negmax;}
            else
            {
                mn = mx/negmax;
            }
        }
        cout<<mx<<' '<<mn<<endl;
    }
    return 0;
}

