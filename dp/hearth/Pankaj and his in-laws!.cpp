
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


int main()
{
    int n;
    le(n);
    int a[n];
    int dp[n];
    loop(i,0,n)
    {le(a[i]);
     dp[i]=1;
    }
    int ans=1;
    loop(i,0,n)
    {
        loop(j,0,i)
        if(a[j]<=a[i])dp[i]=maX(dp[j]+1,dp[i]);

        ans=maX(ans,dp[i]);
      }
      vi v;
      while(ans!=0)
      {
          v.pb(ans%2);
          ans=ans/2;
      }
      loop(i,0,v.size())
      cout<<v[v.size()-i-1];
      cout<<endl;
    return 0;
}



