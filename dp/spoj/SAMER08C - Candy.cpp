#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000000007

int main()
{
    fast;
    int m,n;
    while(true){
    cin>>m>>n;
    int a[m][n];
    if(m==0&&n==0)
        return 0;


    loop(i,0,m)
    loop(j,0,n)
    cin>>a[i][j];
 //cout<<endl;
    int dp[m];
    int dp1[n+1];
    loop(i,0,m)
    {   dp1[0]=0;
        dp1[1]=a[i][0];
        loop(j,2,n+1)
        {
            dp1[j]=max(dp1[j-1],dp1[j-2]+a[i][j-1]);
          //  cout<<dp1[j]<<" ";
        }
       // cout<<endl;
        dp[i]=dp1[n];
    }

    // loop(i,0,m)
     //cout<<dp[i]<<" ";
     //cout<<endl;

    int ans[m+1];
    ans[0]=0;
    ans[1]=dp[0];
    loop(i,2,m+1)
    {
        ans[i]=max(ans[i-1],ans[i-2]+dp[i-1]);
    }

    cout<<ans[m]<<endl;

    }
return 0;
}

