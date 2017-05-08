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
#define limit 31622778
//#define limit 31678
int prime[limit+5];
void seive()
{
	for(int i=2;i<=limit;++i){
		if(prime[i]==0){
			for(int j=2*i;j<=limit;j+=i)
				prime[j]=1;
		}
	}
}
vector<int> fact(lld x){
	int c=sqrt(x)+5;
	vector<int>ans;
	ans.clear();
	for(int i=1;i<=c;++i){
		if(prime[i]==0 and x%i==0){
			ans.ps(i);
		}
	}
	return ans;
}
bool isG(lld x){
	int sum=0;
	while(x>0){
		sum+=x%10;
		x/=10;
	}
	return (sum==1 or prime[sum]==0);
}
map<lld,bool>mp;
bool tell(lld x,vector<int>f){
	//if(mp.find(x)!=mp.end())return mp[x];
	if(isG(x)){
		return mp[x]=0;
	}
	for(int i=0;i<f.size();++i){
		if(f[i]==0)
			continue;
		lld temp = x;
		while(temp%f[i]==0){
			temp/=f[i];
		}
		int l=f[i];
		f[i]=0;
		int mv = tell(temp,f);
		f[i]=l;
		if(mv==0){
			return mp[x]=1;
		}
	}
	return mp[x]=0;
}
void solve(){
	lld x;
	cin>>x;
	if(tell(x,fact(x))){
		cout<<"Laurence\n";
	}
	else{
		cout<<"Seymour\n";
	}
}
int main()
{
	fre;
	seive();
	int T;
	cin>>T;
	int i=0;
	while(T--){
		i++;
		printf("Case #%d: ",i);
		solve();
	}
}
