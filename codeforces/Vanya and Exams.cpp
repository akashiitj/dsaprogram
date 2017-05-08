#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,r,ra,a,b,av=0,i;
     long long sum=0;
    cin>>n>>r>>ra;
    vector<pair<long long, long long> > v;
    for( i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(b,a));
        av=av+a;
    }
    sort(v.begin(),v.end());
    ra=ra*n;
    i=0;
    long long x=ra-av,y,z;
    while(x>0)
    { y=r-v[i].second;
        if(y>0)
        {   z=y-x;
            if(z>=0)
            {
                cout<<sum+x*v[i].first<<endl;
                return 0;
            }
            else{
                sum=sum+y*v[i].first;
                x=x-y;
                i++;
            }

        }
        else i++;
    }
    cout<<sum<<endl;
     return 0;
}
