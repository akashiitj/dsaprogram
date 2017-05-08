
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int main()
{
	vector<int> primes(MAXN);
	for(int i=2;i<MAXN;++i)
		if(primes[i]==0)
			for(int j=i;j<MAXN;j+=i)
				++primes[j];
	vector<int> indices[6];
	for(int i=2;i<MAXN;++i)
		if(primes[i]<=5)
			indices[primes[i]].push_back(i);
	int t,a,b,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&k);
		vector<int>::iterator lo,hi;
		lo = lower_bound(indices[k].begin(),indices[k].end(),a);
		hi = upper_bound(indices[k].begin(),indices[k].end(),b);
		printf("%d\n",size_t(hi-lo));
	}
	return 0;
}
