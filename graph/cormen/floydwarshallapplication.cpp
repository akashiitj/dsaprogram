
#include <bits/stdc++.h>
#define inf 10000000000000LL
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll dp[102][102][255],tim[102][102],risk[102][102];//i to j reach karna in k time with min resk
int main()
{
    int test,n,t;
    cin>>test;
    while(test--)
    {
        cin>>n>>t;
        rep(i,0,n)rep(j,0,n)cin>>tim[i][j];
        rep(i,0,n)rep(j,0,n)cin>>risk[i][j];
        rep(i,0,n)rep(j,0,n)rep(k,0,t+1)dp[i][j][k]=inf;
        for(int i=0; i<n; i++)dp[i][i][0]=0;

        ll ans1 = inf,ans2;
        for(int k=0; k<=t; k++)
        {
            for(int l=0; l<n; l++)
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(l==i)continue;
                        if(k-tim[i][l]>=0)dp[i][j][k] = min(dp[i][j][k],risk[i][l]+dp[l][j][k-tim[i][l]]);
                        if(i==0&&j==n-1)
                        {
                            if(ans1>dp[i][j][k])
                            {
                                ans1=dp[i][j][k];
                                ans2=k;
                            }
                        }
                    }
        o        }
            }
        }
        if(ans1>=inf)cout<<-1<<endl;
        else cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}
