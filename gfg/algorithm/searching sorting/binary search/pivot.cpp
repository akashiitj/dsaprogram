#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

   int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    if(a[0]<a[n-1])
    {
        cout<<"no pivot\n";
        return 0;
    }
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]>a[mid+1])
        {
            cout<<a[mid]<<"\n";
            return 0;
        }
        if(a[mid]<a[l])
        {
            r=mid-1;
        }
        else l=mid+1;
    }
}
