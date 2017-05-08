#include <bits/stdc++.h>

using namespace std;

int cnt[101];
bool memo[5051];
int ZSet = 2525;
bool ans;
void input()
{
	ans = 0;
	for(int i = 0;i <= 100;i++)
		cnt[i] = 0;
	int n,num;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&num);
		cnt[num]++;
	}
}


void memoize()
{
	for(int i = 0;i <= 5050;i++)
			memo[i] = 0;
	for(int i = 1;i <= 100;i++)
	{
		if(cnt[i] > 1)
			ans = 1;
	}

	if(ans == 1)
	{
		printf("YES\n");
		return;
	}

	int i;
	for(i = 1;i <= 100;i++)
		if(cnt[i] == 1)
			break;
	memo[ZSet + i] = 1;
	int mx = ZSet + i;
	int mn = ZSet + i;
	for(i = i + 1;i <= 100;i++)
	{
		if(cnt[i] == 1)
		{
			for(int j = mn;j <= mx;j++)
			{
				if(memo[j] == 1)
				{
					if(j + i <= 5050)
					{
						memo[j + i] = 1;
						mx = max(mx,j + i);
					}
					if(j - i >= 0)
					{
						memo[j - i] = 1;
						mn = min(mn,j - i);
					}
					if(memo[ZSet] == 1)
					{
						ans = 1;
						break;
					}
				}
			}
			memo[i + ZSet] = 1;
			mx = max(mx,i + ZSet);
			if(memo[ZSet] == 1)
				ans = 1;
		}
		if(ans == 1)
			break;
	}


	if(ans == 1)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		input();
		memoize();
	}
}
