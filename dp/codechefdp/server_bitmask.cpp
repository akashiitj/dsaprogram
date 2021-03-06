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
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define sz size()

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

int dp1[1<<20], dp2[1<<20];
int G[20]= {};

int isOne(int x, int i)
{
    return (x >> i) & 1;
}

int main()
{
    int n,m;
    S2(n,m);

    rep(i,0,m)
    {
        int x,y;
        S2(x,y);
        x--;
        y--;
        G[x] |= 1 << y;
        G[y] |= 1 << x;
    }

    rep(i,1,1<<n)
    {
        int x = 0;
        rep(j,0,n) if(isOne(i,j))
            x += __builtin_popcount(G[j] & (~i));
        dp1[i] = x;
    }

    rep(i,1,1<<n)
    {
        dp2[i] = 1000000;
        rep(j,0,n) if(isOne(i,j))
        {
            dp2[i] = min(dp2[i], dp2[i ^ (1<<j)] + dp1[i]);
        }
    }
    P(dp2[(1<<n)-1]);

    return 0;
}
