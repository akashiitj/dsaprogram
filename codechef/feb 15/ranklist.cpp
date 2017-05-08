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
#define f first
#define s second

ll sum(ll x)
{
    return (x*(x+1))/2;
}
int main()
{
 std::ios_base::sync_with_stdio(false);
 int t;
 ll n,s;
 cin>>t;
 while(t--)
 {
     cin>>n>>s;
     ll a[n+1];
     ll b[n+1];
     loop(i,1,n+1)
     {
         a[i]=sum(i)+n-i;
         b[i]=sum(i)+(n-i)*i;
     }
     ll ans;
     for(ll i=n;i>=1;i--)
     {
         if(s<=b[i]&&s>=a[i]){ans=i;break;}
     }
     cout<<n-ans<<endl;

 }
 return 0;
}
