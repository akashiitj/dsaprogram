
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

int main()
{    string s;
     int n;
    frmlty
    {
        cin>>s;
        n=s.length();
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
        dp[2]=0;
        int ans=0;
        loop(i,3,n+1)
        {   dp[i]=0;
            if(!(s[i-1]==s[i-2]&&s[i-2]==s[i-3]))
                dp[i]=3+dp[i-3];
            ans=maX(ans,dp[i]);

        }
        printf("%d\n",n-ans);
    }
    return 0;
}

