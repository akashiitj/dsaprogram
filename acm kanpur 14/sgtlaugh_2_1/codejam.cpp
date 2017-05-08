#include <bits/stdtr1c++.h>

#define SQR 5623
#define LEN 1951975
#define MAX 31622997

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define write() freopen("output.txt", "w", stdout)
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define isprime(x) (( ((x) > 0) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2) || ((x) == 1))

using namespace std;

int p, prime[LEN];
unsigned int ar[(MAX >> 6) + 5] = {0};

void Sieve(){
    int i, j, k;
    setbit(ar, 0), setbit(ar, 1);

    for (i = 3; i < SQR; i++, i++){
        if (!chkbit(ar, i)){
            k = i << 1;
            for (j = (i * i); j < MAX; j += k) setbit(ar, j);
        }
    }

    p = 0;
    prime[p++] = 2;
    for (i = 3; i < MAX; i++, i++){
        if (isprime(i)) prime[p++] = i;
    }
}

int len;
long long P[100], C[100], mul[100];
tr1::unordered_set <long long> visited;
tr1::unordered_map <long long, bool> dp;

bool gNumber(long long n){
    int s = 0;
    while (n){
        s += (n % 10);
        n /= 10;
    }

    return isprime(s);
}

bool F(long long n){
    if (gNumber(n)) return false;
    if (visited.count(n)) return dp[n];

    bool res = false;
    for (int i = 0; i < len; i++){
        if (!(n % mul[i]) && !F(n / mul[i])){
            res = true;
            break;
        }
    }

    visited.insert(n);
    return (dp[n] = res);
}

void factorize(long long n){
    len = 0;
    int i, j, k;

    for (i = 0; i < p; i++){
        long long x = prime[i], y = 1;
        if ((x * x) > n) break;

        k = 0;
        while (!(n % x)){
            k++;
            n /= x, y *= x;
        }
        if (k){
            P[len] = x, C[len] = k, mul[len] = y;
            len++;
        }
    }

    if (n > 1){
        P[len] = n, C[len] = 1, mul[len] = n;
        len++;
    }
}

int main(){
    read();
    write();

    Sieve();
    int T = 0, t, i, j, k;
    long long n, x, y, z, res;

    scanf("%d", &t);
    while (t--){
        scanf("%lld", &n);
        factorize(n);

        visited.clear();
        if (F(n)) printf("Case #%d: Laurence\n", ++T);
        else printf("Case #%d: Seymour\n", ++T);
    }
    return 0;
}
