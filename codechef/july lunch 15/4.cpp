#include<bits/stdc++.h>
using namespace std;

//typedef long long  ll;
typedef unsigned long long  ull;

//ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

typedef long long lint;

const int MAX = 33333;
//ll mod = 1000000007;

lint D[MAX+1]; int chk[MAX+1],when;
std::map<int, lint> D2;
int N,M,L,R;

lint spow(lint a, lint p)
{
	lint r = 1;

	while (p){
		if (p & 1LL) r = (r * a) ;
		a = (a * a) ;
		p >>= 1;
	}

	return r;
}

lint go(int i)
{
	if (i <= MAX){
		if (chk[i] == when) return D[i];
		chk[i] = when;
	}
	else{
		if (D2.count(i)) return D2[i];
	}

	lint &r = (i <= MAX) ? D[i] : D2[i];
	r = spow(i,N);

	for (int j=2,n;j<=i;j=n){
		int js = i / j;
		n = i / js + 1;
		r -= go(js) * (n - j);
	}


	return r;
}

lint sum(int i)
{
	lint res = 0;
	for (int j=1,n;j<=i;j=n){
		int js = M / j;
		n = M / js + 1;
		if (n <= i) res += go(js) * (n - j);
		else res += go(js) * (i - j + 1);
	}
	return res ;
}

int main()
{
	int T;

	scanf ("%d",&T);
	while (T--){
		scanf ("%d%d",&M,&L);
		R=L;
		N=2;
		D[0] = 1; D[1] = 1;
		chk[0] = chk[1] = ++when;
		D2.clear();

		lint r = sum(R) - sum(L-1);
        r=(r-1)/2;
		printf ("%lld\n",r+1);
	}

	return 0;
}
