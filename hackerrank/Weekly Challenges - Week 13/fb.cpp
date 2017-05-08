#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rx,ry,rz;
ll a[30];
ll b[30];
ll c[30];
ll expo(ll a, ll b)
{
    ll result = 1;

    while (b)
    {
        if (b%2==1)
        {
            result *= a;
        }
        b /= 2;
        a *= a;
    }

    return result;
}
ll prllPowerSet(ll set_size)
{

     ll pow_set_size = expo(2, set_size);
    ll counter, j;

    for(counter = 0; counter < pow_set_size; counter++)
    {
        ll  sum=0,sum1=0,sum2=0;
        for(j = 0; j < set_size; j++)
        {

            if(counter & (1<<j))
            {
                sum=sum+a[j];
                sum1=sum1+b[j];
                sum2=sum2+c[j];

            }

        }
        if(sum==rx&&sum1==ry&&sum2==rz)
        {

            return 1;
        }

    }
    return 0;
}


int main()
{
    ll t,n;
    cin>>t;
    for(ll i=1; i<=t; i++)
    {
        cin>>rx>>ry>>rz;
        cin>>n;
        for(ll j=0; j<n; j++)
            cin>>a[j]>>b[j]>>c[j];
        if(prllPowerSet(n)==1)
            cout<<"Case #"<<i<<":"<<" "<<"yes"<<endl;
        else  cout<<"Case #"<<i<<":"<<" "<<"no"<<endl;

    }
return 0;

}
