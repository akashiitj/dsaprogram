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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int dp[50][51][27];//the minimum number of brushes required to paint position
//   left, left+1, ... , left+size-1 of the original strip,
// assuming these position currently has color k.
//size in j left means i
//in simple words if string starting at i index havinh color k and has length in j how many minimum operation
//we have to do to convert it in given string

int minStrokes(string s,int i,int j,int k)
{
    int mini;
    if(j==0)return 0;
    if(dp[i][j][k]!=0)return dp[i][j][k];
    if((s[i]-64)==k)
    {
        dp[i][j][k]=minStrokes(s,i+1,j-1,k);
        return dp[i][j][k];
    }
    else
    {
        mini=1000000;
        for(int x=1; x<=j; x++)
            mini=min(mini,1+minStrokes(s,i+1,x-1,s[i]-64)+minStrokes(s,i+x,j-x,k));
    }
    dp[i][j][k]=mini;
    return mini;
}

int minStrokes(string s)
{
    return minStrokes( s,0,s.length(),0);
}
int fbottomup(string s)
{
    loop(l,1,s.length()+1)
    {
        loop(i,0,s.length()-l+1)
        {
            loop(j,0,27)
            {   dp[i][l][j]=10000;
                if(s[i]-64==j)dp[i][l][j]=dp[i+1][l-1][j];
                else{
                    loop(k,0,l)
                    {
                        dp[i][l][j]=min(dp[i][l][j],1+dp[i+1][k][s[i]-64]+dp[i+k+1][l-k-1][j]);
                    }
                }
            }
        }
    }
    return dp[0][s.length()][0];
}

main()
{

    while(true)
    {
        string s;
        cin>>s;
        cout<<fbottomup(s);
    }
}
