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


int main()
{    string s;
     int n;
     int x;
     while(true)
     {    cin>>s;
          if(s=="0")break;
          n=s.length();
          ll dp[n+1];
          dp[0]=1;
          dp[1]=1LL;
          loop(i,2,n+1)
          {   dp[i]=0;
               if(s[i-1]!='0') dp[i]=dp[i-1];
                x=s[i-1]-'0';
                x=((s[i-2]-'0')*10+x);
                if(x<=26&&x>=10)dp[i]+=dp[i-2];
               //cout<<x<<" ";
                //cout<<dp[i]<<"\n";
          }
          //cout<<"\n";
          cout<<dp[n]<<"\n";

     }
    return 0;
}

