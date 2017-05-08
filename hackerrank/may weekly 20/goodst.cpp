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



#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000

ll mod1(ll x)
{
    return x%1000;
}



ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=C*A;
            if(C>mod) C=mod1(C);
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=A*A;
        if(A>mod) A=mod1(A);
        pow>>=1;
    }
    return mod1(C);
}


int main()
{
    fast;
    //declare variable here
    string s;
    cin>>s;

    ll a[26];

    loop(i,0,26)
    a[i]=0;

    loop(i,0,s.length())
    a[s[i]-97]++;

    ll ans=1;
    a[s[0]-97]=1;

    loop(i,0,26)
    if(a[i]!=0)ans=(ans*a[i])%1000;

    cout<<ans<<endl;
}

