
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <iterator>

#define MOD 1000000007
#define INF 1000000000000000000
#define PI acos(-1)

using namespace std;

int GCD (int a,int b)
{
    if (b == 0) return a;
    return(a % b == 0 ? b : GCD(b,a % b));
}

long long int POW (long long int base,long long int exp)
{
    long long int val;
    val = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            val = (val * base) % MOD;
        }
        base = (base * base) % MOD;
        exp = exp / 2;
    }
    return val;
}

int lesser[10] = {0,1,2,2,2,3,3,4,4,5};//lesser than n how many nonprime not including i

int main()
{
    int t,n,i,flag;
    long long int dig[20];
    long long int num,non_prime,ans;
    char s[25];
    dig[0] = 1;
    for (i = 1; i <= 18; i++)
    {
        dig[i] = dig[i - 1] * 6;
    }
    scanf("%d",&t);
    while (t --)
    {
        scanf("%s",s);
        n = strlen(s);
        num = 0;
        for (i = 0; i < n; i++)
        {
            num = num * 10 + s[i] - '0';
        }
        num++;
        non_prime = 0;
        flag = 0;
        for (i = n - 1; i >= 0; i--)
        {
            if (s[i] - '0' == 2 || s[i] - '0' == 3 || s[i] - '0' == 5 || s[i] - '0' == 7)
            {
                flag = 1;
                non_prime = dig[n - i - 1] * lesser[s[i] - '0'];
            }
            else
            {
                non_prime = non_prime + dig[n - i - 1] * lesser[s[i] - '0'];
            }
              //  cout<<i<<" "<<non_prime <<"\n";
        }
        //non_prime -= 1;//becoz 0 get counted in non prime
        if (flag == 0)
        {
            non_prime += 1;
        }
        ans = num - non_prime;
        printf("%lld\n",ans);
    }
    return 0;
}
