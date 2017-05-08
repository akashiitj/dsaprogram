
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

int a[10];//length of words array

int cost[11][11];//it store cost of putting from ith to jth word in single line

int dp[11];// it store optimal cost of putting word from 1 to ith

int infi=100000;

int main()
{
    int n,w;
    le2(n,w);
    loop(i,1,n+1)
    le(a[i]);

    loop(i,1,n+1)
    {
        cost[i][i]=w-a[i];
        loop(j,i+1,n+1)
        {
            cost[i][j]=cost[i][j-1]-a[j]-1;//it is bachi hui space
        }
    }

    loop(i,1,n+1)
    {
        cost[i][i]*=cost[i][i];
        loop(j,i+1,n+1)
        {
            if(cost[i][j]>=0) cost[i][j]=pow(cost[i][j],2);//1 from
            else cost[i][j]=infi;
        }
    }
  int bt[10];
    loop(i,1,n+1)
    {
        dp[i]=cost[1][i];
        bt[i]=i;
        loop(j,1,i)
        {   if(dp[j]+cost[j+1][i]<dp[i])bt[i]=j;
            dp[i]=miN(dp[i],dp[j]+cost[j+1][i]);
        }
    }
    int x=n;
    while(bt[x]!=x)
    {
        cout<<bt[x]<<" ";
        x=bt[x];
    }
    cout<<"\n";

    cout<<dp[n]<<"\n";

    return 0;
}

