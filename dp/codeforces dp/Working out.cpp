
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

int dp1[1001][1001]= {};
int dp2[1001][1001]= {};
int dp3[1001][1001]= {};
int dp4[1001][1001]= {};
int a[1001][1001];
int main()
{
    int n,m;
    le2(n,m);
    loop(i,1,n+1)
    loop(j,1,m+1)
    le(a[i][j]);

    //  dp1[1][1]=a[1][0];
    loop(i,1,n+1)
    loop(j,1,m+1)
    dp1[i][j]= maX(dp1[i][j-1],dp1[i-1][j])+a[i][j];




    for(int i=n; i>=1; i--)
        loop(j,1,m+1)
        dp2[i][j]=maX(dp2[i+1][j],dp2[i][j-1])+a[i][j];






    for(int i=n; i>=1; i--)
    for(int j=m; j>=1; j--)
    dp3[i][j]=maX(dp3[i][j+1],dp3[i+1][j])+a[i][j];




    loop(i,1,n+1)
    for(int j=m; j>=1; j--)
     dp4[i][j]=maX(dp4[i][j+1],dp4[i-1][j])+a[i][j];



    int ans=-1;
    loop(i,2,n)
    loop(j,2,m)
    {
        ans=maX(ans,dp1[i][j-1]+dp2[i+1][j]+dp3[i][j+1]+dp4[i-1][j]);
        ans=maX(ans,dp2[i][j-1]+dp3[i+1][j]+dp4[i][j+1]+dp1[i-1][j]);

    }
    cout<<ans<<"\n";

    return 0;
}


