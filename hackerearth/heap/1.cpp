
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

priority_queue<int > p;
int main()
{   int n;
    le(n);
    int a;
    vll v;
    int x,y,z;
    loop(i,0,n)
    {
        le(a);
        p.push(a);
        if(i>=2)
        {
            x=p.top();
            p.pop();
            y=p.top();
            p.pop();
            z=p.top();
            p.pop();
            v.pb(x*1LL*y*1LL*z);
            p.push(x);
            p.push(y);
            p.push(z);

        }
        else v.pb(-1);
    }
    loop(i,0,v.size())
    cout<<v[i]<<"\n";
    //cout<<"\n";
    return 0;
}

