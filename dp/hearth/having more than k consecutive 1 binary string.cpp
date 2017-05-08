#include <stack>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <limits>
#include <bitset>
using namespace std;

//Shorthands
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
#define sd(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define For(i, j, k) for (int i = j; i <= k; i++)
#define Ford(i, j, k) for (int i = j; i >= k; i--)
#define sz(a) int((a).size())
#define rsz resize
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define abs(x) (((x) > 0) ? (x) : (-(x)))
#define mp make_pair
//Constants
#define MOD 1000000007
//#define MAX 15

ll dp[105][105];
bool exist[105][105];
int K;

//ya fr that ques...fr that ques.. its simple ... say i have guessing fr the ith bit... it can be either 0 or 1,.
// if its 1 then only if it is preceded by k-1 1 consequetively.. all the permutations are possible.. otherwise i 0 comes i have to start again
//    so again the state count of consequetive 1s required is K again
//
//state consist of two things.i and k where i is the bit currently in decision and k is the no of bits required to set consequetively
//to have K consequestive 1s.. if at some 0 comes consequetiveity breks and again i need to start fresh agin K 1s will be required..
//if its 1 then k-1 1are qrequired.

ll solve(int i, int k, int n)
{
    if (k == 0) return (1LL << (n-i));
    if (i == n) return 0;
    if (!exist[i][k]) {
        ll ways = solve(i+1, K, n) + solve(i+1, k-1, n);
        dp[i][k] = ways;
        exist[i][k] = 1;
    }
    return dp[i][k];
}



int main()
{
    int n;
    cin >> n >> K;
    ll ways = solve(0, K, n);
    ll total = 1LL << n;
    ll gcd_xy = gcd(ways, total);
    cout << ways/gcd_xy << "/" << total/gcd_xy;
}

