
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

ll mx;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define frmlty     ll test_case;cin>>test_case;while(test_case--)

#define vi        vector<ll>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<ll,ll>

#define msi       map<string,ll>
#define msit      map<string,ll>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(ll i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

#define infi 100000000000000LL

ll dp[105][105];
ll dp1[105][105];
int main()
{
    //cout<<mx<<"n";
    string s,ans;
    frmlty
    {
        loop(i,1,102+1)
        {
            loop(j,1,102+1)
            {
                dp[i][j]=0;
                dp1[i][j]=infi;
            }
        }

        cin>>s;
        int n=s.length();
        for(ll i=1; i<=n; i=i+2)
        {

            dp[i][i]=s[i-1]-'0';
            dp1[i][i]=dp[i][i];
        }
        for(ll l=3; l<=n; l=l+2)
        {
            for(ll i=1; i<=n-l+1; i=i+2)
            {
                for(ll j=i; j<i+l-1; j=j+2)
                    dp[i][i+l-1]=maX(dp[i][i+l-1],maX((dp[i][j]+dp[j+2][i+l-1])*(s[j]=='+'),(dp[i][j]*dp[j+2][i+l-1])*(s[j]=='*')));
            }
        }

        for(ll l=3; l<=n; l=l+2)
        {
            for(ll i=1; i<=n-l+1; i=i+2)
            {

                for(ll j=i; j<i+l-1; j=j+2)
                {
                    // cout<<i<<" "<<i+l-1<<"\n";
                    if(s[j]=='+')
                    {
                        // cout<<j<<" + "<<dp1[i][j]+dp1[j+2][i+l-1]<<" "<<dp1[i][i+l-1]<<"\n";
                        dp1[i][i+l-1]=miN(dp1[i][i+l-1],dp1[i][j]+dp1[j+2][i+l-1]);
                    }
                    else
                    {
                        //   cout<<j<<" * "<<dp1[i][j]+dp1[j+2][i+l-1]<<" "<<dp1[i][i+l-1]<<"\n";
                        dp1[i][i+l-1]=miN(dp1[i][i+l-1],dp1[i][j]*dp1[j+2][i+l-1]);
                    }

//                    loop(i,1,n+1)
//                    {
//                        loop(j,1,n+1)
//                        cout<<dp1[i][j]<<" ";
//                        cout<<"\n";
//                    }
//                    cout<<"\n\n";
                }
            }
        }
//        loop(i,1,n+1)
//        {
//            loop(j,1,n+1)
//            cout<<dp1[i][j]<<" ";
//            cout<<"\n";
//        }
        cout<<dp[1][n]<<" "<<dp1[1][n]<<"\n";


    }
    return 0;
}

