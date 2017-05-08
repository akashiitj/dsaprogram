//3.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define pi pair<ll,ll>
#define pii pair<pi,int>
#define f first
#define s second
#define mod 1000000007
#define pb push_back
int a[1111];
int N;
bool vis[111][111];
int dp[111][111];
int rec(int i,int j)
{
    if(vis[i][j]) return dp[i][j];
    vis[i][j]=1;
    int &ret=dp[i][j];
    if(i>j)
    {
        return ret=0;
    }
    int r1=0;
    int r2=0;
    int r3=0;
    int r4=0;
    for(int k=1; k<i; k++)
    {
        if(a[k]<a[i]) r1++;
        if(a[k]>a[i]) r2++;
        if(a[k]>a[j]) r3++;
        if(a[k]<a[j]) r4++;
    }
    for(int k=j+1; k<=N; k++)
    {
        if(a[k]<a[i]) r1++;
        if(a[k]>a[i]) r2++;
        if(a[k]>a[j]) r3++;
        if(a[k]<a[j]) r4++;
    }
    ret=rec(i+1,j)+min(r1,r2);
    ret=min(ret,min(r3,r4)+rec(i,j-1));
    return ret;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1; i<=N; i++)
        {
            cin >> a[i];
        }
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                vis[i][j]=0;
            }
        }
        cout<<rec(1,N)<<"\n";
    }
}
