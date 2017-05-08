#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,x,on=0;//operation needed
    cin>>n>>k;
    vector<int> sv;
    vector<pair<int ,int> > v;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(make_pair(x,i+1));
    }
    sort(v.begin(),v.end());
    while(k>0)
    {
        if(v[0].first+1==v[n-1].first||v[0].first==v[n-1].first)
        {
            cout<<v[n-1].first-v[0].first<<" "<<on<<endl;
            for(int i=0; i<sv.size(); i=i+2)
                cout<<sv[i]<<" "<<sv[i+1]<<endl;
            return 0;
        }
        v[0].first++;
        v[n-1].first--;
        on++;
        sv.push_back( v[n-1].second);
        sv.push_back( v[0].second);
        int i=0;
        pair<int ,int> p=v[0];
        while(p.first>v[i+1].first)
        {
            v[i]=v[i+1];
            i++;
        }
        v[i]=p;
        i=n-1;
        p=v[n-1];
        while(p.first<v[i-1].first)
        {
            v[i]=v[i-1];
            i--;
        }
        v[i]=p;


        k--;


    }
    cout<<v[n-1].first-v[0].first<<" "<<on<<endl;
    for(int i=0; i<sv.size(); i=i+2)
        cout<<sv[i]<<" "<<sv[i+1]<<endl;
    return 0;

    return 0;
}
