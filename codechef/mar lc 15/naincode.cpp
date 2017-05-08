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

const int N = 100001;

string s;
int O[N],Z[N];
int P[N];//p[i] store that previous index maximum upto which all substring doesnt contain more than k 0 or 1
LL cnt[N];//toatal substring upto i that satisy the condition

int main()
{
    int t;
    S(t);
    while(t--)
    {
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        cin >> s;

        rep(i,1,n+1)
        {
            O[i] = O[i-1] + (s[i-1] == '1');
            Z[i] = Z[i-1] + (s[i-1] == '0');
        }

        int idx = 0;
        rep(i,1,n+1)
        {
            if(i > k)
            {
                while(Z[i] - Z[idx] > k || O[i] - O[idx] > k)
                    idx++;
            }
            P[i] = idx + 1;
            cnt[i] = cnt[i-1] + i - idx;
        }
        while(q--)
        {
            int l,r;
            S2(l,r);

            int x = l - 1;
            int lo = l, hi = r;
            //searching for that index x jiska P[x] l se kam hai maximal x because cnt[x] upto that x contain extra string which starts from beyond l
            while(lo <= hi)
            {
                int mi = (lo + hi) >> 1;
                if(P[mi] < l)
                {
                    x = mi;
                    lo = mi + 1;
                }
                else
                {
                    hi = mi - 1;
                }
            }
            cout<<x<<endl;
            LL ans = cnt[r] - cnt[x];
            ans += ((x - l + 1) * 1LL * (x - l + 2)) / 2;//its nc2 + n  n=x-l+1
            printf("%lld\n",ans);
        }
    }
    return 0;
}
