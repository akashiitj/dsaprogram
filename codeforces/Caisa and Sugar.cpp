#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s,x,y,min=101;
    cin>>n>>s;
    vector<pair<int ,int > > v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(y,x));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {   if(v[i].second<min&&v[i].first==0)min=v[i].second;
        if(v[i].first!=0&&v[i].second<s)
        {cout<<100-v[i].first<<endl;return 0;}
    }
    if(min<=s){cout<<"0"<<endl;
    return 0;}
    cout<<"-1"<<endl;
    return 0;

}
