#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void sortd(ll number[],ll n)
{
    ll i,j,a;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (number[i] < number[j])
            {
                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
}
ll prllPowerSet(ll a[],ll ml,ll i ,ll avg,ll &rc,ll ma[])
{

    ll l=i;
    ll pow_set_size = pow(2,l);
    ll counter, j;
    queue<ll > q;
    ll rs=avg-a[i];
    ll sum=0;
    for(counter = 1; counter < pow_set_size; counter++)
    {
        sum=0;
        while(!q.empty())
        {
            q.pop();
        }
        //cout<<counter<<"co"<<l<<endl;
        for(j = 0; j <l ; j++)
        {
            //  cout<<j<<" j "<<endl;

            if(counter & (1<<j))
            {
                //  cout<<ma[i+j]<<" ma "<<endl;
                if(ma[j]==1)goto qw;
                sum=sum+a[j];
                // cout<<sum<<" s "<<i+j<<endl;
                q.push(j);
            }
        }
        if(sum==rs)
        {
            rc++;
            while(!q.empty())
            {
                ma[q.front()]=1;
                q.pop();
            }
            return 1;
        }
qw:;
    }
    return 0;
}


int main()
{
    ll t;
    cin>>t;
    while(t--)

    {
        ll n,k,avg=0;
        ll hv1=0,hv2=0;
        cin>>n>>k;
        ll a[n],ma[n];
        for(ll i=0; i<n; i++)
        {
            cin>>a[i];

            ma[i]=0;
            avg=avg+a[i];
        }
        if(avg%k!=0)
        {
            cout<<"no"<<endl;
            continue;
        }
        avg=avg/k;


        if(hv1!=1)
        {
            sort(a,a+n);
            //  for(ll i=0; i<n; i++)cout<<a[i]<<" ";
            //cout<<endl;
            ll rc=0;
            for(ll i=n-1; i>1; i--)
            {
                //for(ll h=0; h<n; h++)cout<<ma[h]<<" ";cout<<"b"<<endl;
                if(ma[i]==0)
                {
                    if(a[i]==avg)
                    {
                        ma[i]=1;
                        rc++;
                    }
                    else
                    {

                        ll dv=prllPowerSet( a, n, i , avg, rc, ma);
                        if (dv==0)
                        {
                            //  cout<<"if "<<i<<endl;
                            cout<<"no"<<endl;
                            hv2=1;
                            break;
                        }
                    }
                }
                //for(ll h=0; h<n; h++)cout<<ma[h]<<" ";cout<<endl;
            }
            //cout<<rc<<endl;
            if(hv2!=1)
            {
                if(a[n-1]==avg&&ma[n-1]==0)rc++;
                if(rc==k)
                    cout<<"yes"<<endl;
                else cout<<"no"<<endl;
            }
        }
    }

    return 0;
}
