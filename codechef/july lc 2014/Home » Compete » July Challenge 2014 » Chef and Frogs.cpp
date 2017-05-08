#include <bits/stdc++.h>
#define floop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, k, p;
    cin>>n>>k>>p;
    ll hv, x, y;
    vector<pair<ll, ll> > loc;
    loop(i, 0, n)
    {
        cin>>hv;
        loc.push_back(make_pair(hv, i+1));
    }
    sort(loc.begin(), loc.end());
    ll reach[100002] = {0};
    reach[loc[0].second] = 1;
    ll j = 1;
    loop(i, 1, n)
    {
        if(loc[i].first-loc[i-1].first<=k)
            reach[loc[i].second] = j;
        else
        {
            j++;
            reach[loc[i].second] = j;
        }
    }
    loop(i, 0, p)
    {
        cin>>x>>y;
        if(reach[x]==reach[y]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
