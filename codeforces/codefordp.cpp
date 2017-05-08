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

ll dp[100001];
ll ha[100001];


int main()
{
    fast;
    //declare variable here
    int n;
    cin>>n;
    loop(i,0,n+1)
    {
        dp[i]=0;
        ha[i]=0;
    }
    int x;
    loop(i,1,n+1)
    {
        cin>>x;
        ha[x]++;
    }
    dp[1]=1*ha[1];
    loop(i,2,100001)
    {
        dp[i]=max(dp[i-2]+i*ha[i],dp[i-1]);
    }
    cout<<dp[100000]<<endl;
      return 0;
}
