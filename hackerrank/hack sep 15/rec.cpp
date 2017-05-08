#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

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

double a[1001];

int main()
{
	int n;
	frmlty
	{
		le(n);
		loop(i,1,n+1)
		{
		  cin>>a[i];
		}

		sort(a+1,a+1+n);

		double ans=0;
		double x;
    	double y;
	    loop(i,1,n+1)
		{

		}
	//	cout<<ans<<"\n";
		cout<<fixed<<setprecision(9);

		cout<< ans*6.0/(1.0*n*(n-1)*(n-2))<<"\n";
	}

   return 0;
}

