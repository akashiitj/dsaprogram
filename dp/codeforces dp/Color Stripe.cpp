

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

int dp[500001][27];
int trace[500001][27];

int main()
{
    int n,k;
    le2(n,k);
    string s;
    cin>>s;
    loop(i,0,k)
    {
        if(s[0]!=('A'+i))dp[0][i]=1;
        // cout<<dp[0][i]<<" ";
    }
    //cout<<"\n";

    char c,ac;
    int hv1;
    int hv=INT_MAX;
    loop(i,1,n)
    {
        loop(j,0,k)
        {
            dp[i][j]=INT_MAX;
            loop(k1,0,k)
            {
                if(k1!=j)
                {
                    if(dp[i][j]> (dp[i-1][k1]+((j+'A')!=s[i])))
                   {

                        hv1=k1;
                    dp[i][j]=dp[i-1][k1]+((j+'A')!=s[i]);
                   }
                }
            }
            trace[i][j]=hv1;


        }


    }
    int ans=INT_MAX;
    int ansi;
    loop(j,0,k)
    {
        if(ans>dp[n-1][j])ansi=j;
        ans=miN(ans,dp[n-1][j]);

    }
    vi v;
    v.pb(ansi);
    for(int j=n-1; j>=1; j--)
    {
        v.pb(trace[j][ansi]);
        ansi=trace[j][ansi];
    }

    cout<<ans<<"\n";
    loop(i,0,n)
    printf("%c",(v[v.size()-1-i]+'A'));
    cout<<"\n";
    return 0;
}


