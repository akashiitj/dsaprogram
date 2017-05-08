#include<bits/stdc++.h>
using namespace std;
main()
{   std::ios_base::sync_with_stdio(false);
    string s,ts;
    cin>>s;
    int t,m,l,x=s.length(),c,i,j,w;
    cin>>t;

    while(t>0)
    {   cin>>m>>l;
    c=0;
        for(i=0;i<x;i++)
        {  w=0;
            for( j=i;j<x;j++)
            {   w=w*10+int(s[j])-48;


                if((w%m)==l)c++;
            }

        }
        cout<<c<<endl;
        t--;
    }
}
