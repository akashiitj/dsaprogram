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


int main()
{
 std::ios_base::sync_with_stdio(false);
 int t,n;
 int a[1001];
 cin>>t;
 while(t--)
 {
     cin>>n;
     loop(i,0,n)
     cin>>a[i];
     sort(a,a+n,greater<int>());
     ll ans=0;
     for(int i=0;i<n;i=i+4)
     {
         int x=i;
         if(x<n)
         {

            ans=ans+a[x];
            x++;
         }
         if(x<n)
         {
              ans=ans+a[x];
            x++;
         }

     }
     cout<<ans<<endl;
 }
 return 0;
}

