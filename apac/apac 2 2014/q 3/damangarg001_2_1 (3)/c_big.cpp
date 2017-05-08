#include <bits/stdc++.h>
using namespace std;
#define CLR(a) memset(a, 0, sizeof(a))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define SZ(V) (int )V.size()
#define ALL(V) V.begin(), V.end()
#define RALL(V) V.rbegin(), V.rend()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define si(n) scanf("%d",&n)
#define ss(s) scanf("%s",s)
#define prin(n) printf("%d\n",n)
#define pll pair < long long int, long long int >
#define pii pair < int, int >
#define psi pair < string, int >
#define PB push_back  
#define MP make_pair
#define F first
#define S second
#define MOD 1000000007LL

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef long long LL;

bool satisfy(LL a,LL b,LL c,LL k)
{
	if(b-a == c-b && b-a == k) return true;
	return false;
}

LL dp[105][105];

int main()
{
	LL test,t,i,n,k,len,j,l;
	cin >> test;
	FORAB(t,1,test)
	{
		cin >> n >> k;
		LL a[n];
		FORN(i,n) cin >> a[i];
		memset(dp,-1,sizeof(dp));
		for(len=1;len<=n;len++)
		{
			for(i=0;i<n;i++)
			{
				j=i+len-1;
				if(j>=n) break;

				if(i==j) {
					dp[i][j]=1;
					continue;
				}
				if(i+1==j)
				{
					dp[i][j]=2;
					continue;
				}
				if(len==3)
				{
					dp[i][j]=3;
					if(satisfy(a[i],a[i+1],a[j],k)) dp[i][j]=0;
					continue;
				}
				dp[i][j]=len;
				for(l=i+1;l<j;l++)
				{
					LL left = 0;
					if(i+1<=l-1) left = dp[i+1][l-1];
					LL right =0;
					if(l+1<=j-1) right = dp[l+1][j-1];
					if( left==0 && right==0)
					{
						if(satisfy(a[i],a[l],a[j],k))
							dp[i][j]=0;
					}
				}
				for(l=i;l<j;l++){
					dp[i][j]=min(dp[i][j],dp[i][l] + dp[l+1][j]);
				}
			}
		}
		cout << "Case #" << t << ": " << dp[0][n-1] << endl;
	}
	return 0;
}