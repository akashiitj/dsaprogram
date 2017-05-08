#include<iostream>
#include<cmath>
using namespace std;
main()
{
    int n;
    cin>>n;//cout<<endl;
    int f1=0,f2=0,f3=0;
    int a[n+1],b[n+1];
    for(int i=1; i<n+1; i++)
    {
        cin>>a[i];
        f1=f1+(pow(2,n-i)*a[i]);
    }
    for(int i=1; i<n+1; i++)
    {
        cin>>b[i];
        f2=f2+(pow(2,n-i)*b[i]);
    }
    cout<<f1<<"   "<<f2<<endl;
    // for(int i=0;i<n;i++)cout<<a[i];
    // for(int i=0;i<n;i++)cout<<b[i];


    for(int i=n; i>=1; i--)
    {
        if(a[i]+b[i]==3)
        {
            a[i]=1;
            a[i-1]=a[i-1]+1;
        }
        else if(a[i]+b[i]==2)
        {
            a[i]=0;
            a[i-1]=a[i-1]+1;
        }
        else a[i]=a[i]+b[i];
    }
    for(int i=0; i<n+1; i++)
    {
        cout<<a[i];
        f3=f3+(pow(2,n-i)*a[i]);
        cout<<"  ";
    }
    cout<<endl;
    cout<<f3;
}
