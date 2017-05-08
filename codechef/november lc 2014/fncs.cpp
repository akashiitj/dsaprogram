#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MAX 100009
#define MOD 1000000007

typedef long long Int;

int N, binSize;
Int A[MAX] = {0};
Int L[MAX], R[MAX];
Int frequency[400][MAX] = {0};
Int segTree[MAX];
Int sqrtSums[400] = {0};

inline Int read(int idx) {

    Int sum = 0;
    while(idx > 0) {

        sum += segTree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

inline void update(int idx, Int val) {

    while(idx <= N) {

        segTree[idx] += val;
        idx += (idx & -idx);
    }
}

Int getSum(int l, int r) {

    Int res = 0;
    int a = l / binSize, b = r / binSize;
    if(l % binSize) a++;
    if((r + 1) % binSize) b--;
    if(a <= b) {

        FOR(i, a, b + 1)
            res += sqrtSums[i];
        FOR(i, l, binSize * a)
            res += read(R[i]) - read(L[i] - 1);
        FOR(i, (b + 1) * binSize, r + 1)
            res += read(R[i]) - read(L[i] - 1);
    }
    else {

        FOR(j, l, r + 1) {

            res += read(R[j]) - read(L[j] - 1);
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    Int Q, type;
    int bins;
    cin >> N;
    binSize = sqrt(N);
    bins = N / binSize + 1;
    FOR(i, 1, N + 1) {

        cin >> A[i];
        update(i, A[i]);
    }
    FOR(i, 1, N + 1) {

        cin >> L[i];
        cin >> R[i];
        frequency[i / binSize][L[i]]++;
        frequency[i / binSize][R[i] + 1]--;
    }
    FOR(i, 0, bins) {

        Int start = 0;
        FOR(j, 1, N + 1) {

            start += frequency[i][j];
            frequency[i][j] = start;
            sqrtSums[i] += A[j] * start;
        }
    }
    cin >> Q;
    FOR(q, 0, Q) {

        cin >> type;
        if(type == 1) {

            int x, y;
            cin >> x;
            cin >> y;
            Int delta = y - A[x];
            FOR(i, 0, bins) {

                sqrtSums[i] += frequency[i][x] * delta;
            }
            A[x] = y;
            update(x, delta);
        }
        else {

            int m, n;
            cin >> m;
            cin >> n;
            unsigned long long int ans = 0;
            ans += getSum(m, n);
            cout << ans << endl;
        }
    }
    return 0;
}

