#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int i=n-1,sum=0;
    while(i>=0)
    {
        sum=sum+(2*(a[i]-1));
        i=i-k;
    }
    cout<<sum<<endl;
}
