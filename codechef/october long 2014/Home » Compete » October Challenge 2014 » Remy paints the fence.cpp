#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,m,i,p,ans;
    char c;
    vector<pair<int,char> > v;
    cin>>t;
    while(t>0)
    {   ans=1;
        cin>>n;
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>c;
            cin>>p;
            v.push_back(make_pair(p,c));
        }
        sort(v.begin(),v.end());

        for(i=0;i<v.size()-1;i++)
        {
            if(v[i+1].second!=v[i].second)
            {
                ans=ans*(v[i+1].first-v[i].first);
                ans =ans% 1000000009;
            }
        }
        cout<<ans<<endl;
        v.clear();
        t--;

    }
}


