#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x1,x2,fd;
    cin>>n;

    vector<pair<int ,int> > v;
    for(int i=0; i<n; i++)
    {
        cin>>x1>>x2;
        v.push_back(make_pair(x1,x2));
    }
    sort(v.begin(),v.end());
    fd=v[0].second;
    for(int i=1;i<=n-1;i++)
    {
        if(v[i].second>=fd)
            fd=v[i].second;
        else fd=v[i].first;
    }
    cout<<fd<<endl;

}
