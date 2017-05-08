#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

ll dp[100001][2]= {};

int main()
{
    ll n,k;
    le2ll(n,k);
    ll a[n];

    ll totalgrp=1;
    ll cs=0;
    loop(i,0,n)
    {
        lell(a[i]);
        cs=cs+a[i];
        totalgrp=(totalgrp*2)%mod;
    }

    dp[0][0]=1;
    dp[0][1]=1;
    int pre=0,cur=1;
    loop(j,0,n)
    {
        loop(i,1,k)
        dp[i][cur]=dp[i][pre];//you forget this ,you are also not using pre cur due to which number is adding multiple times
        loop(i,1,k)
        {
            //      if(i==8&&a[j]<=i)cout<<dp[i-a[j]]<<" ";
            if(a[j]<=i)dp[i][cur]+=dp[i-a[j]][pre];
            if(dp[i][cur]>=mod)dp[i][cur]=dp[i][cur]%mod;

        }
//        loop(i,0,k)
//    cout<<dp[i][pre]<<" ";
//    cout<<"\n";
//
//    loop(i,0,k)
//    cout<<dp[i][cur]<<" ";
//    cout<<"\n\n";
        swap(pre,cur);


    }

//    loop(i,0,k)
//    cout<<dp[i][pre]<<" ";
//    cout<<"\n";

    ll subtract=0;
    loop(i,0,k)
    {
        if(cs-i<k)
            subtract+=dp[i][pre];
        else subtract+= 2*dp[i][pre];

        if(subtract>=mod)subtract%=mod;
    }
    totalgrp=(totalgrp-subtract)%mod;
    while(totalgrp<0)totalgrp+=mod;

    cout<<totalgrp<<"\n";

    return 0;
}

