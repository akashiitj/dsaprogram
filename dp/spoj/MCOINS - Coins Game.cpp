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

int dp[1000001][2];
int mem[1000001][2];
int k,l,m;

void init()
{
    dp[0][0]=1;
    dp[0][1]=0;

    loop(i,1,1000001)
    {
        dp[i][0]=1;//you forgot ths condition
        if(dp[i-1][1]==0)dp[i][0]=0;
        if(l<=i&&dp[i-l][1]==0)dp[i][0]=0;
        if(k<=i&&dp[i-k][1]==0)dp[i][0]=0;

        dp[i][1]=0;
        if(dp[i-1][0]==1)dp[i][1]=1;
        if(l<=i&&dp[i-l][0]==1)dp[i][1]=1;
        if(k<=i&&dp[i-k][0]==1)dp[i][1]=1;
    }
}

int main()
{
    le2(k,l);
    le(m);
    int n;
    init();
    string s;

    loop(i,0,m)
    {
        le(n);
        if(dp[n][0]==0)
            s=s+'A';
        else
            s=s+'B';
    }
    cout<<s<<"\n";
    return 0;
}

