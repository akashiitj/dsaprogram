// Aaj apac test , kal college test -_-
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int test_case;cin>>test_case;while(test_case--)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,LL>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair

#define GI(x)     scanf("%d",&x)

#define FOR(i,a,b)      for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b)     for(int i=(int)(b)-1;i>=(int)(a);i--)

#define MOD       1000000007
#define EPS       1E-10

#define PI  acos(-1)

#define CASE(x)   fout << "Case #" << x << ": ";

vector<LL> primeFactors;

void check(LL &A , LL b)
{
	LL ins = 1;
	while(A%b == 0)
	{
		A /= b;
		ins *= b;
	}
	if(ins > 1) primeFactors.pb(ins);
}

int marker[100001] = {0};
void sieve(int limit = 100000)
{
	FOR(i,2,limit+1) marker[i] = 1;
	FOR(i,2,limit+1)
	{
		if(!marker[i]) continue;
		int j = 2*i;
		while(j<=limit)
		{
			marker[j] = 0;
			j += i;
		}
	}
	marker[1] = 1;
}

LL Left[1<<20];

int DP[1<<20];

int sod(LL x)
{
	int ret = 0;
	while(x)
	{
		ret += x%10;
		x /= 10;
	}
	return ret;
}

int solve(int mask)
{
	if(mask+1 == (1<<sz(primeFactors)) or marker[sod(Left[mask])] == 1) return 0; // he loses.
	else if(DP[mask] != -1) return DP[mask];
	// he can play now.
	int ret = 1;
	for(int i = 0; i < sz(primeFactors); i++)
	{
		if(mask&(1<<i)) continue;
		ret = ret&solve(mask|(1<<i));
	}
	if(ret == 0)
		DP[mask] = 1;
	else
		DP[mask] = 0;
	return (!ret);
}

int main()
{
	ifstream fin("C.in");
	ofstream fout("out.txt");
	int t;
	fin >> t;
	sieve();
	for(int test = 1; test <= t; test++)
	{
		clr(primeFactors);
		LL n;
		fin >> n;
		LL temp = n;
		check(n , 2);
		check(n , 3);
		int lmt = sqrt(n);
		for(int i = 5; i <= lmt; i += 6)
		{
			check(n , i);
			check(n , i + 2);
			lmt = sqrt(n);
		}
		if(n > 1)
			primeFactors.pb(n);
		for(int i = 0; i < (1<<sz(primeFactors)); i++)
		{
			DP[i] = -1;
			Left[i] = 1;
			for(int j = 0; j < sz(primeFactors); j++)
			{
				if(i&(1<<j))
				{
					Left[i] *= primeFactors[j];
				}
			}
			Left[i] = temp / Left[i];
		}
		int x = solve(0);
		CASE(test);
		if(x) fout << "Laurence" << endl;
		else fout << "Seymour" << endl;
	}
    	return 0;
}