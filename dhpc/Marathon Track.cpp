#include<bits/stdc++.h>
using namespace std;
main()
{   ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    unsigned long long n,q,i,j,sum,x;
    while(t--)
    {
        cin>>n;
        unsigned long long a[n];
        cin>>a[0];
        for(int i=1;i<n;i++)
          {
              cin>>x;
              a[i]=x+a[i-1];
          }
        cin>>q;
        while(q--)

       {  sum=0;
            cin>>i>>j;

            cout<<a[j]-a[i]<<endl;
        }

    }
}
