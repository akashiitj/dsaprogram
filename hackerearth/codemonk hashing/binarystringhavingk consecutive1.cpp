#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[61][61];
int pow2 (int a)
{
	int ans=1;
	for (int g=0;g<a; g++) ans*=2; return ans;
}
int gcd (int a, int b)
{
	if (a==0) return b;
	return gcd(b%a, a);
}
main()
{
	for (int g=0; g<=60; g++) dp[g][0]=1;
	for (int g=1;g<=60; g++)
	{
		for (int y=1;y<=g; y++)
		{
			for (int z=0; z<y; z++)
			{
				dp[g][y]+=dp[g-z-1][y];
			}
			dp[g][y]+=pow2(g-y);
		}
	}
	int a,b; cin >> a >> b;
	int first=dp[a][b];
	int second=pow2(a); int r=gcd(first,second);
	if (first==0){cout << 0; return 0;}
	cout << dp[a][b]/r << '/' << pow2(a)/r;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
typedef double fl;

const int N = 65;
ll dp[N];
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
    int k, n;
    cin >> n >> k;
    dp[0] = 1;
    REP(i, 1, n + 1)
    {
        REP(j, 1, k) {
            if(i - j < 0) break;
            dp[i] += dp[i - j];
        }
    }
    ll den = (1LL << n);
    ll res = den - dp[n + 1];
    ll d = gcd(res, den);
    //cout << den << endl;
    cout << (res / d) << "/" << (den / d) << endl;
    return 0;
}
