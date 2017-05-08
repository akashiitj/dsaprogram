#include <bits/stdc++.h>//its wrong
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
set< pair<ll,ll> > points;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n, x, y;
    cin>>n;
    if(n<3)
    {
        cout<<4-n<<endl;
        return 0;
    }

    loop(i, 0, n)
    {
        cin>>x>>y;
        points.insert(make_pair(x, y));
    }


    pair<ll,ll> p3, p4;
    set< pair<ll,ll> >::iterator j;
    set< pair<ll,ll> >::iterator i;
    for ( i=points.begin(); i!=points.end(); ++i)
    {
        j=i;
        if(i!=points.end())
        {
            for ( ++j; j!=points.end(); ++j)
            {  if(i->first==j->first&&j->second==j->first)continue;
                p3.first =j->first + j->second - i->second;
                p3.second = j->second + i->first - j->first;
                p4.first = p3.first + i->first -j->first;
                p4.second = p3.second + i->second - j->second;
                if(points.find(p3)!=points.end() && points.find(p4)!=points.end())
                {
                    cout<<"0"<<endl;
                    return 0;
                }
                else if(points.find(p3)!=points.end() || points.find(p4)!=points.end())
                {
                    cout<<"1"<<endl;
                    return 0;
                }
            }
        }

    }
    cout<<"2"<<endl;
    return 0;
}

