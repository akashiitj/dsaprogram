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

string a,b;

int dp[1001][1001];

int ht[26];

int f()
{   int n1=a.length();
    int n2=b.length();

    loop(i,0,n2+1)
    dp[0][i]=i;

    loop(i,0,n1+1)
    dp[i][0]=i;

    loop(i,1,n1+1)
    {
        loop(j,1,n2+1)
        {
            dp[i][j]=miN(miN(dp[i][j-1]+1,dp[i-1][j]+1),dp[i-1][j-1]+(a[i-1]!=b[j-1]));
            if(i>=2&&j>=2&&a[i-1]==b[j-2]&&ht[b[j-1]-'a']!=-1)dp[i][j]=miN(dp[i][j],dp[ht[b[j-1]-'a']-1][j-2]+i-ht[b[j-1]-'a']);



           // cout<<dp[i][j]<<" ";
        }
        ht[a[i-1]-'a']=i;
       // cout<<"\n";
    }
    return dp[n1][n2];
}

int main()
{
    while(true)
    {
        cin>>a>>b;
        if(a=="*"&&b==a)
            break;
        loop(i,0,26)
        ht[i]=-1;
        printf("%d\n",f());
    }
    return 0;
}

