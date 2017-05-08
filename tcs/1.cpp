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

char a[1005][1005];

int dp[1005][1005];
int dp1[1005][1005];

int dp3[1005][1005];
int dp4[1005][1005];

int main()
{
    int n;
    int v[4];
    frmlty
    {
        le(n);
        loop(i,1,n+1)
        loop(j,1,n+1)
        {
            cin>>a[i][j];


        }

        loop(i,1,1000+1)
        loop(j,1,1000+1)
        {


            dp[i][j]=0;

            dp1[i][j]=0;
            dp3[i][j]=0;
            dp4[i][j]=0;
        }


        if(n==1)
        {
            cout<<"0"<<"\n";
            continue;
        }

        loop(i,1,1+n)
        loop(j,1,n+1)
        {
            dp[i][j]+=dp[i][j-1]+(a[i][j]=='#');
            dp3[i][j]+=dp3[i][j-1]+(a[i][j]=='@');
        }


        loop(i,1,n+1)
        for(int j=n; j>=1; j--)
        {
            dp1[i][j]+=dp1[i][j+1]+(a[i][j]=='#');
            dp4[i][j]+=dp4[i][j+1]+(a[i][j]=='@');
        }




        loop(i,1,1+n)
        loop(j,1,n+1)
        {
            dp[j][i]+=dp[j-1][i];
            dp3[j][i]+=dp3[j-1][i];
        }

        loop(i,1,1+n)
        loop(j,1,n+1)
        {
            dp1[j][i]+=dp1[j-1][i];
            dp4[j][i]+=dp4[j-1][i];
        }

        int ans=INT_MAX;
        loop(i,1,n)
        {
            loop(j,1,n)
            {
                v[0]=dp[i][j]+dp3[i][j]*2;
                v[1]=dp1[i][j+1]+dp4[i][j+1]*2;
                v[2]=dp[n][j]-dp[i][j]+(dp3[n][j]-dp3[i][j])*2;
                v[3]=dp1[n][j+1]-dp1[i][j+1]+(dp4[n][j+1]-dp4[i][j+1])*2;

                sort(v,v+4);

                ans=miN(ans,v[3]-v[0]);
            }

        }
        cout<<ans<<"\n";

    }
    return 0;
}


