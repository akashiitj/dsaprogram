#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l;
    cin>>n>>l;
    double a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    double d;
    if(n==1)
    {
        cout<<fixed<<setprecision(16)<< max(a[0]-0,l-a[0])<<endl;
        return 0;
    }
    if(a[0]==0.0)
        d=(a[1]-a[0])/2;
    else d=a[0];
    int i=1;
    while(i++<=n-1)
    {
        if(d<(a[i]-a[i-1])/2)
            d=(a[i]-a[i-1])/2;
    }
    if(a[n-1]!=l)
    {
        if(l-a[n-1]>d)
            d=l-a[n-1];
    }
    cout<<fixed<<setprecision(16)<<d<<endl;
    return 0;
}
