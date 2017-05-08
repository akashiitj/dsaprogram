#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
#define MAX 1000000007
using namespace std;
int v[5000001];


void primef(ll n)
{

    while(n%2==0)
    {
        v[n]++;
        n = n>>1;
    }

    for(int i=3; i*i<=n; i=i+2)
    {

        while(n%i==0)
        {
            v[n]++;
            n = n/i;
        }

    }
    if (n > 2 )//
       v[n]++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    loop(i,1,5000001)
    primef(i);
}

