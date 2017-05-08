#include <bits/stdc++.h>

using namespace std;
#define loop(i,a,b) for(ull i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
//#define f first
#define s second

int a[10001];
int dp[10001];
int print[10001];


int f(int n)
{  *max_element()
    if(dp[n]!=-1)
        return dp[n];
    int ans=1;
    loop(i,1,n)
    {
        if(a[i]<=a[n])
            ans=max(ans,f(i)+1);
        else f(i);
    }
   // cout<<ans<<" "<<n<<endl;
    dp[n]=ans;
    return ans;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    loop(i,1,n+1)
    cin>>a[i];

    int ans=-1;
   f(n);
    loop(i,1,n+1)
    {   dp[i]=-1;
        print[i]=-1;

    }
     f(n);
     loop(i,1,n+1)
    {
        ans=max(ans,dp[i]);
    }
    loop(i,1,n+1)
    cout<<dp[i]<<" ";
    cout<<endl;
    cout<<ans<<endl;
}

