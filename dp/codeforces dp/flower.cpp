#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)

typedef long long int LL;
const int mod = 1000000007;
const int N = 100001;
LL dp[N];

int main()
{
    int t,k;
    scanf("%d%d",&t,&k);

    dp[0] = 1;
    rep(i,1,N)
    {
        dp[i] = dp[i-1];
        if(i >= k) dp[i] += dp[i-k];
        dp[i] %= mod;
    }

    rep(i,1,N+1)
    {
        dp[i] += dp[i-1];
    }

    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        cout << (dp[b] - dp[a-1]) % mod << endl;
    }

    return 0;
}
