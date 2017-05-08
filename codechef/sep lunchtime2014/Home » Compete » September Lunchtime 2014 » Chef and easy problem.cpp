#include<bits/stdc++.h>
using namespace std;
int main()
{    ios_base::sync_with_stdio(false);
    int  n,t,i,sum=0;
    cin>>t;
    while(t>0)
    {   sum=0;
       int n;
        cin>>n;
        unsigned long long a[n];
        for( i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);

       // i=0;
      i=n-1;
        while(i>=0)
        {  // cout<<"k";
            sum=sum+a[i];
            i=i-2;
        }
        cout<<sum<<endl;
t--;
    }
return 0;
}
