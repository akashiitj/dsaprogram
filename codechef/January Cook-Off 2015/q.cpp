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
    int y,n,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        double a[n][m];
        loop(i,0,n)
        {
            loop(j,0,m)
            {
               a[i][j]=0.0;
            }}
            a[0][0]=1.0;
        loop(i,0,n)
        {
            loop(j,0,m)
            {
               if(i+1<=n-1&&j+1<=m-1)
               {a[i][j+1]=a[i][j+1]+a[i][j]/2;
               a[i+1][j]=a[i+1][j]+a[i][j]/2;}
               else if(i+1<=n-1&&j+1>m-1)
               {

                 a[i+1][j]=a[i+1][j]+a[i][j];
               }
                else if(i+1>n-1&&j+1<=m-1)
               {

                 a[i][j+1]=a[i][j+1]+a[i][j];
               }
            }
        }
        double ans=0.0;
         loop(i,0,n)
        {
            loop(j,0,m)
            {
              ans=ans+a[i][j];
            }}
            cout<<setprecision(7)<<ans<<endl;
    }
    return 0;
}

