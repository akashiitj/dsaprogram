//https://www.hackerearth.com/problem/algorithm/roy-and-ropes/


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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int dp[1000001];
int l[1000001];
int u[1000001];
int main()
{   int len;
    frmlty
    {   le(len);
        loop(i,1,len)
        {
            le(l[i]);
        }
         loop(i,1,len)
        {
            le(u[i]);
        }
        dp[0]=0;
         loop(i,1,len)
         {
             dp[i]=maX(dp[i-1],i+maX(l[i],u[i]));
         }
         cout<<maX(dp[len-1],len)<<"\n";
    }
    return 0;
}



