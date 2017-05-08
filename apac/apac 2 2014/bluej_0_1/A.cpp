#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 1000000007
typedef long long ll;
ll fact[100];
ll inv[100];
int pow(int a,int b){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y);
            if(x>=MOD)
				x%=MOD;
        }
        y = (y*y);
        if(y>=MOD)
			y%=MOD;
        b /= 2;
    }
    return x;
}
int invmod(int a)
{
	return pow(a,MOD-2);
}
void preprocess()
{
	int i;
	fact[0]=1;
	inv[0]=1;
	for(i=1;i<=100;i++)
	{
		fact[i]=i*fact[i-1];
		if(fact[i]>=MOD)
			fact[i]%=MOD;
	}
	inv[1]=1;
	for(i=2;i<=100;i++)
	{
		inv[i]=invmod(i)*inv[i-1];
		if(inv[i]>=MOD)
			inv[i]%=MOD;
	}
}
int comb(int n,int x)
{
	if(x==0 || x==n)
		return 1;
	ll ans;
	ans=fact[n]*inv[x];
	if(ans>=MOD)
		ans%=MOD;
	ans*=inv[n-x];
	if(ans>=MOD)
		ans%=MOD;
	return ans;
}
int solve(int n,int m)
{
	int i;
	int sign=1;
	ll ans=0,val;
	
	for(i=0;i<m;i++)
	{
		val=comb(m,i);
		//cout<<val<<" ";
		val*=pow(m-i,n);
		//cout<<pow(m-i,n)<<" "<<val<<endl;
		if(val>=MOD)
			val%=MOD;
		ans+=sign*val+MOD;
		if(ans>=MOD)
			ans%=MOD;
		sign*=-1;
	}
	return ans;
}
int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	preprocess();
	int	t,n,m,i=1;
	scanf("%d",&t);
	while(i<=t)
	{
		scanf("%d%d",&m,&n);
		printf("Case #%d: %d\n",i,solve(n,m));
		i++;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
