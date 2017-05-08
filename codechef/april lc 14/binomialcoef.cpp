#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll modularPow(ll base,ll exponent)
{
    ll res = 1;
    while(exponent)
    {
        if(exponent&1)
        {
            res = (res*base)%1000003;
        }
        exponent >>= 1;
        base = (base*base)%1000003;
    }
    return res;
}

ll fact[1000005],factMultInv[1000005];

void pre()
{
    ll p=1,q=1;
    fact[0] = 1;
    factMultInv[0] = 1;
    for(ll t=1;t<=1000003;t++)
    {
         p *= t;
         p %= 1000003;
         fact[t] = p;

         q *= modularPow(t,1000001);
         q %= 1000003;
         factMultInv[t] = q;
    }
}


int main()
{

    pre();
    ll test;
    cin>>test;
    while(test--)
    {
        ll result=1;
        ll n,l,r,k;
        cin>>n>>l>>r;
        k=r-l+1;

        while(n)
        {   n=n+k;
            ll N = n%1000003;
            ll K = k%1000003;
            if(N<K)
            {
                result = 0;
                break;
            }
            result *= (fact[N]*factMultInv[K]*factMultInv[N-K])%1000003;
            result %= 1000003;
            n /=1000003;
            k /=1000003;
        }
        result--;
        while(result<0)result=result+1000003;
        result=result%1000003;
        cout << result << endl;
    }
    return 0;
}
