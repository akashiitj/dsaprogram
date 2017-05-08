
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

ll dp[10][2];
ll ans[65];

int main()
{
    loop(i,0,10)
    dp[i][0]=i+1LL;

    int pre=0;
    int cur=1;

    ans[1]=dp[pre][9];

    loop(i,2,65)
    {   dp[0][cur]=1LL;
        loop(i,1,10)
        {
            dp[i][cur]=dp[i-1][cur]+dp[i][pre];//number of req string ending at digit cur or smaller
          //  cout<<dp[i][cur]<<" ";
        }
        //cout<<"\n";
        swap(pre,cur);
        ans[i]=dp[9][pre];

    }
    int n,x;
    ans[1]=10;
    frmlty
    {   le2(x,n);
        //le(n);
        cout<<x<<" "<<ans[n]<<"\n";
    }
    return 0;
}

