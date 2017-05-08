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
#include <complex>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
#define PI acos(-1)

typedef long long int LL;
const int mod = 1000000009;
const int MAXN = 100005;
int A[MAXN];
int C[2][101];
int cnt[111];


LL _pow(LL a, LL b)
{
    if(!b) return 1;
    if(b == 1) return a;
    if(b == 2) return (a*a) % mod;
    if(b&1) return (a * _pow(a, b-1)) % mod;
    return _pow(_pow(a,b/2),2);
}

LL fact[MAXN], iFact[MAXN];
void pre()
{
    fact[0] = 1;
    rep(i,1,MAXN) fact[i] = (fact[i-1] * i) % mod;

    iFact[MAXN-1] = _pow(fact[MAXN-1], mod-2);
    for(int i = MAXN-2;  i >= 0; i--)
    {
        iFact[i] = (iFact[i+1] * (i+1)) % mod;
    }
}

LL nCr(int n, int r)
{
    return (((fact[n] * iFact[r]) % mod) * iFact[n-r]) % mod;
}

int main()
{
    int t;
    pre();
    S(t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        rep(i,0,n)
        scanf("%d",&A[i]);

        while(q--)
        {
            int m;
            S(m);
            rep(i,0,m) cnt[i] = 0;

            rep(i,0,n)
            {
                int x = A[i]%m;
                if(x < 0) x += m;
                cnt[x]++;
            }

            rep(i,0,m)
            cout<<cnt[i]<<" ";
            cout<<endl;

            vector<LL > prev, res(m,0);
            rep(i,0,m) if(cnt[i])
            {
                int sum = 0;
                vector<LL > tmp(m,0);
                tmp[0] = 1;
                LL ways = 1;
                rep(j,1,cnt[i]+1)
                {
                    sum += i;
                    if(sum >= m) sum -= m;
                    ways = nCr(cnt[i], j);
                    tmp[sum] += ways;

                    if(tmp[sum] >= mod) tmp[sum] -= mod;
                }
                if(!prev.size())
                {
                    prev = tmp;
                    swap(res, tmp);
                }
                else
                {
                    rep(j,0,m) res[j] = 0;
                    rep(j,0,m) rep(k,0,m)
                    {
                        int x = k+j;
                        if(x >= m) x -= m;
                        res[x] += prev[j] * tmp[k];
                        res[x] %= mod;
                    }
                    rep(j,0,m)
                    cout<<res[j]<<" ";
                    cout<<endl;

                    prev = res;
                }
            }
            printf("%lld\n",res[0]);
        }
    }
    return 0;
}
