#include<bits/stdc++.h>
using namespace std;
int a[100001]={0};
main()
{    ios_base::sync_with_stdio(false);
    int t,n,i;
    unsigned long long sum=0;
    cin>>t;
    while(t--)
    {
     cin>>n;
     for(i=0;i<n;i++)
        cin>>a[i];
     sort(a,a+n);
     sum=1;
      for(i=0;i<n-1;i++)
        {   if(a[i+1]-a[i]!=0)
            sum++;
        }
    cout<<sum<<endl;
    }
}
