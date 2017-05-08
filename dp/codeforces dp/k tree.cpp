

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

int dp[101][2]= {};

int main()
{
    int n,k1,d;
    le2(n,k1);
    le(d);

    ll ans=0;
    dp[0][0]=1;
    // dp[0][1]=1;
    loop(i,1,n+1)
    {
        loop(j,1,k1+1)
        {
            if(i-j>=0) dp[i][1]=(dp[i][1]+((dp[i-j][1]+dp[i-j][0]*(j>=d))%mod))%mod;
            if(i-j>=0) dp[i][0]= (dp[i][0]+ dp[i-j][0]*(j<d))%mod;
        }
    }

    cout<<dp[n][1]<<"\n";

    return 0;
}


/*
ll dp[101][101][2]={};

int main()
{
    int n,k1,d;
    le2(n,k1);le(d);

    ll ans=0;
    loop(i,1,100+1)
    {
        dp[1][i][0]=(i<d);
        dp[1][i][1]=(i>=d&&i<=k1);//you forgot this condition i<=k1 and loose confidence inspite of

         if(i==n)ans+=(dp[1][i][1]*(i<=k1));
    }

    loop(i,2,101)
    {
        loop(j,1,n+1)
        {
            loop(k,1,k1+1)
            {
                if(j-k>0&&(k<d))dp[i][j][0]+=(dp[i-1][j-k][0]*1);
                if(j-k>0&&(k>=d))dp[i][j][1]+=((dp[i-1][j-k][0]*1)+dp[i-1][j-k][1])%mod;
                if(j-k>0)dp[i][j][1]+=(dp[i-1][j-k][1])%mod;

                if(dp[i][j][0]>=mod)dp[i][j][0]%=mod;
                 if(dp[i][j][1]>=mod)dp[i][j][1]%=mod;
            }
           // cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<"    ";
            if(j==n)ans+=dp[i][j][1];
            if(ans>=mod)ans%=mod;

        }
        cout<<"\n";
    }
    cout<<ans<<"\n";

    return 0;
}
*/

