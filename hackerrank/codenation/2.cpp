#include <bits/stdc++.h>

using namespace std;
#define loop(i,a,b) for(ll i = a; i < b; i++)
typedef double db;
//typedef long long ll;
typedef  long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll mod1(ll x)
{
    return x%1000000000;
}

ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=mod1(C)*mod1(A);
            C=mod1(C);
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=mod1(mod1(A)*mod1(A));
        pow>>=1;
    }
    return mod1(C);
}

ll a[11]= {1,1,1,3,3,15,15,105,105,105,105};

ll rf(ll n)
{
    if(n<=10)return a[n];
    ll ans=mod1(fast_mul(2,ceil(db(n)/db(4))));
    ans=ans*mod1(rf(ceil(db(n)/db(5))));
    ans=mod1(ans);
    ans=ans*rf(ceil(db(n)/db(10)));
     return mod1(ans);
}
int main()
{  cout<<__gcd(5,3);
    std::ios_base::sync_with_stdio(false);
//cout<<ceil((double)5/(double)4);
    ll t,n;
    cin>>t;
    ll a[6];
    while(t--)
    {
        cin>>n;
        ll no=rf(n);


        loop(i,1,6)
        a[i]=no*i;
        ll max1=-1;
        ll ansh=fast_mul(a[1],a[1]);
        if(max1<ansh)max1=ansh;
         ansh=fast_mul(a[1],a[2]);
        if(max1<ansh)max1=ansh;
        ansh=fast_mul(a[1],a[3]);
        if(max1<ansh)max1=ansh;
        ansh=fast_mul(a[1],a[4]);
        if(max1<ansh)max1=ansh;
        ansh=fast_mul(a[1],a[5]);
        if(max1<ansh)max1=ansh;
        ansh=fast_mul(a[2],a[3]);
        if(max1<ansh)max1=ansh;
        ansh=fast_mul(a[2],a[5]);
        if(max1<ansh)max1=ansh;
        ansh=fast_mul(a[3],a[4]);
        if(max1<ansh)max1=ansh;
        ansh=fast_mul(a[3],a[5]);
        if(max1<ansh)max1=ansh;
        ansh=fast_mul(a[4],a[5]);
        if(max1<ansh)max1=ansh;
        cout<<max1<<endl;
    }
    return 0;
}
