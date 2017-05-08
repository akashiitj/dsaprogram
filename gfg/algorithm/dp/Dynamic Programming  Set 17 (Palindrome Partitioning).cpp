#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

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

string s;
int dp[100][100];
int isp[100][100];
int f(string s)
{
    int n=s.length();
    loop(i,0,n)
    {
        isp[i][i]=1;
        if(i<n-1)
        {
            isp[i][i+1]=(s[i]==s[i+1]);
            dp[i][i+1]=(1-isp[i][i+1]);
        }
    }

    loop(l,3,n+1)
    {
        loop(i,0,n-l+1)
        {
            dp[i][i+l-1]=INT_MAX;
            isp[i][i+l-1]=(isp[i+1][i+l-2]&&s[i]==s[i+l-1]);
            if(isp[i][i+l-1])dp[i][i+l-1]=0;
            else
            {
                loop(j,i,i+l-1)
                {
                    dp[i][i+l-1]=miN(dp[i][i+l-1],dp[i][j]+dp[j+1][i+l-1]+1);
                }
            }
            cout<<isp[i][i+l-1]<<" "<<dp[i][i+l-1]<<" "<<i<<" "<<i+l-1<<"\n";
        }
    }
    loop(i,0,n)
    {
        loop(j,0,n)
        {
        cout<<isp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

     loop(i,0,n)
    {
        loop(j,0,n)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return dp[0][n-1];
}

int main()
{
    cin>>s;
    cout<<f(s);
    return 0;
}


