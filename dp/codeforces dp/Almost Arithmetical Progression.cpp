
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

int dp[4001][4001]= {};
int ht[1000001]= {};
int a[4001];

int main()
{
    int n;
    le(n);
    loop(i,0,n)
    le(a[i]);
    int t=1;
    loop(i,0,n)
    {
        if(ht[a[i]]==0)ht[a[i]]=t,t++;
        a[i]=ht[a[i]];
    }
    int ans=0;
    loop(i,0,n)
    {
        loop(j,0,i)
        {

            dp[i][a[j]]=maX(dp[j][a[i]]+1,dp[i][a[j]]);
            ans=maX(ans,dp[i][a[j]]);
        }
    }
    cout<<ans+1<<"\n";
    return 0;
}


