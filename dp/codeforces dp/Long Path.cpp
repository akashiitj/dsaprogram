
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";
ll dp[1001]= {};

int main()
{    //cout<<"c1"<<"\n";
    int n;

    le(n);
    int pre[n+1];
    loop(i,1,n+1)
    le(pre[i]);
    ll ans=2;
    dp[1]=2;//forgot this
    loop(i,2,n+1)
    {
        dp[i]=2;
        loop(j,pre[i],i)
        {

            dp[i]+=dp[j];
            if(dp[i]>=mod)dp[i]%=mod;

        }
        //cout<<dp[i]<<" f ";
        ans=ans+dp[i];
            if(ans>=mod)ans%=mod;
    }
    cout<<ans<<"\n";//you are first printing dp[n] read q carefully
    return 0;
}


