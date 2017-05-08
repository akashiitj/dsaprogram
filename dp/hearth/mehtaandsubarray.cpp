#include <bits/stdc++.h>
using namespace std;
vector < pair<long long, int> > v;
int n;
int main()
{
    int n,len,cnt,mn;
    long long sum,x;
    sum = len = cnt = 0;
    cin >> n;
    v.push_back(make_pair(0,1));
    for ( int i = 1; i <= n; i++ )
    {
        cin >> x;
        sum += x;
        v.push_back(make_pair(sum,i+1));
    }

    sort(v.begin(),v.end());
     for ( int i = 0; i <= n; i++ )
        cout<<v[i].second<<" "<<v[i].first<<"\n";
    mn = v[0].second;
    for ( int i = 1; i <= n; i++ )
    {
        int val = max(0,v[i].second-mn);
      //  cout<<val<<" "<<len<<"\n";
        if ( val > len )
        {
            len = val;
            cnt = 1;
        }
        else if ( val == len ) cnt++;
        mn = min(mn,v[i].second);
    }
    if ( len == 0 ) cout << "-1" << endl;
    else cout << len << " " << cnt << endl;
    return 0;
}
