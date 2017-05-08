#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;



#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int main()
{
   int T;
	le(T);
	for (int t = 0; t < T; ++t) {
		int x, y;
		le2(x,y);
		if (x > 0 && x % 2 == 1 && y >= -x + 1 && y <= x + 1)		//right vertical lines
			printf("YES\n");
		else if (x < 0 && x % 2 == 0 && y >= x && y <= -x)			//left vertical lines
			printf("YES\n");
		else if (y > 0 && y % 2 == 0 && x >= -y && x < y)			//upper gorizontal lines
			printf("YES\n");
		else if (y <= 0 && y % 2 == 0 && x >= y && x <= -y + 1)		//down gorizontal lines
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

