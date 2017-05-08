#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long LL;

#define N 1000100

char s[N];
int num[256];
int n;
int m[4], L[N][4];
LL f[4][4], F[N][4][4];

void init()
{
    n = strlen(s);
    num['c'] = 0;
    num['h'] = 1;
    num['e'] = 2;
    num['f'] = 3;
    for(int i = 0; i < n; i ++)
    {
        int j = num[s[i]];
        m[j] ++;
        for(int k = 0; k < 4; k ++) L[i][k] = m[k];
        for(int k = 0; k < 4; k ++) if(k != j) f[j][k] += m[k];
        for(j = 0; j < 4; j ++) for(int k = 0; k < 4; k ++) if(j != k)
                    F[i][j][k] = f[j][k];
    }
}

char st[10], en[10];

int main()
{
    ///freopen("in.txt","r",stdin);
    gets(s);
    init();
    int T;
    scanf("%d", &T);
    int  l, r, x, y;
    LL ans;
    while(T --)
    {
        scanf("%s %s %d %d\n", st, en, &l, &r);
        x = num[st[0]], y = num[en[0]];
        ans = F[r-1][y][x];
        if(l > 1)
        {
            ans -= F[l-2][y][x];
            ans -= 1LL * (L[r-1][y] - L[l-2][y]) * L[l-2][x];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
