#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
// template end here
char s[SIZE];
int H[1<<26];
int main()
{
    CASET
    {
        H[0]=1;
        RS(s);
        int n=LEN(s);
        int now=0;
        LL an=0;
        REP(i,n)
        {
            now^=1<<(s[i]-'a');
            an+=(H[now]++);
            REP(j,26)
            {
                an+=H[now^(1<<j)];
            }
        }
        now=0;
        REP(i,n)
        {
            now^=1<<(s[i]-'a');
            H[now]=0;
        }
        LL q=n*(n+1LL)/2;
        LL gg=__gcd(q,an);
        printf("%lld/%lld\n",an/gg,q/gg);
    }
    return 0;
}