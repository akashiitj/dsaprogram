/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M)
{
    LL ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

int A[3001], B[3001], ar[3001][3001], mx[3001][3001];

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1o.out", "w", stdout);
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int T;
    cin >> T;
    FOR(ts, 1, T+1)
    {
        int n, k, c, x;
        cin >> n >> k >> c >> x;
        FOR(i, 1, n+1) cin >> A[i];
        FOR(i, 1, n+1) cin >> B[i];

        FOR(i, 1, n+1)
        {
            FOR(j, 1, n+1)
            {
                ar[i][j] = (A[i]*i + B[j]*j + c) % x;
            }
        }


        FOR(j, 1, n+1)
        {
            multiset < int > ms;
            multiset < int > ::iterator it;
            for(int i = 1; i <= k; i++) ms.insert(ar[i][j]);
            for(int i = 1; i+k-1 <= n; i++)
            {
                it = ms.end();
                it--;
                mx[i][j] = (*it);
                ms.erase(ms.find(ar[i][j]));
                if(i+k <= n) ms.insert(ar[i+k][j]);
            }
        }

        LL res = 0;
        for(int i = 1; i+k-1 <= n; i++)
        {
            multiset < int > ms;
            multiset < int > ::iterator it;
            for(int j = 1; j <= k; j++) ms.insert(mx[i][j]);
            for(int j = 1; j+k-1 <= n; j++)
            {
                it = ms.end();
                it--;
                res += (LL)(*it);
                ms.erase(ms.find(mx[i][j]));
                if(j+k <= n) ms.insert(mx[i][j+k]);
            }
        }

        cout << "Case #" << ts << ": " << res << endl;
       // cerr << "Case #" << ts << ": " << res << endl;
    }
}

