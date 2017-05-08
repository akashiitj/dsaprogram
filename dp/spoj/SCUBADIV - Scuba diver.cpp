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

int dp[1001][100][100];
int o[1001];
int n[1001];
int w[1001];

int infi=100000000;

int main()
{
    int on,nn;
    int n1;
    frmlty
    {
        le2(on,nn);
        le(n1);
        loop(i,1,n1+1)
        {
            le2(o[i],n[i]);
            le(w[i]);
        }

        loop(i,0,100)
        loop(j,0,100)
        dp[0][i][j]=infi;

        dp[0][0][0]=0;

        loop(i,1,n1+1)
        {
            loop(op,0,on+1)//i hr waste just due to start from 1;
            loop(np,0,nn+1)
            {   if(op==0&&np==0)continue;
                dp[i][op][np]=infi;
                if(dp[i-1][op][np]<infi)dp[i][op][np]=dp[i-1][op][np];
                if(dp[i-1][maX(op-o[i],0)][maX(np-n[i],0)]<infi) dp[i][op][np]=miN( dp[i-1][op][np],dp[i-1][maX(op-o[i],0)][maX(np-n[i],0)]+w[i]);


            }
        }

        cout<< dp[n1][on][nn]<<"\n";
    }
    return 0;
}
