#include<bits/stdc++.h>
using namespace std;

#define ll long long


#define fast      ios_base::sync_with_stdio(false);

main()
{   fast;
    int t;
    ll x,y,rx,ry,ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>x>>y;
        x=abs(x);
        y=abs(y);
        rx=min(x,y);//diagonal point
        ry=rx;
        ans=2*rx;
        x=x-rx;
        y=y-ry;
        if(x>y)
        {
            if((x%2)==1)ans=ans+(((x/2)+1)*3)+((x/2)*1);
            else ans=ans+((x/2)*4);
        }
        else if(x<y)
        {
            if(y%2==1)ans=ans+((y/2)+1)+((y/2)*3);
            else ans=ans+(y/2)*4;
        }
        cout<<ans<<endl;

    }
o}
