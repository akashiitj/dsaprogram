
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t,i,V,x,y;
    cin>>t;
    while(t--)
    {
        cin>>V;

        vector<pair<int, int> > v;
        // ver ve[V];
        for( i=0; i<V; i++)
        {
            cin>>x>>y;
            v.push_back(make_pair(y,i+1));
        }

        sort(v.begin(),v.end());
        for( i=0; i<V-1; i++)
          {
             cout<<v[i].second<<" "<<v[i+1].second<<endl;
          }



        //prims(a,graph,0,0,V);
    }
    return 0;
}
