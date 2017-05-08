#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
#define MAX 1000000007
using namespace std;
ll pnum[1000002];

float fsqrt(float x)
{
    float xhalf=0.5f*x;
    int32_t i=*(int32_t*)&x;
    i=0x5f375a86-(i>>1);
    x=*(float*)&i;
    x=x*(1.5f-xhalf*x*x);
    return 1/x;
}
void primef(ll n)
{
    ll pnumt = 0;
    while(n%2==0)
    {
        pnumt++;
        n = n>>1;
    }
    pnum[2] = max(pnum[2], pnumt);
    for(int i=3; i<=fsqrt(n); i=i+2)
    {
        pnumt = 0;
        while(n%i==0)
        {
            pnumt++;
            n = n/i;
        }
        pnum[i] = max(pnum[i], pnumt);
    }
    if (n > 2 && 1>pnum[n])//
        pnum[n] = 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t>0)
    {
        for(ll i=0; i<1000002; i++)pnum[i] = 0;
        ll n;
        ll sum=0;
        cin>>n;
        ll a[n];
        for(ll i=0; i<n; i++)
            cin>>a[i];
        for(ll i=0; i<n; i++)
            primef(a[i]);
        loop(i, 0, 1000001)
        {
            sum=sum+pnum[i];
        }
        cout<<sum<<endl;
        t--;
    }
}
