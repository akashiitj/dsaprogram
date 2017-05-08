/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
lld dp[102][102];
int solve(){
	vector<pair<pii,int> >E;
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			dp[i][j] = MOD;
		}
		dp[i][i] = 0;
	}
	int u,v;
	lld x;
	for(int i=1;i<=M;++i){
		cin>>u>>v>>x;
		u++;
		v++;
		E.push_back(mpa(mpa(u,v),x));
		dp[u][v] = min(dp[u][v],x);
		dp[v][u] = min(dp[v][u],x);
	}
	for(int k=1;k<=N;++k){
		for(int j=1;j<=N;++j){
			for(int i=1;i<=N;++i){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=0;i<E.size();++i){
		int flag = 0;
		int u=E[i].fi.fi;
		int v=E[i].fi.se;
		int d = E[i].se;
		if(!(dp[u][v]==d))cout<<i<<endl;
	}
}
int main()
{
	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);

	int T,test = 0;
	cin>>T;

	while(T--){
		test++;
		printf("Case #%d:\n",test);
		solve();
	}
}
