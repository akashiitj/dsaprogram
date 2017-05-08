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

ll a[100001]={0};
int main()
{
 std::ios_base::sync_with_stdio(false);
 ll t,n,x;
 cin>>t;
 while(t--)
 {
     cin>>n;
     loop(i,1,n+1)
     {
         cin>>x;
         a[x]++;
     }
     ll mx=0;
     loop(i,1,100001)
     {mx=max(mx,a[i]);
      a[i]=0;
     }

     cout<<n-mx<<endl;
 }
 return 0;
}

