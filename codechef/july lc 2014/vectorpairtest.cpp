#include <bits/stdc++.h>
#define floop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, hv;
    cin>>n;
    vector<pair<ll, ll> > loc;
    floop(i, 0, n)
    {
        cin>>hv;
        loc.push_back(make_pair(hv, i+1));
    }

     sort(loc.begin(), loc.end());
      floop(i, 0, n)
    cout<<loc[i].first<<" "<<loc[i].second<<endl;

    return 0;
}
