#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;

int main()
{   std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int n,x,y,c;
    vector<pair<int,int> > v;
    while(t--)
    {   c=1;
        cin>>n;
        loop(i,0,n)
        {
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end());
        x=v[0].first;
        y=v[0].second;
        loop(i,1,n)
        {
            if(v[i].first>y)
            {
                c++;
                x=v[i].first;
                y=v[i].second;
            }
            else{
                x=v[i].first;
                if(v[i].second<y)
                    y=v[i].second;
            }

        }
        cout<<c<<endl;
        v.clear();

    }
    return 0;
}

