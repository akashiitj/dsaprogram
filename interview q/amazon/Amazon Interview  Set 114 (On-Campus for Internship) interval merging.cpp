#include <bits/stdc++.h>
using namespace std;
main()
{   int n,i,f,s,x;//first second
    cout<<"enter no of interval"<<endl;
    cin>>n;
    vector<pair<int ,int> > ia;//interval array
    for(i=0;i<n;i++)
    {
        cin>>f;
        cin>>s;
        ia.push_back(make_pair(f,s));
    }
    sort(ia.begin(),ia.end());
    i=0;
    while(i<n)
    {
        x=ia[i].second;
        {
            for(int j=i+1;j<n;j++)
            {
                if(ia[j].first<=x)
                    { if(ia[j].second>x)
                        x=ia[j].second;
                    if(j==n-1)
                    {
                    cout<<ia[i].first<<" "<<x<<endl;
                    goto qw;
                    }
                    }
                else
                {
                    cout<<ia[i].first<<" "<<ia[j-1].second<<endl;
                    i=j;
                    if(j==n-1)
                    {
                    cout<<ia[i].first<<" "<<ia[j].second<<endl;
                    goto qw;
                    }
                    break;
                }
            }
        }
    }
    qw:;

}
