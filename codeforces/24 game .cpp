#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 4) printf("NO\n");
	else if (n == 4) printf("YES\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
	else if (n == 5) printf("YES\n1 * 2 = 2\n3 + 4 = 7\n5 + 7 = 12\n12 * 2 =24\n");
	else
	{
		printf("YES\n1 + 5 = 6\n6 - 6 = 0\n2 * 3 = 6\n 4 * 6 = 24\n");
		for (int i=7; i<=n; i++) printf("%d * 0 = 0\n", i);
		printf("0 + 24 = 24\n");
	}
	return 0;
}
