#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define PI  3.1415926535897932385
#define EPS 1e-7
#define MOD 1000000007
#define INF 1500111222
#define MAX 100111
int64 N, K;
int64 f[22][2][10][4];
int digits[22], nDigits;
bool isKwavy(int64 n)
{
    if (n <= 10) return true;
    int prevD = -1, dir = -1;
    while (n > 0)
    {
        int d = n % 10;
        if (prevD == d) return false;
        if (prevD < 0);
        else if (dir < 0)
        {
            dir = prevD < d;
        }
        else
        {
            int nextDir = prevD < d;
            if (dir == nextDir) return false;
            dir = nextDir;
        }
        prevD = d;
        n /= 10;
    }
    return true;
}
int64 getBruteForce(int64 n)
{
    int64 res = 0;
    fr(i, 1, n) if (isKwavy(i))
        res++;
    return res;
}
int64 get(int i, bool less, int d, int dir)
{
    int64 &res = f[i][less][d][dir];
    if (res >= 0) return res;
    res = 0;
    if (i == 0)
    {
        res = (dir == 0 && d == 0) ? 0 : 1;
        return res;
    }
    rep(nd, 10)
    {
        if (!less && nd > digits[i - 1])
            break;
        bool nless = less || (nd < digits[i - 1]);
        int ndir = d < nd ? 2 : 3;
        if (dir == 0)
        {
            res += get(i - 1, nless, nd, nd == 0 ? 0 : 1);
        }
        else if (d != nd && (dir == 1 || dir + ndir == 5))
        {
            res += get(i - 1, nless, nd, ndir);
        }
    }
    return res;
}
int64 get(int64 n)
{
    fill(f, -1);
    fill(digits, 0);
    nDigits = 0;
    while (n > 0)
    {
        digits[nDigits++] = n % 10;
        n /= 10;
    }
    return get(nDigits + 1, false, 0, 0);
}
int64 solveLeft()
{
    int64 total = get(N);
    int64 lo = 1, hi = N, res = -1;
    while (lo <= hi)
    {
        int64 mid = (lo + hi) / 2;
        int64 midVal = get(mid - 1);
        if (total - midVal <= K)
        {
            if (total - midVal == K) res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return res;
}
int64 solveRight()
{
    int64 total = get(N - 1);
    int64 lo = N, hi = 1e18, res = -1;
    while (lo <= hi)
    {
        int64 mid = (lo + hi) / 2;
        int64 midVal = get(mid);
        if (midVal - total <= K)
        {
            if (midVal - total == K) res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return res;
}
void solve()
{
    printf("%lld %lld\n", solveLeft(), solveRight());
}
void solveBruteForce()
{
    int64 lo = -1, hi = -1;
    for (int64 i = N, counter = 0; i >= 1; i--)
    {
        if (isKwavy(i)) counter++;
        if (counter == K) lo = i;
        if (counter > K) break;
    }
    for (int64 i = N, counter = 0; i <= 1e18; i++)
    {
        if (isKwavy(i)) counter++;
        if (counter == K) hi = i;
        if (counter > K) break;
    }
    cout << lo << " " << hi << endl;
}
int main()
{
    int cases;
    scanf("%d", &cases);
    assert(1 <= cases && cases <= 625);
    while (cases--)
    {
        scanf("%lld %lld", &N, &K);
        assert(1 <= N && N <= 1e18);
        assert(1 <= K && K <= 1e18);
        solve();
        //solveBruteForce();
    }
    return 0;
}
