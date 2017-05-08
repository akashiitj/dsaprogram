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
            v.push_back(make_pair(x,i+1));
        }

        sort(v.begin(),v.end());
        for( i=1; i<V; i++)
        {
          //  printf("%d %d\n", i, i+1);
          cout<<i<<" "<<i+1<<endl;
        }



        //prims(a,graph,0,0,V);
    }
    return 0;
}
