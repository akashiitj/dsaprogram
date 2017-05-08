#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define loop(i,a,b)      for(int i=a;i<b;i++)

#define mod       1000000007

ll mod1(ll x)
{
    return x%1000000007;
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

ll rm(ll x)
{
    return fast_mul(x,mod-2);
}

ll mp(ll x)
{
    while(x<0)x=x+mod;
    return x;
}

main()
{
    // cout<<fast_mul(10000000,10000000)<<endl;
    int t;
    cin>>t;
    ll n,k;
    ll a1,a2,a3,a4,a5,a6;
    while(t--)
    {

}
 }
}
