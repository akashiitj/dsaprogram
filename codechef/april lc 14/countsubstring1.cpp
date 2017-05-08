
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)

ll mod(ll x)
{
    return x%1000003;
}

ll cs[100000];

int main()
{
    fast;
    //declare variable here
    ll n,l,r,c;

    frmlty
    {
        cin>>n>>l>>r;
        ll c=r-l+1;
        loop(j,0,c)
        cs[j]=1;
        ll ans=0;
        loop(i,0,n)
        {
            loop(j,1,c)
            {
                cs[j]=cs[j-1]+cs[j];
                if(cs[j]>=1000003)cs[j]=mod(cs[j]);
            }
            ans=ans+cs[c-1];
            if(ans>=1000003)
                ans=mod(ans);
        }
        cout<<ans<<endl;
    }



return 0;
}
