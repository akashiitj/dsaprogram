#include<bits/stdc++.h>
using namespace std;
 
#define LL unsigned long long int
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define LINF 1000000000000000007ULL
#define MOD 1000000007
 
LL dp[203][203];
char a[300];
LL getless(int copen, int len) {
    if (copen < 0)
        return 0;
    if (len == 0)
        return copen == 0;
    LL &ret = dp[copen][len];
    if (ret == LINF + 1) {
        ret = 0;
        ret += getless(copen + 1, len - 1);
        ret += getless(copen - 1, len - 1); 
        if (ret > LINF)
            ret = LINF;
    }
    return ret;
}
int main() {
    int i, j, n, t, cs = 0;
    LL k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        n += n;
        memset(a, 0, sizeof(a));
        for (i = 0; i < 202; i++)
            for (j = 0; j < 202; j++)
                dp[i][j] = LINF + 1;
        int cplus = 0;
        for (i = 0; i < n; i++) {
            LL cless = getless(cplus + 1, n - i - 1);
            if (cless >= k) {
                a[i] = '(';
                cplus ++;
                continue;
            } else if (cplus == 0) {
                break;
            }
            a[i] = ')';
            cplus --;
            k -= cless;
        }
        printf("Case #%d: ", ++cs);
        if (i != n)
            printf("Doesn't Exist!\n");
        else
            printf("%s\n", a);
    }
    return 0;
}

