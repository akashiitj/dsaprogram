#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,p,x=0;
    cin>>t;
    while(t>0)
    {   cin>>n>>p;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>=p)
               x++;
        }
        cout<<x<<endl;
        t--;
    }
}
