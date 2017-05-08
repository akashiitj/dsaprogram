#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(ll i = a; i < b; i++)


int main()
{
    std::ios_base::sync_with_stdio(false);
    ll t;

    cin>>t;
    vector<ll> v;
    //ll q,x,y,n;
    while(t--)
    {
        ll q;
        cin>>q;
        if(q==0)
        {
            ll x;
            cin>>x;
            v.push_back(x);
        }
        else if(q==1)
        {
            ll x,y,n,max1,no;
            cin>>x>>y>>n;
            max1=v[x-1]^n;
            no=v[x-1];
            loop(i,x,y)
            {
            if((v[i]^n)>max1)
            {
                max1=(v[i]^n);
                no=v[i];
            }
            }
            cout<<no<<endl;
        }
        else if(q==2)
        {
            ll y;
            cin>>y;
            v.erase(v.begin()+v.size()-y,v.begin()+v.size());
            //  loop(i,0,v.size())
            //cout<<v[i]<<endl;
        }
        else if(q==3)
        {

            ll c=0,x,y,n;
            cin>>x>>y>>n;
            loop(i,x-1,y)
            {
            if(v[i]<=n)c++;
            }
            cout<<c<<endl;
        }
        else if(q==4)
        {
            long long int o=0,x,y,n,l,h;
            cin>>x>>y>>n;
            ll a[y-x+1];
             l=y-x+1;
            loop(i,x-1,y)
            {
                a[o]=v[i];
                o++;
            }
            sort(a,a+l);
            ll mini=a[0];
            ll e=1;
            loop(i,0,l)
            {
               if(a[i]>mini)
                    e++;
               if(e==n)
               {
                   h=i;
                   break;
               }
            }
            cout<<a[h]<<endl;
        }
    }

    return 0;
}


