#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define sz(a) int((a).size())
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;

const double eps=1E-9;
const double Exp=2.718281828459045;
const double Pi=3.1415926535897932;

const int NMAX=5000 + 5;
const int MMAX=100000 + 5;
const int INF=1000000000;
const int BASE=1000000007;



int main()
{


    int n,m,k;
    int i,j;
    static ll dp[NMAX][NMAX]= {0};
    ll sum[NMAX];
    int a[NMAX];
    cin >> n >> m >> k;
    for (i=1; i<=n; i++) cin >> a[i];
    sum[0]=0;
    for (i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=k; j++)
        {
            dp[i][j]=dp[i-1][j];
            if (i<=m)
                dp[i][j]=max(dp[i][j],sum[i]);
            else dp[i][j]=max(dp[i][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";

    }
    cout << dp[n][k] << endl;
    return 0;
}
