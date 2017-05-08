#include<bits/stdc++.h>
using namespace std;



int main()
{    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int n;

    while(t--)
    {   vector<pair<int,int> > v;
        cin>>n;
        while(n--)
        {
            int x,y;
            cin>>x>>y;
            v.push_back(make_pair(x,0));
            v.push_back(make_pair(y,1));

        }
        sort(v.begin(),v.end());
         for(int i=0;i<v.size();i++)
            cout<<v[i].first<<" "<<v[i].second<<endl;
        int ans=0;
        int ans1=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].second==0)ans++;
            else ans--;
            ans1=max(ans,ans1);
        }
        cout<<ans1<<endl;
    }
}
