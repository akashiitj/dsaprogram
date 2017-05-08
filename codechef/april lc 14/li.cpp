#include<iostream>
#include<cstdio>
#include<cstring>

typedef long long ll;

#define FOR(i,n) for(ll i=0;i<n;i++)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;


inline ll read(ll &x){
	x=0;int sign,ch;
	while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF) ch=getchar();
	if (ch=='-')
		sign=-1,ch=getchar();
	else sign=1;
	do
		x=(x<<3)+(x<<1)+ch-'0';
	while((ch=getchar())>='0' && ch<='9');
	x*=sign;
	return 1;
}


int main()
{
int n1;
cin>>n1;
ll a[n1];
ll hash[1000];
FILL(hash,0);
FOR(i,n1) {read(a[i]); hash[a[i]]++;}
FOR(i,n1-1)
{
    read(a[i]);
    hash[a[i]]--;
}
FOR(i,n1)
{
    if(hash[a[i]]==1) { cout<<a[i];break;}
    else hash[a[i]]++;
}
FOR(i,n1-2)
{
    read(a[i]);
    hash[a[i]]--;
}
FOR(i,n1-1)
{
    if(hash[a[i]]==1) cout<<a[i];break;
}
}
