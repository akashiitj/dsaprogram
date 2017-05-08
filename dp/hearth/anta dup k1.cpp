#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <bitset>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef long long ll;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs;
typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y)
{
    if(y < x) x = y;
}
template<typename T, typename U> inline void amax(T &x, U y)
{
    if(x < y) x = y;
}

template<typename T>T gcd(T x, T y)
{
    if(y==0)return x;
    else return gcd(y,x%y);
}

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    vector<vector<long long> > dp(N+1, vector<long long>(K+1, 0));
    dp[0][0] = 1;
    rep(i, N) rer(j, 0, K)
    {
        long long x = dp[i][j];
        if(x == 0) continue;
        if(j == K)
        {
            dp[i+1][K] += x * 2;
        }
        else
        {
            dp[i+1][j+1] += x;
            dp[i+1][0] += x;
        }
        rep(i1, N)
        {
            rer(j1, 0, K)
            cout<<dp[i1][j1]<<" ";
            cout<<"\n";
        }
        cout<<"\n\n";
    }
    long long num = dp[N][K], den = 1LL << N;
    long long g = gcd(num, den);
    cout << num / g << "/" << den / g << endl;
    return 0;
}

