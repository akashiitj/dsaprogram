
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

int ht[101];

int dp[101][6000];//using element upto i what is frequency of each j;


int main()
{
    int n;

    int x;
    int ans=0;
    frmlty
    {
        ans=0;
        memset(ht,0,sizeof ht);
        memset(dp,0,sizeof dp);
        le(n);
        loop(i,0,n)
        {
            le(x);
            ht[x]++;

            if(ht[x]>=2)
                ans=1;
        }
        if(ans==1)
        {
            cout<<"YES\n";
            continue;
        }
        dp[0][0]=1;
        loop(i,1,101)
        {
            dp[i][0]=1;
            loop(j,1,5051)
            {
                dp[i][j]=dp[i-1][j];
                if(ht[i]>0) if(j-i>=0)dp[i][j]+=dp[i-1][j-i];
                if(dp[i][j]>=2)ans=1;//we are done if we found subset whose frequency is more than 2;
            }
        }

        if(ans==1)
        {
            cout<<"YES\n";
        }
        else cout<<"NO"<<"\n";
    }
    return 0;
}

