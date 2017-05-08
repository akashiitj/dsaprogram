#include<bits/stdc++.h>
using namespace std;
int main()
{
	// freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		long long int a,b,ans=0;
		cin>>a>>b;
		for(int i=0;i<32;i++)
		{
			if((a & (1ll<<i)) && (b & (1ll<<i)) && (b-a)<(1ll<<i))
				ans^=(1ll<<i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
