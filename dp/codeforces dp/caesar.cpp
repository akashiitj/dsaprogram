#include <iostream>
#include <cstdio>
using namespace std;

#define MOD 100000000

int K1, K2;

bool exist[105][105][15][15];
long long dp[105][105][15][15];

//idea is similar state can be currently wht ist the position in decision, wht no of I soldiers are required consequetively to have k1 consequetive
//soldiers and wht soldires of type 2 are are requiered to hve k2 soldiers of type 2... transition can be like if i choose to have
//1st soldier i can do so only if no of consequetive I type soldiers is k1-1
//
//sorry < k1-1, similarly i i place II type it can be done only if < k2-1
//
//at last just return 1
//
//base case
//
//you also need to keep track ho many Ist type and second type soldiers are remaining

long long solve(int n1, int n2, int k1, int k2)
{
    if (n1 == 0 && n2 == 0)
    {
        return 1;
    }
    if (!exist[n1][n2][k1][k2])
    {
        long long answer = 0;
        if (k1+1 <= K1 && n1 >= 1)
        {
            answer += solve(n1-1, n2, k1+1, 0);
            answer %= MOD;
        }
        if (k2+1 <= K2 && n2 >= 1)
        {
            answer += solve(n1, n2-1, 0, k2+1);
            answer %= MOD;
        }
        dp[n1][n2][k1][k2] = answer;
        exist[n1][n2][k1][k2] = true;
    }
    return dp[n1][n2][k1][k2];
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2 >> K1 >> K2;
    long long answer = solve(n1, n2, 0, 0);
    cout << answer << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define infinity (1000000007)
#define ll long long
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define pip pair<int,pii>
#define pb push_back
ll pwr(ll a,ll b,ll mod)
{
  if(b==0)
    return 1;
  ll temp=pwr(a,b/2,mod);
  temp=(temp*temp)%mod;
  if(b&1)
    temp=(temp*a)%mod;
  return temp;
}
ll pwr(ll a,ll b)
{
  if(b==0)
    return 1;
  ll temp=pwr(a,b/2);
  temp=(temp*temp);
  if(b&1)
    temp=(temp*a);
  return temp;
}
ll gcd(ll a,ll b)
{
  return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
  return (a/gcd(a,b))*b;
}
ll modularInverse(ll a,ll m)
{
      /*reminder: make sure m is prime*/
      assert(false);
      return pwr(a,m-2,m);
}
const int mod=1000000007;
  int k;
  ll DP[432][666];
ll dp(int n,int onesToRight)
{
  if(n==0)
    return 1;
  if(DP[n][onesToRight]!=-1)
    return DP[n][onesToRight];
  ll o1=0;
  if(onesToRight+1<k)
    o1=dp(n-1,onesToRight+1);
  ll o2=dp(n-1,0);
  return DP[n][onesToRight]=o1+o2;

}
int main()
{
  memset(DP,-1,sizeof DP);
  std::ios::sync_with_stdio(false);
  int n;
  cin>>n>>k;
  ll total=pwr(2,n);
  ll valid=total-dp(n,0);
  ll g=gcd(total,valid);
  valid/=g;
  total/=g;
  cout<<valid<<"/"<<total;
}


#include <bits/stdc++.h>
using namespace std;
#define infinity (1000000007)
#define ll long long
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define pip pair<int,pii>
#define pb push_back
ll pwr(ll a,ll b,ll mod)
{
  if(b==0)
    return 1;
  ll temp=pwr(a,b/2,mod);
  temp=(temp*temp)%mod;
  if(b&1)
    temp=(temp*a)%mod;
  return temp;
}
ll pwr(ll a,ll b)
{
  if(b==0)
    return 1;
  ll temp=pwr(a,b/2);
  temp=(temp*temp);
  if(b&1)
    temp=(temp*a);
  return temp;
}
ll gcd(ll a,ll b)
{
  return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
  return (a/gcd(a,b))*b;
}
ll modularInverse(ll a,ll m)
{
      /*reminder: make sure m is prime*/
      assert(false);
      return pwr(a,m-2,m);
}
const int mod=1000000007;
  int k;
  int N;
  ll DP[432][666];
ll dp(int n,int onesToleft)
{
  if(n==N)
    return 1;
  if(DP[n][onesToleft]!=-1)
    return DP[n][onesToleft];
  ll o1=0;
  if(onesToleft+1<k)
    o1=dp(n+1,onesToleft+1);
  ll o2=dp(n+1,0);
  return DP[n][onesToleft]=o1+o2;

}
int main()
{
  memset(DP,-1,sizeof DP);
  std::ios::sync_with_stdio(false);
  int n;
  cin>>n>>k;
  N=n;
  ll total=pwr(2,n);
  ll valid=total-dp(0,0);
  ll g=gcd(total,valid);
  valid/=g;
  total/=g;
  cout<<valid<<"/"<<total;
}
