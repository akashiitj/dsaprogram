#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
float fsqrt(float x)
{
    float xhalf=0.5f*x;
    int32_t i1=*(int32_t*)&x;
    i1=0x5f375a86-(i1>>1);
    x=*(float*)&i1;
    x=x*(1.5f-xhalf*x*x);
    return 1/x;
}
struct hold
{
    ll i,j;
};
ll sqrtSums[100001],len;
ll A[100001];
ll sum[100001]= {0};
ll sum1[100001];
ll getPartSum(ll r)
{
    ll it = 0;
    ll res = 0;
    while((it+1) * len -1 <= r)
        res += sqrtSums[it++];
    for(ll i = it*len; i <=r; i++)
        res += sum[i];
    return res;
}
ll getSum(ll l, ll r)
{
    if(l == 0)
        return getPartSum(r);
    else
        return getPartSum(r) - getPartSum(l-1);
}
ll incElement(ll index, ll delta)
{
//   A[index] += delta;
    sqrtSums[index/len] += delta;
}
main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll x,y,i1,i;
    hold h[n];
    sum1[0]=0;
    for( i=0; i<n; i++)
    {
        cin>>A[i];
        sum1[i+1]=sum1[i]+A[i];
    }

    len = (ll)fsqrt(n) + 1;

    for( i1 = 0; i1 < n; i1++)
    {
        cin>>x>>y;
        h[i1].i=x-1;
        h[i1].j=y-1;
        sum[i1]=sum1[y]-sum1[x-1];

    }
    for(ll i = 0; i < n; i++)
        sqrtSums[i / len] += sum[i];
    // ull sum=0;
    ll q,qt,delta;
    cin>>q;
    while(q--)
    {
        cin>>qt;
        if(qt==1)
        {
            cin>>x>>y;
            delta=y-A[x-1];
            A[x-1]=y;
            for( i1 = 0; i1 < n; i1++)
            {
                if(x-1>= h[i1].i&&x-1<=h[i1].j)
                {
                    sum[i1]=sum[i1]+delta;
                    incElement(i1,delta);
                    //cout<<sum[i1]<<" ";
                }
                //cout<<endl;
                //incElement(x-1,y-A[x-1]);
            }
        }
            if(qt==2)
            {
                //     sum=0;
                cin>>x>>y;

                cout<<getSum(x-1,y-1)<<endl;
            }
        }
    }

