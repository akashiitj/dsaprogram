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
    ll count1, j;
    queue<ll > q;
    ll rs=avg-a[i];
    ll average=0;
    for(count1 = 1; count1 < pow_set_size; count1++)
    {
        average=0;
        while(!q.empty())
        {
            q.pop();
        }
        //cout<<count1<<"co"<<l<<endl;
        for(j = 0; j <l ; j++)
        {
            //  cout<<j<<" j "<<endl;

            if(count1 & (1<<j))
            {
                //  cout<<ma[i+j]<<" ma "<<endl;
                if(ma[j]==1)goto qw;
                average=average+a[j];
                // cout<<average<<" s "<<i+j<<endl;
                q.push(j);
            }
        }
        if(average==rs)
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
 main()
{   ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        ll array1[n];
        ll average=0,x;
        for(int i=0; i<n; i++)
        {
            cin>>array1[i];
            average=average+array1[i];
        }
        sort(array1,array1+n);

        if(average%k==0)
        {
            x=average/k;
            bool hashmarker;

            {
                hashmarker=false;
                int temp[i];
                copy(array1,array1+i,temp);
                int pow_set_size = pow(2, i);
                int count1, j;
                ll val,s=0;
                val=x-array1[i];
                if(s==val)
                {
                    hashmarker=true;
                    continue;
                }
                for(count1 = 0; count1 < pow_set_size; count1++)
                {
                    queue<ll> q;
                    for(j = 0; j < i; j++)
                    {
                        if(count1 & (1<<j))
                        {
                            s= s + temp[j];
                            q.push(j);
                        }
                    }
                    if(s==val)
                    {
                        s=0;
                        hashmarker=true;
                        while(!q.empty())
                        {
                            array1[q.front()]=0;
                            q.pop();
                        }
                        break;
                    }
                    else s=0;
                }
                if(!hashmarker)
                {
                    cout<<"no"<<endl;
                    break;
                }
                else continue;
            }
            if(hashmarker)cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;
    }
}

