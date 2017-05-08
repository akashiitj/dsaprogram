#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

ll MOD=1000003;

ll countFact(ll n,ll p)
{
   ll k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}


ll pow(ll a,ll b,ll MOD)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n,ll MOD)
{
    return pow(n,MOD-2,MOD);
}

ll factMOD(ll n,ll MOD)
{
    ll res = 1;
    while (n > 0)
    {
        for (ll i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}

ll nCr(ll n,ll r,ll MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;

    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) *
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}


int main()
{


    fast;
    //declare variable here
    ll n,l,r,c;

    frmlty
    {
       cin>>n>>l>>r;
        ll k=r-l+1;
        ll ans=nCr(n+k,n,MOD)%MOD;
        while(ans<0)
			ans=ans+10*MOD;
		ans--;
		ans=(ans+MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
