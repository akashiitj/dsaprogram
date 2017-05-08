//author akashiitj
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

#define tk(x) scanf("%d",&x);
#define tk2(x,y) scanf("%d%d",&x,&y);
#define tkll(x) scanf("%lld",&x);
#define tk2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

int max_subsequence(vector<int> v)
{
    int n=v.size();
    int ans=1;
    vector<int> dp(n,1);
    loop(i,0,n)
    {
        loop(j,0,i)
        {
            if(v[j]<v[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n;
    vector<int> a(n);
    loop(i,0,n)
        cin>>a[i];
    cout<< max_subsequence(a);
}


