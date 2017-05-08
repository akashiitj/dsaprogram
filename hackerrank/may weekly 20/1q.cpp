#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     ll test_case;cin>>test_case;while(test_case--)

#define vi        vector<ll>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<ll,ll>

#define msi       map<string,ll>
#define msit      map<string,ll>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(ll i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       10000009

ll a[100001];

ll cs[100001];
int main()
{
    fast;
    //declare variable here
    frmlty{
    ll n,l,r;
    cin>>n>>l>>r;
    loop(i,1,n+1)
    cin>>a[i];

    ll c=0;
    vi v;

    loop(i,1,n+1)
    {
        if(a[i]<=r&&a[i]>=l)continue;
        c++;
         v.push_back(min(abs(a[i]-l),abs(a[i]-r)));
    }
    sort(v.begin(),v.end());
    cs[0]=0;
    loop(i,1,v.size()+1)
    cs[i]=cs[i-1]+v[i-1];

    loop(i,1,n+1)
    {
        if(i>c)
            cout<<0<<" ";
        else cout<<cs[c-(i-1)]<<" ";
    }
    cout<<endl;
}
return 0;
}

