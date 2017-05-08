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

int n, m, x ,y;
int cshs[1001]= {};
int csdt[1001]= {};

int dp[1001][2]= {};

int main()
{
    le2(n,m);
    le2(x,y);
    char hv;
    loop(i,1,n+1)
    loop(j,1,m+1)
    {
        cin>>hv;
        if(hv=='#')
            cshs[j]++;
        else csdt[j]++;
    }

    loop(j,1,m+1)
    csdt[j]+=csdt[j-1],cshs[j]+=cshs[j-1];

    loop(i,1,m+1)
    {
        dp[i][0]=1000000;
        dp[i][1]=1000000;
        if(i<x)continue;
        loop(j,maX(i-y,0),maX(i-x,0)+1)
        {
            dp[i][0]=miN(dp[j][1]+csdt[i]-csdt[j],dp[i][0]);
            dp[i][1]=miN(dp[j][0]+cshs[i]-cshs[j],dp[i][1]);
        }
    }
    cout<<miN(dp[m][0],dp[m][1])<<"\n";
    return 0;
}


