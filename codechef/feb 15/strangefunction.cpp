#include <bits/stdc++.h>

using namespace std;
#define loop(i,a,b) for(ll i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
ll f[10000001];

int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    //  a[0]=0;
//    cs[0]=0;
    f[1]=1;
    //a[1]=1;
    //cs[1]=1;
    loop(i,2,m+1)
    {
        f[i]=f[i-1]*i;
        if(f[i]>=m)f[i]=f[i]%m;
    }


    ll ans=0;
    ll p;
    loop(i,1,n+1)
    {
        cin>>p;
        ll ans1=0;
        if((p%2)==0)
        {
            //cout<<"s";
            ll p2=p%m;
            ll p1=p/2;
            //cout<<p1<<endl;
            p1=p1%m;
            //cout<<p1<<endl;
            p1=p1*p2;
            // cout<<p1<<endl;
            p1=p1%m;
            p1=p1*(p2+1);
            // cout<<p1<<endl;
            ans1=p1;
            if(ans1>=m)ans1=ans1%m;

        }
        else
        {  ll p2=p%m;
            ll p1=(p+1)/2;
            p1=p1%m;
            p1=p1*p2;
            p1=p1%m;
            p1=p1*(p2);
            ans1=p1;
            if(ans1>=m)ans1=ans1%m;

        }
        //cout<<ans1<<endl;
        ll ans12=ans1;
        if(p<m)
        {
            //  ans1=ans1+cs[p];
            ans12=ans12+f[p+1]-1;
            if(ans12<0)ans12=ans12+10*m;
            ans12=ans12%m;
        }
        else
        {
            ans12=ans12+f[m]-1;
            if(ans12<0)ans12=ans12+10*m;
            ans12=ans12%m;
        }
        if(ans12>=m)ans12=ans12%m;
        //    cout<<ans1<<endl;
        ans=ans+ans12;
        if(ans>=m)ans=ans%m;
    }
    if(ans<0)ans=ans+10*m;
    cout<<ans%m<<endl;

    return 0;
}

