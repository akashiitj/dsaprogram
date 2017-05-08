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
    //v.push_back(make_pair(0,1));
    int flag=0;

    for ( int i = 1; i <= n; i++ )
    {
        cin >> x;
        if(x>=0)flag=1;
        sum += x;
        v.push_back(make_pair(sum,i));
    }
    if(flag==0)
    {
        cout << "-1" << endl;
        return 0;
    }
    sort(v.begin(),v.end());
//     for ( int i = 1; i <= n; i++ )
//        cout<<v[i-1].first<<" "<<v[i-1].second<<"\n";
    mn = v[0].second;
    for ( int i = 1; i <n; i++ )
    {
        int val = max(0,v[i].second-mn);
        if(v[i].first>=0)val = max(val,v[i].second);//subarray 1 to v[i].second is candidate
        if ( val > len )
        {
            len = val;
            cnt = 1;
        }
        else if ( val == len ) cnt++;
        mn = min(mn,v[i].second);//min index update it best for further longest array difference is obviusly going to be >= 0
    }
    cout << len << " " << cnt << endl;
    return 0;
}
