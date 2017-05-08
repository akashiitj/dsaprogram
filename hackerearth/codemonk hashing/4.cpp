#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read()
{
    int x;
    scanf("%d",&x);
    return x;
}
int readln()
{
    int x;
    scanf("%d\n",&x);
    return x;
}


const int MAX_N = 1e5 + 5;
const ll BASE = 1e4 + 7;
ll mod=1e9 +9;


char s[MAX_N];
ll h[MAX_N], g[MAX_N], p[MAX_N];


inline ll getH(int i, int j)
{
    if (i > j) return 0;
    return (h[j] - (h[i-1] * p[j-i+1])%mod + mod)%mod;
}

int main()
{

    // init
    scanf("%s", s);
    int n = strlen(s);
    p[0] = 1;
    for (int i = 1; i < MAX_N; ++i)
        p[i] = (p[i-1] * BASE)%mod;
    h[0] = 0;
    for (int i = 1; i <= n; ++i)
        h[i] = ((h[i-1]*BASE)%mod + ll(s[i-1]))%mod;


    // solve
    int nQ = read();
    while (nQ--)
    {
        int i, j, k, l;
        scanf("%d%d%d%d", &i, &j, &k, &l);
        if (getH(i,j)==getH(k,l)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
